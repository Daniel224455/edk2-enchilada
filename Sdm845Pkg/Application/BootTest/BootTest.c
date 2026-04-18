#include <PiDxe.h> 
#include <Library/DebugLib.h>
#include <Library/PrintLib.h>
#include <Library/UefiLib.h>
#include <Library/HobLib.h>

extern EFI_GUID  gFdtHobGuid;

VOID *
GetDtbFromHob (
  VOID
  )
{
  EFI_HOB_GUID_TYPE  *GuidHob;
  VOID               **DtbPtr;

  GuidHob = GetFirstGuidHob (&gFdtHobGuid);
  if (GuidHob == NULL) {
    Print(L"DTB HOB not found\n");
    return NULL;
  }

  DtbPtr = (VOID **)GET_GUID_HOB_DATA (GuidHob);
  Print(L"DTB found at 0x%p\n", *DtbPtr);
  return *DtbPtr;
}

EFI_STATUS
EFIAPI
BootEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable)
{
  Print(L"BootTest: Entry\n");

  GetDtbFromHob();

  Print(L"BootTest: Exit\n");
  while (TRUE);
  return EFI_SUCCESS;
}