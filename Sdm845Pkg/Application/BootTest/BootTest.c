#include <Library/DebugLib.h>
#include <Library/PrintLib.h>
#include <Library/UefiLib.h>

EFI_STATUS
EFIAPI
BootEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable)
{
  Print(L"BootTest: Entry\n");


  Print(L"BootTest: Exit\n");
  while (TRUE);
  return EFI_SUCCESS;
}