[Defines]
  PLATFORM_NAME                  = Sdm845Pkg
  PLATFORM_GUID                  = 28f1a3bf-193a-47e3-a7b9-5a435eaab2ee
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010019
  OUTPUT_DIRECTORY               = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = Sdm845Pkg/Devices/enchilada.fdf

!include Sdm845Pkg/Sdm845Pkg.dsc

[BuildOptions.common]
  GCC:*_*_AARCH64_CC_FLAGS = 

[PcdsFixedAtBuild.common]
  # Simple FrameBuffer
  gSdm845PkgTokenSpaceGuid.PcdMipiFrameBufferWidth|1080
  gSdm845PkgTokenSpaceGuid.PcdMipiFrameBufferHeight|2280

  # SmBios Information
  gSdm845PkgTokenSpaceGuid.PcdDeviceVendor|"OnePlus"
  gSdm845PkgTokenSpaceGuid.PcdDeviceProduct|"6"
  gSdm845PkgTokenSpaceGuid.PcdDeviceCodeName|"enchilada"
