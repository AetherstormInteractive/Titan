cmake -S 3rdparty/Box2D -B lib/Box2D
cmake -S 3rdparty/Bullet3 -B lib/Bullet3
cmake -S 3rdparty/DiligentEngine -B lib/DiligentEngine
cmake -S 3rdparty/EnTT -B lib/EnTT
cmake -S 3rdparty/Eventpp -B lib/Eventpp
cmake -S 3rdparty/GLFW -B lib/GLFW
cmake -S 3rdparty/GLM -B lib/GLM
cmake -S 3rdparty/OIS -B lib/OIS
cmake -S 3rdparty/OpenAL-Soft -B lib/OpenAL-Soft
cmake -S "3rdparty/Ozz Animation" -B "lib/Ozz Animation"
cmake -S 3rdparty/SDL2 -B lib/SDL2
cmake -S 3rdparty/SpdLog -B lib/SpdLog

@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/assimp/Assimp.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/bullet3/BULLET_PHYSICS.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/entt/EnTT.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/eventpp/eventpp.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/gainput/Project.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/glm/glm.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/openal-soft/OpenAL.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/ozz-animation/ozz.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/glfw/GLFW.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "lib/spdlog/spdlog.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 "3rdparty\bgfx\.build\projects\vs2022\bgfx.sln"

msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/assimp/Assimp.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/bullet3/BULLET_PHYSICS.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/entt/EnTT.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/eventpp/eventpp.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/gainput/Project.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/glm/glm.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/openal-soft/OpenAL.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/ozz-animation/ozz.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/glfw/GLFW.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "lib/spdlog/spdlog.sln"
msbuild /t:Build /p:Configuration=Release /p:Platform=x64 "3rdparty\bgfx\.build\projects\vs2022\bgfx.sln"


pause