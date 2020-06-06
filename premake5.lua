--[[
    GTA_reversed Build Script
    Use 'premake5 --help' for help
--]]


--[[
    Options and Actions
--]]

newoption {
    trigger     = "outdir",
    value       = "path",
    description = "Output directory for the build files"
}
if not _OPTIONS["outdir"] then
    _OPTIONS["outdir"] = "Build"
end


--[[
    The Solution
--]]
solution "gta_reversed"

    configurations { "Release", "Debug" }

    location( _OPTIONS["outdir"] )
    targetprefix "" -- no 'lib' prefix on gcc
    targetdir "Bin"
    implibdir "Bin"

    flags {
        characterset ("MBCS"), --fix strings
        staticruntime("On"),
        "NoImportLib",
        rtti ("Off"),
        "NoBufferSecurityCheck"
    }
    vpaths {
        ["Headers/*"] = {"source/**.h*",},
        ["Sources/*"] = {"source/**.c*",},
        ["*"] = {"premake5.lua", "CMakeLists.txt"}
    }
    defines {
            "NOMINMAX" 
    }
    defines {
        "_CRT_SECURE_NO_WARNINGS",
        "_SCL_SECURE_NO_WARNINGS",
        "USE_GTASA_ALLOCATOR"
    }

    includedirs {
       "source",
       "source/**"
    }
    libdirs {"source"}

    function setpaths (gamepath, exepath, scriptspath)
        scriptspath = scriptspath or ""
        if (gamepath) then
           postbuildcommands {
              '{COPY} "%{cfg.buildtarget.abspath}" "' .. gamepath .. scriptspath .. '%{cfg.buildtarget.name}"'
           }
           debugdir (gamepath)
           if (exepath) then
              -- Used VS variable $(TargetFileName) because it doesn't accept premake tokens. Does debugcommand even work outside VS??
              debugcommand (gamepath .. "gta_sa.exe")
              dir, file = exepath:match'(.*/)(.*)'
              debugdir (gamepath .. (dir or ""))
           end
        end
        --targetdir ("bin/%{prj.name}/" .. scriptspath)
     end

    filter {}
	if(os.getenv("GTA_SA_DIR")) then
		setpaths("$(GTA_SA_DIR)/", "%(cfg.buildtarget.name)", "")
	end
    
    configuration "Debug*"
        flags { symbols ("On") }
        buildoptions {"/MDd"}          
    configuration "Release*"
        defines { "NDEBUG" }
        buildoptions {"/MD"}
    flags { symbols ("Off") }
        optimize "Full"
    configuration "vs*"
         linkoptions   { "/ignore:4099" }      
         buildoptions {"/EHsc"}
    project "gta_reversed"
        language "C++"
        kind "SharedLib"
        targetname "gta_reversed"
        targetextension ".asi"
        pchheader "StdInc.h"
    pchsource "source/StdInc.cpp"           
        flags { }
       
        files {
        "source/StdInc.h",
        "source/StdInc.cpp",
        "source/**.h*",
        "source/**.c*"
        }

        --libdirs { 
        --    "libs/dxsdk" 
        --}

        --links { "d3d9", "dinput" }
        
        excludes{
        "source/**/errcom.def", --bugfix for premake5
        "source/**/errcore.def"
        }
        

