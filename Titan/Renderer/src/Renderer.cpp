#include "Renderer.h"

namespace Titan
{
	struct PosColorVertex
	{
		float x;
		float y;
		float z;
		uint32_t abgr;
	};

	static PosColorVertex cubeVertices[] =
	{
		{-1.0f,  1.0f,  1.0f, 0xff000000 },
		{ 1.0f,  1.0f,  1.0f, 0xff0000ff },
		{-1.0f, -1.0f,  1.0f, 0xff00ff00 },
		{ 1.0f, -1.0f,  1.0f, 0xff00ffff },
		{-1.0f,  1.0f, -1.0f, 0xffff0000 },
		{ 1.0f,  1.0f, -1.0f, 0xffff00ff },
		{-1.0f, -1.0f, -1.0f, 0xffffff00 },
		{ 1.0f, -1.0f, -1.0f, 0xffffffff },
	};

	static const uint16_t cubeTriList[] =
	{
		0, 1, 2,
		1, 3, 2,
		4, 6, 5,
		5, 6, 7,
		0, 2, 4,
		4, 2, 6,
		1, 5, 3,
		5, 7, 3,
		0, 4, 1,
		4, 5, 1,
		2, 3, 6,
		6, 3, 7,
	};

	bgfx::ShaderHandle loadShader(const char* FILENAME)
	{
		const char* shaderPath = "???";

		switch (bgfx::getRendererType())
		{
		case bgfx::RendererType::Noop:
		case bgfx::RendererType::Direct3D9:  shaderPath = "assets/shaders/dx9/";   break;
		case bgfx::RendererType::Direct3D11:
		case bgfx::RendererType::Direct3D12: shaderPath = "assets/shaders/dx11/";  break;
		case bgfx::RendererType::Gnm:        shaderPath = "assets/shaders/pssl/";  break;
		case bgfx::RendererType::Metal:      shaderPath = "assets/shaders/metal/"; break;
		case bgfx::RendererType::OpenGL:     shaderPath = "assets/shaders/glsl/";  break;
		case bgfx::RendererType::OpenGLES:   shaderPath = "assets/shaders/essl/";  break;
		case bgfx::RendererType::Vulkan:     shaderPath = "assets/shaders/spirv/"; break;
		}

		size_t shaderLen = strlen(shaderPath);
		size_t fileLen = strlen(FILENAME);
		char* filePath = (char*)calloc(1, shaderLen + fileLen + 1);
		memcpy(filePath, shaderPath, shaderLen);
		memcpy(&filePath[shaderLen], FILENAME, fileLen);

		FILE* file = fopen(filePath, "rb");
		fseek(file, 0, SEEK_END);
		long fileSize = ftell(file);
		fseek(file, 0, SEEK_SET);

		const bgfx::Memory* mem = bgfx::alloc(fileSize + 1);
		fread(mem->data, 1, fileSize, file);
		mem->data[mem->size - 1] = '\0';
		fclose(file);

		return bgfx::createShader(mem);
	}

	class Redebra
	{
	public:
		bgfx::VertexBufferHandle vbh;
		bgfx::IndexBufferHandle ibh;
		bgfx::ProgramHandle program;

		void run()
		{
			bgfx::VertexLayout pcvDecl;
			pcvDecl.begin()
				.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
				.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
				.end();
			vbh = bgfx::createVertexBuffer(bgfx::makeRef(cubeVertices, sizeof(cubeVertices)), pcvDecl);
			ibh = bgfx::createIndexBuffer(bgfx::makeRef(cubeTriList, sizeof(cubeTriList)));

			bgfx::ShaderHandle vsh = loadShader("vs_cubes.bin");
			bgfx::ShaderHandle fsh = loadShader("fs_cubes.bin");
			program = bgfx::createProgram(vsh, fsh, true);

		}

	};

	Redebra* reb = new Redebra();


	bool Renderer::init(GLFWwindow* win)
	{
		bgfx::PlatformData pd;
		pd.nwh = glfwGetWin32Window(win);
		bgfx::setPlatformData(pd);

		bgfx::Init bgfxInit;
		bgfxInit.type = bgfx::RendererType::Count;
		bgfxInit.resolution.width = 1600;
		bgfxInit.resolution.height = 900;
		bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
		bgfx::init(bgfxInit);

		bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
		bgfx::setViewRect(0, 0, 0, 1600, 900);

		reb->run();

		
		if (!bgfx::init)
		{
			return false;
		}
		return true;
	}

	unsigned int counter = 0;

	void Renderer::render()
	{
		const bx::Vec3 at = { 0.0f, 0.0f,  0.0f };
		const bx::Vec3 eye = { 0.0f, 0.0f, -5.0f };
		float view[16];
		bx::mtxLookAt(view, eye, at);
		float proj[16];
		bx::mtxProj(proj, 60.0f, float(1600) / float(900), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
		bgfx::setViewTransform(0, view, proj);

		float mtx[16];
		bx::mtxRotateXY(mtx, counter * 0.01f, counter * 0.01f);
		bgfx::setTransform(mtx);

		bgfx::setVertexBuffer(0, reb->vbh);
		bgfx::setIndexBuffer(reb->ibh);

		bgfx::submit(0, reb->program);
		bgfx::frame();
		counter++;
	}

	void Renderer::draw()
	{
	}

	void Renderer::release()
	{
	}

}