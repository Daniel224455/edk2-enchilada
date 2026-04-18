#include <PiDxe.h> 
#include <Library/DebugLib.h>
#include <Library/PrintLib.h>
#include <Library/UefiLib.h>
#include <Library/HobLib.h>

#include <libfdt.h>

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

//
// parse /chosen node and print bootargs
//
VOID
ParseChosenNode (
  VOID *Dtb
  )
{
  INT32 Node;
  CONST CHAR8 *CmdLine;
  INT32 Len;

  if (Dtb == NULL) {
    Print(L"No DTB provided\n");
    return;
  }

  // locate /chosen node
  Node = fdt_path_offset(Dtb, "/chosen");
  if (Node < 0) {
    Print(L"/chosen node not found\n");
    return;
  }

  Print(L"/chosen node found\n");

  // get bootargs property
  CmdLine = fdt_getprop(Dtb, Node, "bootargs", &Len);
  if (CmdLine == NULL) {
    Print(L"bootargs property not found\n");
    return;
  }

  Print(L"bootargs:\n");
  for (INT32 i = 0; i < Len; i++) {
    CHAR8 c = CmdLine[i];
  
    if (c == '\0') {
      Print(L"\n[NULL]\n");  // breaks
    } else {
      Print(L"%c", c);
    }
  }
  Print(L"\n");  
  
  Print(L"bootargs len: %d\n", Len);
}

EFI_STATUS
EFIAPI
BootEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable)
{
  VOID *Dtb;
  
  Print(L"BootTest: Entry\n");

  Dtb = GetDtbFromHob();
  if (Dtb != NULL) {
    ParseChosenNode(Dtb);
  }

  Print(L"BootTest: Exit\n");
  while (TRUE);
  return EFI_SUCCESS;
}