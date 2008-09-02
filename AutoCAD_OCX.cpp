// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// $Rev: 5081 $
// File generated on 10.08.2008 16:06:45 from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\Program Files\Common Files\Autodesk Shared\acax17enu.tlb (1)
// LIBID: {851A4561-F4EC-4631-9B0C-E7DC407512C9}
// LCID: 0
// Helpfile: C:\Program Files\Common Files\Autodesk Shared\ACADAUTO.CHM
// HelpString: AutoCAD 2009 Type Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINDOWS\system32\stdole2.tlb)
// Errors:
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Error creating palette bitmap of (TAcadAcCmColor) : Server C:\Program Files\AutoCAD 2009\acad.exe /Automation contains no icons
//   Error creating palette bitmap of (TAcadSortentsTable) : Server C:\Program Files\AutoCAD 2009\acad.exe /Automation contains no icons
//   Error creating palette bitmap of (TAcadTableStyle) : Server C:\Program Files\AutoCAD 2009\acad.exe /Automation contains no icons
//   Error creating palette bitmap of (TAcadMLeaderStyle) : Server C:\Program Files\AutoCAD 2009\acad.exe /Automation contains no icons
//   Error creating palette bitmap of (TAcadDatabase) : Server C:\Program Files\AutoCAD 2009\acad.exe /Automation contains no icons
//   Error creating palette bitmap of (TAcadSecurityParams) : Server C:\Program Files\AutoCAD 2009\acad.exe /Automation contains no icons
//   Error creating palette bitmap of (TAcadLayerStateManager) : Server C:\Program Files\AutoCAD 2009\acad.exe /Automation contains no icons
//   Error creating palette bitmap of (TAcadDocument) : Server C:\Program Files\AutoCAD 2009\acad.exe /Automation contains no icons
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <olectrls.hpp>
#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "AutoCAD_OCX.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Autocad_tlb
{

IAcadAcCmColorPtr& TAcadAcCmColor::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAcadAcCmColor::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAcadAcCmColor::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAcadAcCmColor::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAcadAcCmColor::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAcadAcCmColor::ConnectTo(IAcadAcCmColorPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAcadAcCmColor::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AcadAcCmColor;
  sd.IntfIID = __uuidof(IAcadAcCmColor);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TAcadAcCmColor::SetNames(BSTR ColorName/*[in]*/, BSTR BookName/*[in]*/)
{
  GetDefaultInterface()->SetNames(ColorName/*[in]*/, BookName/*[in]*/);
}

void __fastcall TAcadAcCmColor::Delete(void)
{
  GetDefaultInterface()->Delete();
}

void __fastcall TAcadAcCmColor::SetRGB(long Red/*[in]*/, long Green/*[in]*/, long Blue/*[in]*/)
{
  GetDefaultInterface()->SetRGB(Red/*[in]*/, Green/*[in]*/, Blue/*[in]*/);
}

void __fastcall TAcadAcCmColor::SetColorBookColor(BSTR BookName/*[in]*/, BSTR ColorName/*[in]*/)
{
  GetDefaultInterface()->SetColorBookColor(BookName/*[in]*/, ColorName/*[in]*/);
}

void __fastcall TAcadAcCmColor::set_EntityColor(long eColor/*[in]*/)
{
  GetDefaultInterface()->set_EntityColor(eColor/*[in]*/);
}

long __fastcall TAcadAcCmColor::get_EntityColor(void)
{
  long eColor;
  OLECHECK(GetDefaultInterface()->get_EntityColor((long*)&eColor));
  return eColor;
}

BSTR __fastcall TAcadAcCmColor::get_ColorName(void)
{
  BSTR Name = 0;
  OLECHECK(GetDefaultInterface()->get_ColorName((BSTR*)&Name));
  return Name;
}

BSTR __fastcall TAcadAcCmColor::get_BookName(void)
{
  BSTR Name = 0;
  OLECHECK(GetDefaultInterface()->get_BookName((BSTR*)&Name));
  return Name;
}

long __fastcall TAcadAcCmColor::get_Red(void)
{
  long Red;
  OLECHECK(GetDefaultInterface()->get_Red((long*)&Red));
  return Red;
}

long __fastcall TAcadAcCmColor::get_Blue(void)
{
  long Blue;
  OLECHECK(GetDefaultInterface()->get_Blue((long*)&Blue));
  return Blue;
}

long __fastcall TAcadAcCmColor::get_Green(void)
{
  long Green;
  OLECHECK(GetDefaultInterface()->get_Green((long*)&Green));
  return Green;
}

void __fastcall TAcadAcCmColor::set_ColorMethod(Autocad_tlb::AcColorMethod Flags/*[in]*/)
{
  GetDefaultInterface()->set_ColorMethod(Flags/*[in]*/);
}

Autocad_tlb::AcColorMethod __fastcall TAcadAcCmColor::get_ColorMethod(void)
{
  Autocad_tlb::AcColorMethod Flags;
  OLECHECK(GetDefaultInterface()->get_ColorMethod((Autocad_tlb::AcColorMethod*)&Flags));
  return Flags;
}

Autocad_tlb::AcColor __fastcall TAcadAcCmColor::get_ColorIndex(void)
{
  Autocad_tlb::AcColor color;
  OLECHECK(GetDefaultInterface()->get_ColorIndex((Autocad_tlb::AcColor*)&color));
  return color;
}

void __fastcall TAcadAcCmColor::set_ColorIndex(Autocad_tlb::AcColor color/*[in]*/)
{
  GetDefaultInterface()->set_ColorIndex(color/*[in]*/);
}

IAcadSortentsTablePtr& TAcadSortentsTable::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAcadSortentsTable::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAcadSortentsTable::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAcadSortentsTable::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAcadSortentsTable::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAcadSortentsTable::ConnectTo(IAcadSortentsTablePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAcadSortentsTable::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AcadSortentsTable;
  sd.IntfIID = __uuidof(IAcadSortentsTable);
  sd.EventIID= __uuidof(IAcadObjectEvents);
  ServerData = &sd;
}

void __fastcall TAcadSortentsTable::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 768: {
      if (OnModified) {
        (OnModified)(this, (Autocad_tlb::IAcadObject*)(LPDISPATCH)(params[0].pdispVal));
      }
      break;
      }
    default:
      break;
  }
}

void __fastcall TAcadSortentsTable::GetXData(BSTR AppName/*[in]*/, VARIANT* XDataType/*[out]*/, 
                                             VARIANT* XDataValue/*[out]*/)
{
  GetDefaultInterface()->GetXData(AppName/*[in]*/, XDataType/*[out]*/, XDataValue/*[out]*/);
}

void __fastcall TAcadSortentsTable::SetXData(VARIANT XDataType/*[in]*/, VARIANT XDataValue/*[in]*/)
{
  GetDefaultInterface()->SetXData(XDataType/*[in]*/, XDataValue/*[in]*/);
}

void __fastcall TAcadSortentsTable::Delete(void)
{
  GetDefaultInterface()->Delete();
}

Autocad_tlb::IAcadDictionary* __fastcall TAcadSortentsTable::GetExtensionDictionary(void)
{
  Autocad_tlb::IAcadDictionary* pExtDictionary = 0;
  OLECHECK(GetDefaultInterface()->GetExtensionDictionary((Autocad_tlb::IAcadDictionary**)&pExtDictionary));
  return pExtDictionary;
}

void __fastcall TAcadSortentsTable::Erase(void)
{
  GetDefaultInterface()->Erase();
}

void __fastcall TAcadSortentsTable::MoveToBottom(VARIANT Objects/*[in]*/)
{
  GetDefaultInterface()->MoveToBottom(Objects/*[in]*/);
}

void __fastcall TAcadSortentsTable::MoveToTop(VARIANT Objects/*[in]*/)
{
  GetDefaultInterface()->MoveToTop(Objects/*[in]*/);
}

void __fastcall TAcadSortentsTable::MoveBelow(VARIANT Objects/*[in]*/, 
                                              Autocad_tlb::IAcadEntity* Target/*[in]*/)
{
  GetDefaultInterface()->MoveBelow(Objects/*[in]*/, Target/*[in]*/);
}

void __fastcall TAcadSortentsTable::MoveAbove(VARIANT Objects/*[in]*/, 
                                              Autocad_tlb::IAcadEntity* Target/*[in]*/)
{
  GetDefaultInterface()->MoveAbove(Objects/*[in]*/, Target/*[in]*/);
}

void __fastcall TAcadSortentsTable::SwapOrder(Autocad_tlb::IAcadEntity* Object1/*[in]*/, 
                                              Autocad_tlb::IAcadEntity* Object2/*[in]*/)
{
  GetDefaultInterface()->SwapOrder(Object1/*[in]*/, Object2/*[in]*/);
}

Autocad_tlb::IAcadBlock* __fastcall TAcadSortentsTable::Block(void)
{
  Autocad_tlb::IAcadBlock* pBlock = 0;
  OLECHECK(GetDefaultInterface()->Block((Autocad_tlb::IAcadBlock**)&pBlock));
  return pBlock;
}

void __fastcall TAcadSortentsTable::GetFullDrawOrder(VARIANT* Objects/*[out]*/, 
                                                     VARIANT_BOOL honorSortentsSysvar/*[in]*/)
{
  GetDefaultInterface()->GetFullDrawOrder(Objects/*[out]*/, honorSortentsSysvar/*[in]*/);
}

void __fastcall TAcadSortentsTable::GetRelativeDrawOrder(VARIANT* Objects/*[out]*/, 
                                                         VARIANT_BOOL honorSortentsSysvar/*[in]*/)
{
  GetDefaultInterface()->GetRelativeDrawOrder(Objects/*[out]*/, honorSortentsSysvar/*[in]*/);
}

void __fastcall TAcadSortentsTable::SetRelativeDrawOrder(VARIANT Objects/*[in]*/)
{
  GetDefaultInterface()->SetRelativeDrawOrder(Objects/*[in]*/);
}

BSTR __fastcall TAcadSortentsTable::get_Handle(void)
{
  BSTR Handle = 0;
  OLECHECK(GetDefaultInterface()->get_Handle((BSTR*)&Handle));
  return Handle;
}

BSTR __fastcall TAcadSortentsTable::get_ObjectName(void)
{
  BSTR ObjectName = 0;
  OLECHECK(GetDefaultInterface()->get_ObjectName((BSTR*)&ObjectName));
  return ObjectName;
}

Autocad_tlb::LONG_PTR __fastcall TAcadSortentsTable::get_ObjectID(void)
{
  Autocad_tlb::LONG_PTR ObjectID;
  OLECHECK(GetDefaultInterface()->get_ObjectID((Autocad_tlb::LONG_PTR*)&ObjectID));
  return ObjectID;
}

LPDISPATCH __fastcall TAcadSortentsTable::get_Application(void)
{
  LPDISPATCH ApplicationObject;
  OLECHECK(GetDefaultInterface()->get_Application((LPDISPATCH*)&ApplicationObject));
  return ApplicationObject;
}

Autocad_tlb::IAcadDatabasePtr __fastcall TAcadSortentsTable::get_Database(void)
{
  Autocad_tlb::IAcadDatabasePtr pDatabase;
  OLECHECK(GetDefaultInterface()->get_Database(&pDatabase));
  return pDatabase;
}

VARIANT_BOOL __fastcall TAcadSortentsTable::get_HasExtensionDictionary(void)
{
  VARIANT_BOOL bHasDictionary;
  OLECHECK(GetDefaultInterface()->get_HasExtensionDictionary((VARIANT_BOOL*)&bHasDictionary));
  return bHasDictionary;
}

Autocad_tlb::LONG_PTR __fastcall TAcadSortentsTable::get_OwnerID(void)
{
  Autocad_tlb::LONG_PTR OwnerID;
  OLECHECK(GetDefaultInterface()->get_OwnerID((Autocad_tlb::LONG_PTR*)&OwnerID));
  return OwnerID;
}

LPDISPATCH __fastcall TAcadSortentsTable::get_Document(void)
{
  LPDISPATCH pDocument;
  OLECHECK(GetDefaultInterface()->get_Document((LPDISPATCH*)&pDocument));
  return pDocument;
}

IAcadTableStylePtr& TAcadTableStyle::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAcadTableStyle::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAcadTableStyle::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAcadTableStyle::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAcadTableStyle::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAcadTableStyle::ConnectTo(IAcadTableStylePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAcadTableStyle::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AcadTableStyle;
  sd.IntfIID = __uuidof(IAcadTableStyle);
  sd.EventIID= __uuidof(IAcadObjectEvents);
  ServerData = &sd;
}

void __fastcall TAcadTableStyle::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 768: {
      if (OnModified) {
        (OnModified)(this, (Autocad_tlb::IAcadObject*)(LPDISPATCH)(params[0].pdispVal));
      }
      break;
      }
    default:
      break;
  }
}

void __fastcall TAcadTableStyle::GetXData(BSTR AppName/*[in]*/, VARIANT* XDataType/*[out]*/, 
                                          VARIANT* XDataValue/*[out]*/)
{
  GetDefaultInterface()->GetXData(AppName/*[in]*/, XDataType/*[out]*/, XDataValue/*[out]*/);
}

void __fastcall TAcadTableStyle::SetXData(VARIANT XDataType/*[in]*/, VARIANT XDataValue/*[in]*/)
{
  GetDefaultInterface()->SetXData(XDataType/*[in]*/, XDataValue/*[in]*/);
}

void __fastcall TAcadTableStyle::Delete(void)
{
  GetDefaultInterface()->Delete();
}

Autocad_tlb::IAcadDictionary* __fastcall TAcadTableStyle::GetExtensionDictionary(void)
{
  Autocad_tlb::IAcadDictionary* pExtDictionary = 0;
  OLECHECK(GetDefaultInterface()->GetExtensionDictionary((Autocad_tlb::IAcadDictionary**)&pExtDictionary));
  return pExtDictionary;
}

void __fastcall TAcadTableStyle::Erase(void)
{
  GetDefaultInterface()->Erase();
}

BSTR __fastcall TAcadTableStyle::GetTextStyle(Autocad_tlb::AcRowType rowType/*[in]*/)
{
  BSTR bstrName = 0;
  OLECHECK(GetDefaultInterface()->GetTextStyle(rowType, (BSTR*)&bstrName));
  return bstrName;
}

void __fastcall TAcadTableStyle::SetTextStyle(int rowTypes/*[in]*/, BSTR bstrName/*[in]*/)
{
  GetDefaultInterface()->SetTextStyle(rowTypes/*[in]*/, bstrName/*[in]*/);
}

double __fastcall TAcadTableStyle::GetTextHeight(Autocad_tlb::AcRowType rowType/*[in]*/)
{
  double pTextHeight;
  OLECHECK(GetDefaultInterface()->GetTextHeight(rowType, (double*)&pTextHeight));
  return pTextHeight;
}

void __fastcall TAcadTableStyle::SetTextHeight(int rowTypes/*[in]*/, double TextHeight/*[in]*/)
{
  GetDefaultInterface()->SetTextHeight(rowTypes/*[in]*/, TextHeight/*[in]*/);
}

Autocad_tlb::AcCellAlignment __fastcall TAcadTableStyle::GetAlignment(Autocad_tlb::AcRowType rowType/*[in]*/)
{
  Autocad_tlb::AcCellAlignment pCellAlignment;
  OLECHECK(GetDefaultInterface()->GetAlignment(rowType, (Autocad_tlb::AcCellAlignment*)&pCellAlignment));
  return pCellAlignment;
}

void __fastcall TAcadTableStyle::SetAlignment(int rowTypes/*[in]*/, 
                                              Autocad_tlb::AcCellAlignment cellAlignment/*[in]*/)
{
  GetDefaultInterface()->SetAlignment(rowTypes/*[in]*/, cellAlignment/*[in]*/);
}

Autocad_tlb::IAcadAcCmColor* __fastcall TAcadTableStyle::GetColor(Autocad_tlb::AcRowType rowType/*[in]*/)
{
  Autocad_tlb::IAcadAcCmColor* pColor = 0;
  OLECHECK(GetDefaultInterface()->GetColor(rowType, (Autocad_tlb::IAcadAcCmColor**)&pColor));
  return pColor;
}

void __fastcall TAcadTableStyle::SetColor(int rowTypes/*[in]*/, 
                                          Autocad_tlb::IAcadAcCmColor* pColor/*[in]*/)
{
  GetDefaultInterface()->SetColor(rowTypes/*[in]*/, pColor/*[in]*/);
}

Autocad_tlb::IAcadAcCmColor* __fastcall TAcadTableStyle::GetBackgroundColor(Autocad_tlb::AcRowType rowType/*[in]*/)
{
  Autocad_tlb::IAcadAcCmColor* pColor = 0;
  OLECHECK(GetDefaultInterface()->GetBackgroundColor(rowType, (Autocad_tlb::IAcadAcCmColor**)&pColor));
  return pColor;
}

void __fastcall TAcadTableStyle::SetBackgroundColor(int rowTypes/*[in]*/, 
                                                    Autocad_tlb::IAcadAcCmColor* pColor/*[in]*/)
{
  GetDefaultInterface()->SetBackgroundColor(rowTypes/*[in]*/, pColor/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadTableStyle::GetBackgroundColorNone(Autocad_tlb::AcRowType rowType/*[in]*/)
{
  VARIANT_BOOL bValue;
  OLECHECK(GetDefaultInterface()->GetBackgroundColorNone(rowType, (VARIANT_BOOL*)&bValue));
  return bValue;
}

void __fastcall TAcadTableStyle::SetBackgroundColorNone(int rowTypes/*[in]*/, 
                                                        VARIANT_BOOL* bValue/*[in]*/)
{
  GetDefaultInterface()->SetBackgroundColorNone(rowTypes/*[in]*/, bValue/*[in]*/);
}

Autocad_tlb::ACAD_LWEIGHT __fastcall TAcadTableStyle::GetGridLineWeight(Autocad_tlb::AcGridLineType gridLineType/*[in]*/, 
                                                                        Autocad_tlb::AcRowType rowType/*[in]*/)
{
  Autocad_tlb::ACAD_LWEIGHT Lineweight;
  OLECHECK(GetDefaultInterface()->GetGridLineWeight(gridLineType, rowType, (Autocad_tlb::ACAD_LWEIGHT*)&Lineweight));
  return Lineweight;
}

void __fastcall TAcadTableStyle::SetGridLineWeight(int gridLineTypes/*[in]*/, int rowTypes/*[in]*/, 
                                                   Autocad_tlb::ACAD_LWEIGHT Lineweight/*[in]*/)
{
  GetDefaultInterface()->SetGridLineWeight(gridLineTypes/*[in]*/, rowTypes/*[in]*/, 
                                           Lineweight/*[in]*/);
}

Autocad_tlb::IAcadAcCmColor* __fastcall TAcadTableStyle::GetGridColor(Autocad_tlb::AcGridLineType gridLineType/*[in]*/, 
                                                                      Autocad_tlb::AcRowType rowType/*[in]*/)
{
  Autocad_tlb::IAcadAcCmColor* pColor = 0;
  OLECHECK(GetDefaultInterface()->GetGridColor(gridLineType, rowType, (Autocad_tlb::IAcadAcCmColor**)&pColor));
  return pColor;
}

void __fastcall TAcadTableStyle::SetGridColor(int gridLineTypes/*[in]*/, int rowTypes/*[in]*/, 
                                              Autocad_tlb::IAcadAcCmColor* pColor/*[in]*/)
{
  GetDefaultInterface()->SetGridColor(gridLineTypes/*[in]*/, rowTypes/*[in]*/, pColor/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadTableStyle::GetGridVisibility(Autocad_tlb::AcGridLineType gridLineType/*[in]*/, 
                                                           Autocad_tlb::AcRowType rowType/*[in]*/)
{
  VARIANT_BOOL bValue;
  OLECHECK(GetDefaultInterface()->GetGridVisibility(gridLineType, rowType, (VARIANT_BOOL*)&bValue));
  return bValue;
}

void __fastcall TAcadTableStyle::SetGridVisibility(int gridLineTypes/*[in]*/, int rowTypes/*[in]*/, 
                                                   VARIANT_BOOL bValue/*[in]*/)
{
  GetDefaultInterface()->SetGridVisibility(gridLineTypes/*[in]*/, rowTypes/*[in]*/, bValue/*[in]*/);
}

void __fastcall TAcadTableStyle::GetDataType(Autocad_tlb::AcRowType rowType/*[in]*/, 
                                             Autocad_tlb::AcValueDataType* pDataType/*[out]*/, 
                                             Autocad_tlb::AcValueUnitType* pUnitType/*[out]*/)
{
  GetDefaultInterface()->GetDataType(rowType/*[in]*/, pDataType/*[out]*/, pUnitType/*[out]*/);
}

void __fastcall TAcadTableStyle::SetDataType(int rowTypes/*[in]*/, 
                                             Autocad_tlb::AcValueDataType nDataType/*[in]*/, 
                                             Autocad_tlb::AcValueUnitType nUnitType/*[in]*/)
{
  GetDefaultInterface()->SetDataType(rowTypes/*[in]*/, nDataType/*[in]*/, nUnitType/*[in]*/);
}

BSTR __fastcall TAcadTableStyle::GetFormat(Autocad_tlb::AcRowType rowType/*[in]*/)
{
  BSTR pVal = 0;
  OLECHECK(GetDefaultInterface()->GetFormat(rowType, (BSTR*)&pVal));
  return pVal;
}

void __fastcall TAcadTableStyle::SetFormat(int rowTypes/*[in]*/, BSTR val/*[in]*/)
{
  GetDefaultInterface()->SetFormat(rowTypes/*[in]*/, val/*[in]*/);
}

BSTR __fastcall TAcadTableStyle::get_Handle(void)
{
  BSTR Handle = 0;
  OLECHECK(GetDefaultInterface()->get_Handle((BSTR*)&Handle));
  return Handle;
}

BSTR __fastcall TAcadTableStyle::get_ObjectName(void)
{
  BSTR ObjectName = 0;
  OLECHECK(GetDefaultInterface()->get_ObjectName((BSTR*)&ObjectName));
  return ObjectName;
}

Autocad_tlb::LONG_PTR __fastcall TAcadTableStyle::get_ObjectID(void)
{
  Autocad_tlb::LONG_PTR ObjectID;
  OLECHECK(GetDefaultInterface()->get_ObjectID((Autocad_tlb::LONG_PTR*)&ObjectID));
  return ObjectID;
}

LPDISPATCH __fastcall TAcadTableStyle::get_Application(void)
{
  LPDISPATCH ApplicationObject;
  OLECHECK(GetDefaultInterface()->get_Application((LPDISPATCH*)&ApplicationObject));
  return ApplicationObject;
}

Autocad_tlb::IAcadDatabasePtr __fastcall TAcadTableStyle::get_Database(void)
{
  Autocad_tlb::IAcadDatabasePtr pDatabase;
  OLECHECK(GetDefaultInterface()->get_Database(&pDatabase));
  return pDatabase;
}

VARIANT_BOOL __fastcall TAcadTableStyle::get_HasExtensionDictionary(void)
{
  VARIANT_BOOL bHasDictionary;
  OLECHECK(GetDefaultInterface()->get_HasExtensionDictionary((VARIANT_BOOL*)&bHasDictionary));
  return bHasDictionary;
}

Autocad_tlb::LONG_PTR __fastcall TAcadTableStyle::get_OwnerID(void)
{
  Autocad_tlb::LONG_PTR OwnerID;
  OLECHECK(GetDefaultInterface()->get_OwnerID((Autocad_tlb::LONG_PTR*)&OwnerID));
  return OwnerID;
}

LPDISPATCH __fastcall TAcadTableStyle::get_Document(void)
{
  LPDISPATCH pDocument;
  OLECHECK(GetDefaultInterface()->get_Document((LPDISPATCH*)&pDocument));
  return pDocument;
}

BSTR __fastcall TAcadTableStyle::get_Name(void)
{
  BSTR bstrValue = 0;
  OLECHECK(GetDefaultInterface()->get_Name((BSTR*)&bstrValue));
  return bstrValue;
}

void __fastcall TAcadTableStyle::set_Name(BSTR bstrValue/*[in]*/)
{
  GetDefaultInterface()->set_Name(bstrValue/*[in]*/);
}

BSTR __fastcall TAcadTableStyle::get_Description(void)
{
  BSTR bstr = 0;
  OLECHECK(GetDefaultInterface()->get_Description((BSTR*)&bstr));
  return bstr;
}

void __fastcall TAcadTableStyle::set_Description(BSTR bstr/*[in]*/)
{
  GetDefaultInterface()->set_Description(bstr/*[in]*/);
}

long __fastcall TAcadTableStyle::get_BitFlags(void)
{
  long bitFlag;
  OLECHECK(GetDefaultInterface()->get_BitFlags((long*)&bitFlag));
  return bitFlag;
}

void __fastcall TAcadTableStyle::set_BitFlags(long bitFlag/*[in]*/)
{
  GetDefaultInterface()->set_BitFlags(bitFlag/*[in]*/);
}

Autocad_tlb::AcTableDirection __fastcall TAcadTableStyle::get_FlowDirection(void)
{
  Autocad_tlb::AcTableDirection pFlow;
  OLECHECK(GetDefaultInterface()->get_FlowDirection((Autocad_tlb::AcTableDirection*)&pFlow));
  return pFlow;
}

void __fastcall TAcadTableStyle::set_FlowDirection(Autocad_tlb::AcTableDirection pFlow/*[in]*/)
{
  GetDefaultInterface()->set_FlowDirection(pFlow/*[in]*/);
}

double __fastcall TAcadTableStyle::get_HorzCellMargin(void)
{
  double dHorzCellMargin;
  OLECHECK(GetDefaultInterface()->get_HorzCellMargin((double*)&dHorzCellMargin));
  return dHorzCellMargin;
}

void __fastcall TAcadTableStyle::set_HorzCellMargin(double dHorzCellMargin/*[in]*/)
{
  GetDefaultInterface()->set_HorzCellMargin(dHorzCellMargin/*[in]*/);
}

double __fastcall TAcadTableStyle::get_VertCellMargin(void)
{
  double dVertCellMargin;
  OLECHECK(GetDefaultInterface()->get_VertCellMargin((double*)&dVertCellMargin));
  return dVertCellMargin;
}

void __fastcall TAcadTableStyle::set_VertCellMargin(double dVertCellMargin/*[in]*/)
{
  GetDefaultInterface()->set_VertCellMargin(dVertCellMargin/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadTableStyle::get_TitleSuppressed(void)
{
  VARIANT_BOOL bValue;
  OLECHECK(GetDefaultInterface()->get_TitleSuppressed((VARIANT_BOOL*)&bValue));
  return bValue;
}

void __fastcall TAcadTableStyle::set_TitleSuppressed(VARIANT_BOOL bValue/*[in]*/)
{
  GetDefaultInterface()->set_TitleSuppressed(bValue/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadTableStyle::get_HeaderSuppressed(void)
{
  VARIANT_BOOL bValue;
  OLECHECK(GetDefaultInterface()->get_HeaderSuppressed((VARIANT_BOOL*)&bValue));
  return bValue;
}

void __fastcall TAcadTableStyle::set_HeaderSuppressed(VARIANT_BOOL bValue/*[in]*/)
{
  GetDefaultInterface()->set_HeaderSuppressed(bValue/*[in]*/);
}

IAcadMLeaderStylePtr& TAcadMLeaderStyle::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAcadMLeaderStyle::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAcadMLeaderStyle::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAcadMLeaderStyle::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAcadMLeaderStyle::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAcadMLeaderStyle::ConnectTo(IAcadMLeaderStylePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAcadMLeaderStyle::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AcadMLeaderStyle;
  sd.IntfIID = __uuidof(IAcadMLeaderStyle);
  sd.EventIID= __uuidof(IAcadObjectEvents);
  ServerData = &sd;
}

void __fastcall TAcadMLeaderStyle::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 768: {
      if (OnModified) {
        (OnModified)(this, (Autocad_tlb::IAcadObject*)(LPDISPATCH)(params[0].pdispVal));
      }
      break;
      }
    default:
      break;
  }
}

void __fastcall TAcadMLeaderStyle::GetXData(BSTR AppName/*[in]*/, VARIANT* XDataType/*[out]*/, 
                                            VARIANT* XDataValue/*[out]*/)
{
  GetDefaultInterface()->GetXData(AppName/*[in]*/, XDataType/*[out]*/, XDataValue/*[out]*/);
}

void __fastcall TAcadMLeaderStyle::SetXData(VARIANT XDataType/*[in]*/, VARIANT XDataValue/*[in]*/)
{
  GetDefaultInterface()->SetXData(XDataType/*[in]*/, XDataValue/*[in]*/);
}

void __fastcall TAcadMLeaderStyle::Delete(void)
{
  GetDefaultInterface()->Delete();
}

Autocad_tlb::IAcadDictionary* __fastcall TAcadMLeaderStyle::GetExtensionDictionary(void)
{
  Autocad_tlb::IAcadDictionary* pExtDictionary = 0;
  OLECHECK(GetDefaultInterface()->GetExtensionDictionary((Autocad_tlb::IAcadDictionary**)&pExtDictionary));
  return pExtDictionary;
}

void __fastcall TAcadMLeaderStyle::Erase(void)
{
  GetDefaultInterface()->Erase();
}

BSTR __fastcall TAcadMLeaderStyle::get_Handle(void)
{
  BSTR Handle = 0;
  OLECHECK(GetDefaultInterface()->get_Handle((BSTR*)&Handle));
  return Handle;
}

BSTR __fastcall TAcadMLeaderStyle::get_ObjectName(void)
{
  BSTR ObjectName = 0;
  OLECHECK(GetDefaultInterface()->get_ObjectName((BSTR*)&ObjectName));
  return ObjectName;
}

Autocad_tlb::LONG_PTR __fastcall TAcadMLeaderStyle::get_ObjectID(void)
{
  Autocad_tlb::LONG_PTR ObjectID;
  OLECHECK(GetDefaultInterface()->get_ObjectID((Autocad_tlb::LONG_PTR*)&ObjectID));
  return ObjectID;
}

LPDISPATCH __fastcall TAcadMLeaderStyle::get_Application(void)
{
  LPDISPATCH ApplicationObject;
  OLECHECK(GetDefaultInterface()->get_Application((LPDISPATCH*)&ApplicationObject));
  return ApplicationObject;
}

Autocad_tlb::IAcadDatabasePtr __fastcall TAcadMLeaderStyle::get_Database(void)
{
  Autocad_tlb::IAcadDatabasePtr pDatabase;
  OLECHECK(GetDefaultInterface()->get_Database(&pDatabase));
  return pDatabase;
}

VARIANT_BOOL __fastcall TAcadMLeaderStyle::get_HasExtensionDictionary(void)
{
  VARIANT_BOOL bHasDictionary;
  OLECHECK(GetDefaultInterface()->get_HasExtensionDictionary((VARIANT_BOOL*)&bHasDictionary));
  return bHasDictionary;
}

Autocad_tlb::LONG_PTR __fastcall TAcadMLeaderStyle::get_OwnerID(void)
{
  Autocad_tlb::LONG_PTR OwnerID;
  OLECHECK(GetDefaultInterface()->get_OwnerID((Autocad_tlb::LONG_PTR*)&OwnerID));
  return OwnerID;
}

LPDISPATCH __fastcall TAcadMLeaderStyle::get_Document(void)
{
  LPDISPATCH pDocument;
  OLECHECK(GetDefaultInterface()->get_Document((LPDISPATCH*)&pDocument));
  return pDocument;
}

BSTR __fastcall TAcadMLeaderStyle::get_Name(void)
{
  BSTR Name = 0;
  OLECHECK(GetDefaultInterface()->get_Name((BSTR*)&Name));
  return Name;
}

void __fastcall TAcadMLeaderStyle::set_Name(BSTR Name/*[in]*/)
{
  GetDefaultInterface()->set_Name(Name/*[in]*/);
}

BSTR __fastcall TAcadMLeaderStyle::get_Description(void)
{
  BSTR Description = 0;
  OLECHECK(GetDefaultInterface()->get_Description((BSTR*)&Description));
  return Description;
}

void __fastcall TAcadMLeaderStyle::set_Description(BSTR Description/*[in]*/)
{
  GetDefaultInterface()->set_Description(Description/*[in]*/);
}

long __fastcall TAcadMLeaderStyle::get_BitFlags(void)
{
  long bitFlag;
  OLECHECK(GetDefaultInterface()->get_BitFlags((long*)&bitFlag));
  return bitFlag;
}

void __fastcall TAcadMLeaderStyle::set_BitFlags(long bitFlag/*[in]*/)
{
  GetDefaultInterface()->set_BitFlags(bitFlag/*[in]*/);
}

Autocad_tlb::AcMLeaderContentType __fastcall TAcadMLeaderStyle::get_ContentType(void)
{
  Autocad_tlb::AcMLeaderContentType Type;
  OLECHECK(GetDefaultInterface()->get_ContentType((Autocad_tlb::AcMLeaderContentType*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_ContentType(Autocad_tlb::AcMLeaderContentType Type/*[in]*/)
{
  GetDefaultInterface()->set_ContentType(Type/*[in]*/);
}

Autocad_tlb::AcDrawMLeaderOrderType __fastcall TAcadMLeaderStyle::get_DrawMLeaderOrderType(void)
{
  Autocad_tlb::AcDrawMLeaderOrderType Type;
  OLECHECK(GetDefaultInterface()->get_DrawMLeaderOrderType((Autocad_tlb::AcDrawMLeaderOrderType*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_DrawMLeaderOrderType(Autocad_tlb::AcDrawMLeaderOrderType Type/*[in]*/)
{
  GetDefaultInterface()->set_DrawMLeaderOrderType(Type/*[in]*/);
}

Autocad_tlb::AcDrawLeaderOrderType __fastcall TAcadMLeaderStyle::get_DrawLeaderOrderType(void)
{
  Autocad_tlb::AcDrawLeaderOrderType Type;
  OLECHECK(GetDefaultInterface()->get_DrawLeaderOrderType((Autocad_tlb::AcDrawLeaderOrderType*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_DrawLeaderOrderType(Autocad_tlb::AcDrawLeaderOrderType Type/*[in]*/)
{
  GetDefaultInterface()->set_DrawLeaderOrderType(Type/*[in]*/);
}

int __fastcall TAcadMLeaderStyle::get_MaxLeaderSegmentsPoints(void)
{
  int number;
  OLECHECK(GetDefaultInterface()->get_MaxLeaderSegmentsPoints((int*)&number));
  return number;
}

void __fastcall TAcadMLeaderStyle::set_MaxLeaderSegmentsPoints(int number/*[in]*/)
{
  GetDefaultInterface()->set_MaxLeaderSegmentsPoints(number/*[in]*/);
}

Autocad_tlb::AcSegmentAngleType __fastcall TAcadMLeaderStyle::get_FirstSegmentAngleConstraint(void)
{
  Autocad_tlb::AcSegmentAngleType constraint;
  OLECHECK(GetDefaultInterface()->get_FirstSegmentAngleConstraint((Autocad_tlb::AcSegmentAngleType*)&constraint));
  return constraint;
}

void __fastcall TAcadMLeaderStyle::set_FirstSegmentAngleConstraint(Autocad_tlb::AcSegmentAngleType constraint/*[in]*/)
{
  GetDefaultInterface()->set_FirstSegmentAngleConstraint(constraint/*[in]*/);
}

Autocad_tlb::AcSegmentAngleType __fastcall TAcadMLeaderStyle::get_SecondSegmentAngleConstraint(void)
{
  Autocad_tlb::AcSegmentAngleType constraint;
  OLECHECK(GetDefaultInterface()->get_SecondSegmentAngleConstraint((Autocad_tlb::AcSegmentAngleType*)&constraint));
  return constraint;
}

void __fastcall TAcadMLeaderStyle::set_SecondSegmentAngleConstraint(Autocad_tlb::AcSegmentAngleType constraint/*[in]*/)
{
  GetDefaultInterface()->set_SecondSegmentAngleConstraint(constraint/*[in]*/);
}

Autocad_tlb::AcMLeaderType __fastcall TAcadMLeaderStyle::get_LeaderLineType(void)
{
  Autocad_tlb::AcMLeaderType Type;
  OLECHECK(GetDefaultInterface()->get_LeaderLineType((Autocad_tlb::AcMLeaderType*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_LeaderLineType(Autocad_tlb::AcMLeaderType Type/*[in]*/)
{
  GetDefaultInterface()->set_LeaderLineType(Type/*[in]*/);
}

Autocad_tlb::IAcadAcCmColorPtr __fastcall TAcadMLeaderStyle::get_LeaderLineColor(void)
{
  Autocad_tlb::IAcadAcCmColorPtr color;
  OLECHECK(GetDefaultInterface()->get_LeaderLineColor(&color));
  return color;
}

void __fastcall TAcadMLeaderStyle::set_LeaderLineColor(Autocad_tlb::IAcadAcCmColorPtr color/*[in]*/)
{
  GetDefaultInterface()->set_LeaderLineColor(color/*[in]*/);
}

Autocad_tlb::ACAD_LTYPE __fastcall TAcadMLeaderStyle::get_LeaderLineTypeId(void)
{
  Autocad_tlb::ACAD_LTYPE Type;
  OLECHECK(GetDefaultInterface()->get_LeaderLineTypeId((Autocad_tlb::ACAD_LTYPE*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_LeaderLineTypeId(Autocad_tlb::ACAD_LTYPE Type/*[in]*/)
{
  GetDefaultInterface()->set_LeaderLineTypeId(Type/*[in]*/);
}

Autocad_tlb::AcLineWeight __fastcall TAcadMLeaderStyle::get_LeaderLineWeight(void)
{
  Autocad_tlb::AcLineWeight weight;
  OLECHECK(GetDefaultInterface()->get_LeaderLineWeight((Autocad_tlb::AcLineWeight*)&weight));
  return weight;
}

void __fastcall TAcadMLeaderStyle::set_LeaderLineWeight(Autocad_tlb::AcLineWeight weight/*[in]*/)
{
  GetDefaultInterface()->set_LeaderLineWeight(weight/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadMLeaderStyle::get_EnableLanding(void)
{
  VARIANT_BOOL enabled;
  OLECHECK(GetDefaultInterface()->get_EnableLanding((VARIANT_BOOL*)&enabled));
  return enabled;
}

void __fastcall TAcadMLeaderStyle::set_EnableLanding(VARIANT_BOOL enabled/*[in]*/)
{
  GetDefaultInterface()->set_EnableLanding(enabled/*[in]*/);
}

double __fastcall TAcadMLeaderStyle::get_LandingGap(void)
{
  double LandingGap;
  OLECHECK(GetDefaultInterface()->get_LandingGap((double*)&LandingGap));
  return LandingGap;
}

void __fastcall TAcadMLeaderStyle::set_LandingGap(double LandingGap/*[in]*/)
{
  GetDefaultInterface()->set_LandingGap(LandingGap/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadMLeaderStyle::get_EnableDogleg(void)
{
  VARIANT_BOOL enabled;
  OLECHECK(GetDefaultInterface()->get_EnableDogleg((VARIANT_BOOL*)&enabled));
  return enabled;
}

void __fastcall TAcadMLeaderStyle::set_EnableDogleg(VARIANT_BOOL enabled/*[in]*/)
{
  GetDefaultInterface()->set_EnableDogleg(enabled/*[in]*/);
}

double __fastcall TAcadMLeaderStyle::get_DoglegLength(void)
{
  double DoglegLength;
  OLECHECK(GetDefaultInterface()->get_DoglegLength((double*)&DoglegLength));
  return DoglegLength;
}

void __fastcall TAcadMLeaderStyle::set_DoglegLength(double DoglegLength/*[in]*/)
{
  GetDefaultInterface()->set_DoglegLength(DoglegLength/*[in]*/);
}

BSTR __fastcall TAcadMLeaderStyle::get_ArrowSymbol(void)
{
  BSTR Name = 0;
  OLECHECK(GetDefaultInterface()->get_ArrowSymbol((BSTR*)&Name));
  return Name;
}

void __fastcall TAcadMLeaderStyle::set_ArrowSymbol(BSTR Name/*[in]*/)
{
  GetDefaultInterface()->set_ArrowSymbol(Name/*[in]*/);
}

double __fastcall TAcadMLeaderStyle::get_ArrowSize(void)
{
  double size;
  OLECHECK(GetDefaultInterface()->get_ArrowSize((double*)&size));
  return size;
}

void __fastcall TAcadMLeaderStyle::set_ArrowSize(double size/*[in]*/)
{
  GetDefaultInterface()->set_ArrowSize(size/*[in]*/);
}

BSTR __fastcall TAcadMLeaderStyle::get_TextStyle(void)
{
  BSTR Name = 0;
  OLECHECK(GetDefaultInterface()->get_TextStyle((BSTR*)&Name));
  return Name;
}

void __fastcall TAcadMLeaderStyle::set_TextStyle(BSTR Name/*[in]*/)
{
  GetDefaultInterface()->set_TextStyle(Name/*[in]*/);
}

Autocad_tlb::AcTextAttachmentType __fastcall TAcadMLeaderStyle::get_TextLeftAttachmentType(void)
{
  Autocad_tlb::AcTextAttachmentType Type;
  OLECHECK(GetDefaultInterface()->get_TextLeftAttachmentType((Autocad_tlb::AcTextAttachmentType*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_TextLeftAttachmentType(Autocad_tlb::AcTextAttachmentType Type/*[in]*/)
{
  GetDefaultInterface()->set_TextLeftAttachmentType(Type/*[in]*/);
}

Autocad_tlb::AcTextAttachmentType __fastcall TAcadMLeaderStyle::get_TextRightAttachmentType(void)
{
  Autocad_tlb::AcTextAttachmentType Type;
  OLECHECK(GetDefaultInterface()->get_TextRightAttachmentType((Autocad_tlb::AcTextAttachmentType*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_TextRightAttachmentType(Autocad_tlb::AcTextAttachmentType Type/*[in]*/)
{
  GetDefaultInterface()->set_TextRightAttachmentType(Type/*[in]*/);
}

Autocad_tlb::IAcadAcCmColorPtr __fastcall TAcadMLeaderStyle::get_TextColor(void)
{
  Autocad_tlb::IAcadAcCmColorPtr color;
  OLECHECK(GetDefaultInterface()->get_TextColor(&color));
  return color;
}

void __fastcall TAcadMLeaderStyle::set_TextColor(Autocad_tlb::IAcadAcCmColorPtr color/*[in]*/)
{
  GetDefaultInterface()->set_TextColor(color/*[in]*/);
}

double __fastcall TAcadMLeaderStyle::get_TextHeight(void)
{
  double Height;
  OLECHECK(GetDefaultInterface()->get_TextHeight((double*)&Height));
  return Height;
}

void __fastcall TAcadMLeaderStyle::set_TextHeight(double Height/*[in]*/)
{
  GetDefaultInterface()->set_TextHeight(Height/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadMLeaderStyle::get_EnableFrameText(void)
{
  VARIANT_BOOL enabled;
  OLECHECK(GetDefaultInterface()->get_EnableFrameText((VARIANT_BOOL*)&enabled));
  return enabled;
}

void __fastcall TAcadMLeaderStyle::set_EnableFrameText(VARIANT_BOOL enabled/*[in]*/)
{
  GetDefaultInterface()->set_EnableFrameText(enabled/*[in]*/);
}

double __fastcall TAcadMLeaderStyle::get_AlignSpace(void)
{
  double AlignSpace;
  OLECHECK(GetDefaultInterface()->get_AlignSpace((double*)&AlignSpace));
  return AlignSpace;
}

void __fastcall TAcadMLeaderStyle::set_AlignSpace(double AlignSpace/*[in]*/)
{
  GetDefaultInterface()->set_AlignSpace(AlignSpace/*[in]*/);
}

BSTR __fastcall TAcadMLeaderStyle::get_Block(void)
{
  BSTR Name = 0;
  OLECHECK(GetDefaultInterface()->get_Block((BSTR*)&Name));
  return Name;
}

void __fastcall TAcadMLeaderStyle::set_Block(BSTR Name/*[in]*/)
{
  GetDefaultInterface()->set_Block(Name/*[in]*/);
}

Autocad_tlb::IAcadAcCmColorPtr __fastcall TAcadMLeaderStyle::get_BlockColor(void)
{
  Autocad_tlb::IAcadAcCmColorPtr color;
  OLECHECK(GetDefaultInterface()->get_BlockColor(&color));
  return color;
}

void __fastcall TAcadMLeaderStyle::set_BlockColor(Autocad_tlb::IAcadAcCmColorPtr color/*[in]*/)
{
  GetDefaultInterface()->set_BlockColor(color/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadMLeaderStyle::get_EnableBlockScale(void)
{
  VARIANT_BOOL enabled;
  OLECHECK(GetDefaultInterface()->get_EnableBlockScale((VARIANT_BOOL*)&enabled));
  return enabled;
}

void __fastcall TAcadMLeaderStyle::set_EnableBlockScale(VARIANT_BOOL enabled/*[in]*/)
{
  GetDefaultInterface()->set_EnableBlockScale(enabled/*[in]*/);
}

double __fastcall TAcadMLeaderStyle::get_BlockScale(void)
{
  double ScaleFactor;
  OLECHECK(GetDefaultInterface()->get_BlockScale((double*)&ScaleFactor));
  return ScaleFactor;
}

void __fastcall TAcadMLeaderStyle::set_BlockScale(double ScaleFactor/*[in]*/)
{
  GetDefaultInterface()->set_BlockScale(ScaleFactor/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadMLeaderStyle::get_EnableBlockRotation(void)
{
  VARIANT_BOOL enabled;
  OLECHECK(GetDefaultInterface()->get_EnableBlockRotation((VARIANT_BOOL*)&enabled));
  return enabled;
}

void __fastcall TAcadMLeaderStyle::set_EnableBlockRotation(VARIANT_BOOL enabled/*[in]*/)
{
  GetDefaultInterface()->set_EnableBlockRotation(enabled/*[in]*/);
}

double __fastcall TAcadMLeaderStyle::get_BlockRotation(void)
{
  double Rotation;
  OLECHECK(GetDefaultInterface()->get_BlockRotation((double*)&Rotation));
  return Rotation;
}

void __fastcall TAcadMLeaderStyle::set_BlockRotation(double Rotation/*[in]*/)
{
  GetDefaultInterface()->set_BlockRotation(Rotation/*[in]*/);
}

Autocad_tlb::AcBlockConnectionType __fastcall TAcadMLeaderStyle::get_BlockConnectionType(void)
{
  Autocad_tlb::AcBlockConnectionType Type;
  OLECHECK(GetDefaultInterface()->get_BlockConnectionType((Autocad_tlb::AcBlockConnectionType*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_BlockConnectionType(Autocad_tlb::AcBlockConnectionType Type/*[in]*/)
{
  GetDefaultInterface()->set_BlockConnectionType(Type/*[in]*/);
}

double __fastcall TAcadMLeaderStyle::get_ScaleFactor(void)
{
  double scale;
  OLECHECK(GetDefaultInterface()->get_ScaleFactor((double*)&scale));
  return scale;
}

void __fastcall TAcadMLeaderStyle::set_ScaleFactor(double scale/*[in]*/)
{
  GetDefaultInterface()->set_ScaleFactor(scale/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadMLeaderStyle::get_OverwritePropChanged(void)
{
  VARIANT_BOOL changed;
  OLECHECK(GetDefaultInterface()->get_OverwritePropChanged((VARIANT_BOOL*)&changed));
  return changed;
}

VARIANT_BOOL __fastcall TAcadMLeaderStyle::get_Annotative(void)
{
  VARIANT_BOOL Annotative;
  OLECHECK(GetDefaultInterface()->get_Annotative((VARIANT_BOOL*)&Annotative));
  return Annotative;
}

void __fastcall TAcadMLeaderStyle::set_Annotative(VARIANT_BOOL Annotative/*[in]*/)
{
  GetDefaultInterface()->set_Annotative(Annotative/*[in]*/);
}

double __fastcall TAcadMLeaderStyle::get_BreakSize(void)
{
  double size;
  OLECHECK(GetDefaultInterface()->get_BreakSize((double*)&size));
  return size;
}

void __fastcall TAcadMLeaderStyle::set_BreakSize(double size/*[in]*/)
{
  GetDefaultInterface()->set_BreakSize(size/*[in]*/);
}

BSTR __fastcall TAcadMLeaderStyle::get_TextString(void)
{
  BSTR Text = 0;
  OLECHECK(GetDefaultInterface()->get_TextString((BSTR*)&Text));
  return Text;
}

void __fastcall TAcadMLeaderStyle::set_TextString(BSTR Text/*[in]*/)
{
  GetDefaultInterface()->set_TextString(Text/*[in]*/);
}

Autocad_tlb::AcTextAngleType __fastcall TAcadMLeaderStyle::get_TextAngleType(void)
{
  Autocad_tlb::AcTextAngleType Type;
  OLECHECK(GetDefaultInterface()->get_TextAngleType((Autocad_tlb::AcTextAngleType*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_TextAngleType(Autocad_tlb::AcTextAngleType Type/*[in]*/)
{
  GetDefaultInterface()->set_TextAngleType(Type/*[in]*/);
}

Autocad_tlb::AcTextAlignmentType __fastcall TAcadMLeaderStyle::get_TextAlignmentType(void)
{
  Autocad_tlb::AcTextAlignmentType Type;
  OLECHECK(GetDefaultInterface()->get_TextAlignmentType((Autocad_tlb::AcTextAlignmentType*)&Type));
  return Type;
}

void __fastcall TAcadMLeaderStyle::set_TextAlignmentType(Autocad_tlb::AcTextAlignmentType Type/*[in]*/)
{
  GetDefaultInterface()->set_TextAlignmentType(Type/*[in]*/);
}

IAcadDatabasePtr& TAcadDatabase::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAcadDatabase::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAcadDatabase::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAcadDatabase::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAcadDatabase::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAcadDatabase::ConnectTo(IAcadDatabasePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAcadDatabase::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AcadDatabase;
  sd.IntfIID = __uuidof(IAcadDatabase);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

VARIANT __fastcall TAcadDatabase::CopyObjects(VARIANT Objects/*[in]*/, VARIANT Owner/*[in,opt]*/, 
                                              VARIANT* IdPairs/*[in,out,opt]*/)
{
  VARIANT pNewObjects;
  OLECHECK(GetDefaultInterface()->CopyObjects(Objects, Owner, IdPairs, (VARIANT*)&pNewObjects));
  return pNewObjects;
}

LPDISPATCH __fastcall TAcadDatabase::HandleToObject(BSTR Handle/*[in]*/)
{
  LPDISPATCH pObj;
  OLECHECK(GetDefaultInterface()->HandleToObject(Handle, (LPDISPATCH*)&pObj));
  return pObj;
}

LPDISPATCH __fastcall TAcadDatabase::ObjectIdToObject(Autocad_tlb::LONG_PTR ObjectID/*[in]*/)
{
  LPDISPATCH pObj;
  OLECHECK(GetDefaultInterface()->ObjectIdToObject(ObjectID, (LPDISPATCH*)&pObj));
  return pObj;
}

Autocad_tlb::IAcadModelSpacePtr __fastcall TAcadDatabase::get_ModelSpace(void)
{
  Autocad_tlb::IAcadModelSpacePtr pMSpace;
  OLECHECK(GetDefaultInterface()->get_ModelSpace(&pMSpace));
  return pMSpace;
}

Autocad_tlb::IAcadPaperSpacePtr __fastcall TAcadDatabase::get_PaperSpace(void)
{
  Autocad_tlb::IAcadPaperSpacePtr pPSpace;
  OLECHECK(GetDefaultInterface()->get_PaperSpace(&pPSpace));
  return pPSpace;
}

Autocad_tlb::IAcadBlocksPtr __fastcall TAcadDatabase::get_Blocks(void)
{
  Autocad_tlb::IAcadBlocksPtr pBlocks;
  OLECHECK(GetDefaultInterface()->get_Blocks(&pBlocks));
  return pBlocks;
}

Autocad_tlb::IAcadGroupsPtr __fastcall TAcadDatabase::get_Groups(void)
{
  Autocad_tlb::IAcadGroupsPtr pGroups;
  OLECHECK(GetDefaultInterface()->get_Groups(&pGroups));
  return pGroups;
}

Autocad_tlb::IAcadDimStylesPtr __fastcall TAcadDatabase::get_DimStyles(void)
{
  Autocad_tlb::IAcadDimStylesPtr pDimStyles;
  OLECHECK(GetDefaultInterface()->get_DimStyles(&pDimStyles));
  return pDimStyles;
}

Autocad_tlb::IAcadLayersPtr __fastcall TAcadDatabase::get_Layers(void)
{
  Autocad_tlb::IAcadLayersPtr pLayers;
  OLECHECK(GetDefaultInterface()->get_Layers(&pLayers));
  return pLayers;
}

Autocad_tlb::IAcadLineTypesPtr __fastcall TAcadDatabase::get_Linetypes(void)
{
  Autocad_tlb::IAcadLineTypesPtr pLinetypes;
  OLECHECK(GetDefaultInterface()->get_Linetypes(&pLinetypes));
  return pLinetypes;
}

Autocad_tlb::IAcadDictionariesPtr __fastcall TAcadDatabase::get_Dictionaries(void)
{
  Autocad_tlb::IAcadDictionariesPtr pDictionaries;
  OLECHECK(GetDefaultInterface()->get_Dictionaries(&pDictionaries));
  return pDictionaries;
}

Autocad_tlb::IAcadRegisteredApplicationsPtr __fastcall TAcadDatabase::get_RegisteredApplications(void)
{
  Autocad_tlb::IAcadRegisteredApplicationsPtr pRegApps;
  OLECHECK(GetDefaultInterface()->get_RegisteredApplications(&pRegApps));
  return pRegApps;
}

Autocad_tlb::IAcadTextStylesPtr __fastcall TAcadDatabase::get_TextStyles(void)
{
  Autocad_tlb::IAcadTextStylesPtr pTextStyles;
  OLECHECK(GetDefaultInterface()->get_TextStyles(&pTextStyles));
  return pTextStyles;
}

Autocad_tlb::IAcadUCSsPtr __fastcall TAcadDatabase::get_UserCoordinateSystems(void)
{
  Autocad_tlb::IAcadUCSsPtr pUCSs;
  OLECHECK(GetDefaultInterface()->get_UserCoordinateSystems(&pUCSs));
  return pUCSs;
}

Autocad_tlb::IAcadViewsPtr __fastcall TAcadDatabase::get_Views(void)
{
  Autocad_tlb::IAcadViewsPtr pViews;
  OLECHECK(GetDefaultInterface()->get_Views(&pViews));
  return pViews;
}

Autocad_tlb::IAcadViewportsPtr __fastcall TAcadDatabase::get_Viewports(void)
{
  Autocad_tlb::IAcadViewportsPtr pViewports;
  OLECHECK(GetDefaultInterface()->get_Viewports(&pViewports));
  return pViewports;
}

double __fastcall TAcadDatabase::get_ElevationModelSpace(void)
{
  double Elevation;
  OLECHECK(GetDefaultInterface()->get_ElevationModelSpace((double*)&Elevation));
  return Elevation;
}

void __fastcall TAcadDatabase::set_ElevationModelSpace(double Elevation/*[in]*/)
{
  GetDefaultInterface()->set_ElevationModelSpace(Elevation/*[in]*/);
}

double __fastcall TAcadDatabase::get_ElevationPaperSpace(void)
{
  double Elevation;
  OLECHECK(GetDefaultInterface()->get_ElevationPaperSpace((double*)&Elevation));
  return Elevation;
}

void __fastcall TAcadDatabase::set_ElevationPaperSpace(double Elevation/*[in]*/)
{
  GetDefaultInterface()->set_ElevationPaperSpace(Elevation/*[in]*/);
}

VARIANT __fastcall TAcadDatabase::get_Limits(void)
{
  VARIANT Limits;
  OLECHECK(GetDefaultInterface()->get_Limits((VARIANT*)&Limits));
  return Limits;
}

void __fastcall TAcadDatabase::set_Limits(VARIANT Limits/*[in]*/)
{
  GetDefaultInterface()->set_Limits(Limits/*[in]*/);
}

Autocad_tlb::IAcadLayoutsPtr __fastcall TAcadDatabase::get_Layouts(void)
{
  Autocad_tlb::IAcadLayoutsPtr pLayouts;
  OLECHECK(GetDefaultInterface()->get_Layouts(&pLayouts));
  return pLayouts;
}

Autocad_tlb::IAcadPlotConfigurationsPtr __fastcall TAcadDatabase::get_PlotConfigurations(void)
{
  Autocad_tlb::IAcadPlotConfigurationsPtr pPlotConfigs;
  OLECHECK(GetDefaultInterface()->get_PlotConfigurations(&pPlotConfigs));
  return pPlotConfigs;
}

Autocad_tlb::IAcadDatabasePreferencesPtr __fastcall TAcadDatabase::get_Preferences(void)
{
  Autocad_tlb::IAcadDatabasePreferencesPtr pPref;
  OLECHECK(GetDefaultInterface()->get_Preferences(&pPref));
  return pPref;
}

Autocad_tlb::IAcadFileDependenciesPtr __fastcall TAcadDatabase::get_FileDependencies(void)
{
  Autocad_tlb::IAcadFileDependenciesPtr pFDM;
  OLECHECK(GetDefaultInterface()->get_FileDependencies(&pFDM));
  return pFDM;
}

Autocad_tlb::IAcadSummaryInfoPtr __fastcall TAcadDatabase::get_SummaryInfo(void)
{
  Autocad_tlb::IAcadSummaryInfoPtr pSummaryInfo;
  OLECHECK(GetDefaultInterface()->get_SummaryInfo(&pSummaryInfo));
  return pSummaryInfo;
}

Autocad_tlb::IAcadSectionManagerPtr __fastcall TAcadDatabase::get_SectionManager(void)
{
  Autocad_tlb::IAcadSectionManagerPtr pSecMgr;
  OLECHECK(GetDefaultInterface()->get_SectionManager(&pSecMgr));
  return pSecMgr;
}

Autocad_tlb::IAcadMaterialsPtr __fastcall TAcadDatabase::get_Materials(void)
{
  Autocad_tlb::IAcadMaterialsPtr pMaterials;
  OLECHECK(GetDefaultInterface()->get_Materials(&pMaterials));
  return pMaterials;
}

IAcadSecurityParamsPtr& TAcadSecurityParams::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAcadSecurityParams::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAcadSecurityParams::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAcadSecurityParams::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAcadSecurityParams::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAcadSecurityParams::ConnectTo(IAcadSecurityParamsPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAcadSecurityParams::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AcadSecurityParams;
  sd.IntfIID = __uuidof(IAcadSecurityParams);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TAcadSecurityParams::set_Action(long pOperations/*[in]*/)
{
  GetDefaultInterface()->set_Action(pOperations/*[in]*/);
}

long __fastcall TAcadSecurityParams::get_Action(void)
{
  long pOperations;
  OLECHECK(GetDefaultInterface()->get_Action((long*)&pOperations));
  return pOperations;
}

void __fastcall TAcadSecurityParams::set_Password(BSTR pSecret/*[in]*/)
{
  GetDefaultInterface()->set_Password(pSecret/*[in]*/);
}

BSTR __fastcall TAcadSecurityParams::get_Password(void)
{
  BSTR pSecret = 0;
  OLECHECK(GetDefaultInterface()->get_Password((BSTR*)&pSecret));
  return pSecret;
}

void __fastcall TAcadSecurityParams::set_ProviderType(long pProvType/*[in]*/)
{
  GetDefaultInterface()->set_ProviderType(pProvType/*[in]*/);
}

long __fastcall TAcadSecurityParams::get_ProviderType(void)
{
  long pProvType;
  OLECHECK(GetDefaultInterface()->get_ProviderType((long*)&pProvType));
  return pProvType;
}

void __fastcall TAcadSecurityParams::set_ProviderName(BSTR pProvName/*[in]*/)
{
  GetDefaultInterface()->set_ProviderName(pProvName/*[in]*/);
}

BSTR __fastcall TAcadSecurityParams::get_ProviderName(void)
{
  BSTR pProvName = 0;
  OLECHECK(GetDefaultInterface()->get_ProviderName((BSTR*)&pProvName));
  return pProvName;
}

void __fastcall TAcadSecurityParams::set_Algorithm(long pAlgId/*[in]*/)
{
  GetDefaultInterface()->set_Algorithm(pAlgId/*[in]*/);
}

long __fastcall TAcadSecurityParams::get_Algorithm(void)
{
  long pAlgId;
  OLECHECK(GetDefaultInterface()->get_Algorithm((long*)&pAlgId));
  return pAlgId;
}

void __fastcall TAcadSecurityParams::set_KeyLength(long pKeyLen/*[in]*/)
{
  GetDefaultInterface()->set_KeyLength(pKeyLen/*[in]*/);
}

long __fastcall TAcadSecurityParams::get_KeyLength(void)
{
  long pKeyLen;
  OLECHECK(GetDefaultInterface()->get_KeyLength((long*)&pKeyLen));
  return pKeyLen;
}

void __fastcall TAcadSecurityParams::set_Subject(BSTR pCertSubject/*[in]*/)
{
  GetDefaultInterface()->set_Subject(pCertSubject/*[in]*/);
}

BSTR __fastcall TAcadSecurityParams::get_Subject(void)
{
  BSTR pCertSubject = 0;
  OLECHECK(GetDefaultInterface()->get_Subject((BSTR*)&pCertSubject));
  return pCertSubject;
}

void __fastcall TAcadSecurityParams::set_Issuer(BSTR pCertIssuer/*[in]*/)
{
  GetDefaultInterface()->set_Issuer(pCertIssuer/*[in]*/);
}

BSTR __fastcall TAcadSecurityParams::get_Issuer(void)
{
  BSTR pCertIssuer = 0;
  OLECHECK(GetDefaultInterface()->get_Issuer((BSTR*)&pCertIssuer));
  return pCertIssuer;
}

void __fastcall TAcadSecurityParams::set_SerialNumber(BSTR pSerialNum/*[in]*/)
{
  GetDefaultInterface()->set_SerialNumber(pSerialNum/*[in]*/);
}

BSTR __fastcall TAcadSecurityParams::get_SerialNumber(void)
{
  BSTR pSerialNum = 0;
  OLECHECK(GetDefaultInterface()->get_SerialNumber((BSTR*)&pSerialNum));
  return pSerialNum;
}

void __fastcall TAcadSecurityParams::set_Comment(BSTR pText/*[in]*/)
{
  GetDefaultInterface()->set_Comment(pText/*[in]*/);
}

BSTR __fastcall TAcadSecurityParams::get_Comment(void)
{
  BSTR pText = 0;
  OLECHECK(GetDefaultInterface()->get_Comment((BSTR*)&pText));
  return pText;
}

void __fastcall TAcadSecurityParams::set_TimeServer(BSTR pTimeServerName/*[in]*/)
{
  GetDefaultInterface()->set_TimeServer(pTimeServerName/*[in]*/);
}

BSTR __fastcall TAcadSecurityParams::get_TimeServer(void)
{
  BSTR pTimeServerName = 0;
  OLECHECK(GetDefaultInterface()->get_TimeServer((BSTR*)&pTimeServerName));
  return pTimeServerName;
}

IAcadLayerStateManagerPtr& TAcadLayerStateManager::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAcadLayerStateManager::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAcadLayerStateManager::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAcadLayerStateManager::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAcadLayerStateManager::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAcadLayerStateManager::ConnectTo(IAcadLayerStateManagerPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAcadLayerStateManager::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AcadLayerStateManager;
  sd.IntfIID = __uuidof(IAcadLayerStateManager);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TAcadLayerStateManager::SetDatabase(Autocad_tlb::IAcadDatabase* iHostDb/*[in]*/)
{
  GetDefaultInterface()->SetDatabase(iHostDb/*[in]*/);
}

void __fastcall TAcadLayerStateManager::Save(BSTR bsName/*[in]*/, 
                                             Autocad_tlb::AcLayerStateMask eMask/*[in]*/)
{
  GetDefaultInterface()->Save(bsName/*[in]*/, eMask/*[in]*/);
}

void __fastcall TAcadLayerStateManager::Restore(BSTR bsName/*[in]*/)
{
  GetDefaultInterface()->Restore(bsName/*[in]*/);
}

void __fastcall TAcadLayerStateManager::Delete(BSTR bsName/*[in]*/)
{
  GetDefaultInterface()->Delete(bsName/*[in]*/);
}

void __fastcall TAcadLayerStateManager::Rename(BSTR bsName/*[in]*/, BSTR bsNewName/*[in]*/)
{
  GetDefaultInterface()->Rename(bsName/*[in]*/, bsNewName/*[in]*/);
}

void __fastcall TAcadLayerStateManager::Import(BSTR bsFilename/*[in]*/)
{
  GetDefaultInterface()->Import(bsFilename/*[in]*/);
}

void __fastcall TAcadLayerStateManager::Export(BSTR bsName/*[in]*/, BSTR bsFilename/*[in]*/)
{
  GetDefaultInterface()->Export(bsName/*[in]*/, bsFilename/*[in]*/);
}

void __fastcall TAcadLayerStateManager::set_Mask(BSTR bsName/*[in]*/, 
                                                 Autocad_tlb::AcLayerStateMask eMask/*[in]*/)
{
  GetDefaultInterface()->set_Mask(bsName/*[in]*/, eMask/*[in]*/);
}

Autocad_tlb::AcLayerStateMask __fastcall TAcadLayerStateManager::get_Mask(BSTR bsName/*[in]*/)
{
  Autocad_tlb::AcLayerStateMask eMask;
  OLECHECK(GetDefaultInterface()->get_Mask(bsName, (Autocad_tlb::AcLayerStateMask*)&eMask));
  return eMask;
}

IAcadDocumentPtr& TAcadDocument::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAcadDocument::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAcadDocument::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAcadDocument::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAcadDocument::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAcadDocument::ConnectTo(IAcadDocumentPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAcadDocument::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AcadDocument;
  sd.IntfIID = __uuidof(IAcadDocument);
  sd.EventIID= __uuidof(_DAcadDocumentEvents);
  ServerData = &sd;
}

void __fastcall TAcadDocument::InvokeEvent(int id, Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnBeginSave) {
        (OnBeginSave)(this, params[0].bstrVal);
      }
      break;
      }
    case 2: {
      if (OnEndSave) {
        (OnEndSave)(this, params[0].bstrVal);
      }
      break;
      }
    case 6: {
      if (OnBeginCommand) {
        (OnBeginCommand)(this, params[0].bstrVal);
      }
      break;
      }
    case 7: {
      if (OnEndCommand) {
        (OnEndCommand)(this, params[0].bstrVal);
      }
      break;
      }
    case 8: {
      if (OnBeginLisp) {
        (OnBeginLisp)(this, params[0].bstrVal);
      }
      break;
      }
    case 9: {
      if (OnEndLisp) {
        (OnEndLisp)(this);
      }
      break;
      }
    case 10: {
      if (OnLispCancelled) {
        (OnLispCancelled)(this);
      }
      break;
      }
    case 11: {
      if (OnSelectionChanged) {
        (OnSelectionChanged)(this);
      }
      break;
      }
    case 12: {
      if (OnActivate) {
        (OnActivate)(this);
      }
      break;
      }
    case 13: {
      if (OnDeactivate) {
        (OnDeactivate)(this);
      }
      break;
      }
    case 14: {
      if (OnBeginRightClick) {
        (OnBeginRightClick)(this, params[0]);
      }
      break;
      }
    case 15: {
      if (OnBeginShortcutMenuDefault) {
        (OnBeginShortcutMenuDefault)(this, (Autocad_tlb::IAcadPopupMenu**)(LPDISPATCH*)(params[0].ppdispVal));
      }
      break;
      }
    case 16: {
      if (OnBeginShortcutMenuEdit) {
        (OnBeginShortcutMenuEdit)(this, (Autocad_tlb::IAcadPopupMenu**)(LPDISPATCH*)(params[0].ppdispVal), (Autocad_tlb::IAcadSelectionSet**)(LPDISPATCH*)(params[1].ppdispVal));
      }
      break;
      }
    case 17: {
      if (OnBeginShortcutMenuCommand) {
        (OnBeginShortcutMenuCommand)(this, (Autocad_tlb::IAcadPopupMenu**)(LPDISPATCH*)(params[0].ppdispVal), params[1].bstrVal);
      }
      break;
      }
    case 18: {
      if (OnBeginShortcutMenuGrip) {
        (OnBeginShortcutMenuGrip)(this, (Autocad_tlb::IAcadPopupMenu**)(LPDISPATCH*)(params[0].ppdispVal));
      }
      break;
      }
    case 19: {
      if (OnBeginShortcutMenuOsnap) {
        (OnBeginShortcutMenuOsnap)(this, (Autocad_tlb::IAcadPopupMenu**)(LPDISPATCH*)(params[0].ppdispVal));
      }
      break;
      }
    case 30: {
      if (OnEndShortcutMenu) {
        (OnEndShortcutMenu)(this, (Autocad_tlb::IAcadPopupMenu**)(LPDISPATCH*)(params[0].ppdispVal));
      }
      break;
      }
    case 20: {
      if (OnBeginDoubleClick) {
        (OnBeginDoubleClick)(this, params[0]);
      }
      break;
      }
    case 21: {
      if (OnObjectAdded) {
        (OnObjectAdded)(this, params[0].pdispVal);
      }
      break;
      }
    case 22: {
      if (OnObjectErased) {
        (OnObjectErased)(this, params[0]);
      }
      break;
      }
    case 23: {
      if (OnObjectModified) {
        (OnObjectModified)(this, params[0].pdispVal);
      }
      break;
      }
    case 24: {
      if (OnBeginPlot) {
        (OnBeginPlot)(this, params[0].bstrVal);
      }
      break;
      }
    case 25: {
      if (OnEndPlot) {
        (OnEndPlot)(this, params[0].bstrVal);
      }
      break;
      }
    case 29: {
      if (OnWindowMovedOrResized) {
        (OnWindowMovedOrResized)(this, params[0], params[1]);
      }
      break;
      }
    case 31: {
      if (OnLayoutSwitched) {
        (OnLayoutSwitched)(this, params[0].bstrVal);
      }
      break;
      }
    case 32: {
      if (OnWindowChanged) {
        (OnWindowChanged)(this, (Autocad_tlb::AcWindowState)(int)params[0]);
      }
      break;
      }
    case 33: {
      if (OnBeginClose) {
        (OnBeginClose)(this);
      }
      break;
      }
    case 34: {
      if (OnBeginDocClose) {
        (OnBeginDocClose)(this, params[0]);
      }
      break;
      }
    default:
      break;
  }
}

VARIANT __fastcall TAcadDocument::CopyObjects(VARIANT Objects/*[in]*/, VARIANT Owner/*[in,opt]*/, 
                                              VARIANT* IdPairs/*[in,out,opt]*/)
{
  VARIANT pNewObjects;
  OLECHECK(GetDefaultInterface()->CopyObjects(Objects, Owner, IdPairs, (VARIANT*)&pNewObjects));
  return pNewObjects;
}

LPDISPATCH __fastcall TAcadDocument::HandleToObject(BSTR Handle/*[in]*/)
{
  LPDISPATCH pObj;
  OLECHECK(GetDefaultInterface()->HandleToObject(Handle, (LPDISPATCH*)&pObj));
  return pObj;
}

LPDISPATCH __fastcall TAcadDocument::ObjectIdToObject(Autocad_tlb::LONG_PTR ObjectID/*[in]*/)
{
  LPDISPATCH pObj;
  OLECHECK(GetDefaultInterface()->ObjectIdToObject(ObjectID, (LPDISPATCH*)&pObj));
  return pObj;
}

Autocad_tlb::IAcadDocument* __fastcall TAcadDocument::Open(BSTR FullName/*[in]*/, 
                                                           VARIANT Password/*[in,opt]*/)
{
  Autocad_tlb::IAcadDocument* pDocObj = 0;
  OLECHECK(GetDefaultInterface()->Open(FullName, Password, (Autocad_tlb::IAcadDocument**)&pDocObj));
  return pDocObj;
}

void __fastcall TAcadDocument::AuditInfo(VARIANT_BOOL FixErr/*[in]*/)
{
  GetDefaultInterface()->AuditInfo(FixErr/*[in]*/);
}

LPDISPATCH __fastcall TAcadDocument::Import(BSTR FileName/*[in]*/, VARIANT InsertionPoint/*[in]*/, 
                                            double ScaleFactor/*[in]*/)
{
  LPDISPATCH pObj;
  OLECHECK(GetDefaultInterface()->Import(FileName, InsertionPoint, ScaleFactor, (LPDISPATCH*)&pObj));
  return pObj;
}

void __fastcall TAcadDocument::Export(BSTR FileName/*[in]*/, BSTR Extension/*[in]*/, 
                                      Autocad_tlb::IAcadSelectionSet* SelectionSet/*[in]*/)
{
  GetDefaultInterface()->Export(FileName/*[in]*/, Extension/*[in]*/, SelectionSet/*[in]*/);
}

Autocad_tlb::IAcadDocument* __fastcall TAcadDocument::New(BSTR TemplateFileName/*[in]*/)
{
  Autocad_tlb::IAcadDocument* pDocObj = 0;
  OLECHECK(GetDefaultInterface()->New(TemplateFileName, (Autocad_tlb::IAcadDocument**)&pDocObj));
  return pDocObj;
}

void __fastcall TAcadDocument::Save(void)
{
  GetDefaultInterface()->Save();
}

void __fastcall TAcadDocument::SaveAs(BSTR FullFileName/*[in]*/, VARIANT SaveAsType/*[in,opt]*/, 
                                      VARIANT vSecurityParams/*[in,opt]*/)
{
  GetDefaultInterface()->SaveAs(FullFileName/*[in]*/, SaveAsType/*[in,opt]*/, 
                                vSecurityParams/*[in,opt]*/);
}

void __fastcall TAcadDocument::Wblock(BSTR FileName/*[in]*/, 
                                      Autocad_tlb::IAcadSelectionSet* SelectionSet/*[in]*/)
{
  GetDefaultInterface()->Wblock(FileName/*[in]*/, SelectionSet/*[in]*/);
}

void __fastcall TAcadDocument::PurgeAll(void)
{
  GetDefaultInterface()->PurgeAll();
}

VARIANT __fastcall TAcadDocument::GetVariable(BSTR Name/*[in]*/)
{
  VARIANT Value;
  OLECHECK(GetDefaultInterface()->GetVariable(Name, (VARIANT*)&Value));
  return Value;
}

void __fastcall TAcadDocument::SetVariable(BSTR Name/*[in]*/, VARIANT Value/*[in]*/)
{
  GetDefaultInterface()->SetVariable(Name/*[in]*/, Value/*[in]*/);
}

void __fastcall TAcadDocument::LoadShapeFile(BSTR FullName/*[in]*/)
{
  GetDefaultInterface()->LoadShapeFile(FullName/*[in]*/);
}

void __fastcall TAcadDocument::Regen(Autocad_tlb::AcRegenType WhichViewports/*[in]*/)
{
  GetDefaultInterface()->Regen(WhichViewports/*[in]*/);
}

void __fastcall TAcadDocument::Activate(void)
{
  GetDefaultInterface()->Activate();
}

void __fastcall TAcadDocument::Close(VARIANT SaveChanges/*[in,opt]*/, VARIANT FileName/*[in,opt]*/)
{
  GetDefaultInterface()->Close(SaveChanges/*[in,opt]*/, FileName/*[in,opt]*/);
}

void __fastcall TAcadDocument::SendCommand(BSTR Command/*[in]*/)
{
  GetDefaultInterface()->SendCommand(Command/*[in]*/);
}

void __fastcall TAcadDocument::StartUndoMark(void)
{
  GetDefaultInterface()->StartUndoMark();
}

void __fastcall TAcadDocument::EndUndoMark(void)
{
  GetDefaultInterface()->EndUndoMark();
}

Autocad_tlb::IAcadModelSpacePtr __fastcall TAcadDocument::get_ModelSpace(void)
{
  Autocad_tlb::IAcadModelSpacePtr pMSpace;
  OLECHECK(GetDefaultInterface()->get_ModelSpace(&pMSpace));
  return pMSpace;
}

Autocad_tlb::IAcadPaperSpacePtr __fastcall TAcadDocument::get_PaperSpace(void)
{
  Autocad_tlb::IAcadPaperSpacePtr pPSpace;
  OLECHECK(GetDefaultInterface()->get_PaperSpace(&pPSpace));
  return pPSpace;
}

Autocad_tlb::IAcadBlocksPtr __fastcall TAcadDocument::get_Blocks(void)
{
  Autocad_tlb::IAcadBlocksPtr pBlocks;
  OLECHECK(GetDefaultInterface()->get_Blocks(&pBlocks));
  return pBlocks;
}

Autocad_tlb::IAcadGroupsPtr __fastcall TAcadDocument::get_Groups(void)
{
  Autocad_tlb::IAcadGroupsPtr pGroups;
  OLECHECK(GetDefaultInterface()->get_Groups(&pGroups));
  return pGroups;
}

Autocad_tlb::IAcadDimStylesPtr __fastcall TAcadDocument::get_DimStyles(void)
{
  Autocad_tlb::IAcadDimStylesPtr pDimStyles;
  OLECHECK(GetDefaultInterface()->get_DimStyles(&pDimStyles));
  return pDimStyles;
}

Autocad_tlb::IAcadLayersPtr __fastcall TAcadDocument::get_Layers(void)
{
  Autocad_tlb::IAcadLayersPtr pLayers;
  OLECHECK(GetDefaultInterface()->get_Layers(&pLayers));
  return pLayers;
}

Autocad_tlb::IAcadLineTypesPtr __fastcall TAcadDocument::get_Linetypes(void)
{
  Autocad_tlb::IAcadLineTypesPtr pLinetypes;
  OLECHECK(GetDefaultInterface()->get_Linetypes(&pLinetypes));
  return pLinetypes;
}

Autocad_tlb::IAcadDictionariesPtr __fastcall TAcadDocument::get_Dictionaries(void)
{
  Autocad_tlb::IAcadDictionariesPtr pDictionaries;
  OLECHECK(GetDefaultInterface()->get_Dictionaries(&pDictionaries));
  return pDictionaries;
}

Autocad_tlb::IAcadRegisteredApplicationsPtr __fastcall TAcadDocument::get_RegisteredApplications(void)
{
  Autocad_tlb::IAcadRegisteredApplicationsPtr pRegApps;
  OLECHECK(GetDefaultInterface()->get_RegisteredApplications(&pRegApps));
  return pRegApps;
}

Autocad_tlb::IAcadTextStylesPtr __fastcall TAcadDocument::get_TextStyles(void)
{
  Autocad_tlb::IAcadTextStylesPtr pTextStyles;
  OLECHECK(GetDefaultInterface()->get_TextStyles(&pTextStyles));
  return pTextStyles;
}

Autocad_tlb::IAcadUCSsPtr __fastcall TAcadDocument::get_UserCoordinateSystems(void)
{
  Autocad_tlb::IAcadUCSsPtr pUCSs;
  OLECHECK(GetDefaultInterface()->get_UserCoordinateSystems(&pUCSs));
  return pUCSs;
}

Autocad_tlb::IAcadViewsPtr __fastcall TAcadDocument::get_Views(void)
{
  Autocad_tlb::IAcadViewsPtr pViews;
  OLECHECK(GetDefaultInterface()->get_Views(&pViews));
  return pViews;
}

Autocad_tlb::IAcadViewportsPtr __fastcall TAcadDocument::get_Viewports(void)
{
  Autocad_tlb::IAcadViewportsPtr pViewports;
  OLECHECK(GetDefaultInterface()->get_Viewports(&pViewports));
  return pViewports;
}

double __fastcall TAcadDocument::get_ElevationModelSpace(void)
{
  double Elevation;
  OLECHECK(GetDefaultInterface()->get_ElevationModelSpace((double*)&Elevation));
  return Elevation;
}

void __fastcall TAcadDocument::set_ElevationModelSpace(double Elevation/*[in]*/)
{
  GetDefaultInterface()->set_ElevationModelSpace(Elevation/*[in]*/);
}

double __fastcall TAcadDocument::get_ElevationPaperSpace(void)
{
  double Elevation;
  OLECHECK(GetDefaultInterface()->get_ElevationPaperSpace((double*)&Elevation));
  return Elevation;
}

void __fastcall TAcadDocument::set_ElevationPaperSpace(double Elevation/*[in]*/)
{
  GetDefaultInterface()->set_ElevationPaperSpace(Elevation/*[in]*/);
}

VARIANT __fastcall TAcadDocument::get_Limits(void)
{
  VARIANT Limits;
  OLECHECK(GetDefaultInterface()->get_Limits((VARIANT*)&Limits));
  return Limits;
}

void __fastcall TAcadDocument::set_Limits(VARIANT Limits/*[in]*/)
{
  GetDefaultInterface()->set_Limits(Limits/*[in]*/);
}

Autocad_tlb::IAcadLayoutsPtr __fastcall TAcadDocument::get_Layouts(void)
{
  Autocad_tlb::IAcadLayoutsPtr pLayouts;
  OLECHECK(GetDefaultInterface()->get_Layouts(&pLayouts));
  return pLayouts;
}

Autocad_tlb::IAcadPlotConfigurationsPtr __fastcall TAcadDocument::get_PlotConfigurations(void)
{
  Autocad_tlb::IAcadPlotConfigurationsPtr pPlotConfigs;
  OLECHECK(GetDefaultInterface()->get_PlotConfigurations(&pPlotConfigs));
  return pPlotConfigs;
}

Autocad_tlb::IAcadDatabasePreferencesPtr __fastcall TAcadDocument::get_Preferences(void)
{
  Autocad_tlb::IAcadDatabasePreferencesPtr pPref;
  OLECHECK(GetDefaultInterface()->get_Preferences(&pPref));
  return pPref;
}

Autocad_tlb::IAcadFileDependenciesPtr __fastcall TAcadDocument::get_FileDependencies(void)
{
  Autocad_tlb::IAcadFileDependenciesPtr pFDM;
  OLECHECK(GetDefaultInterface()->get_FileDependencies(&pFDM));
  return pFDM;
}

Autocad_tlb::IAcadSummaryInfoPtr __fastcall TAcadDocument::get_SummaryInfo(void)
{
  Autocad_tlb::IAcadSummaryInfoPtr pSummaryInfo;
  OLECHECK(GetDefaultInterface()->get_SummaryInfo(&pSummaryInfo));
  return pSummaryInfo;
}

Autocad_tlb::IAcadSectionManagerPtr __fastcall TAcadDocument::get_SectionManager(void)
{
  Autocad_tlb::IAcadSectionManagerPtr pSecMgr;
  OLECHECK(GetDefaultInterface()->get_SectionManager(&pSecMgr));
  return pSecMgr;
}

Autocad_tlb::IAcadMaterialsPtr __fastcall TAcadDocument::get_Materials(void)
{
  Autocad_tlb::IAcadMaterialsPtr pMaterials;
  OLECHECK(GetDefaultInterface()->get_Materials(&pMaterials));
  return pMaterials;
}

Autocad_tlb::IAcadPlotPtr __fastcall TAcadDocument::get_Plot(void)
{
  Autocad_tlb::IAcadPlotPtr pPlot;
  OLECHECK(GetDefaultInterface()->get_Plot(&pPlot));
  return pPlot;
}

Autocad_tlb::IAcadLayerPtr __fastcall TAcadDocument::get_ActiveLayer(void)
{
  Autocad_tlb::IAcadLayerPtr pActLayer;
  OLECHECK(GetDefaultInterface()->get_ActiveLayer(&pActLayer));
  return pActLayer;
}

void __fastcall TAcadDocument::set_ActiveLayer(Autocad_tlb::IAcadLayerPtr pActLayer/*[in]*/)
{
  GetDefaultInterface()->set_ActiveLayer(pActLayer/*[in]*/);
}

Autocad_tlb::IAcadLineTypePtr __fastcall TAcadDocument::get_ActiveLinetype(void)
{
  Autocad_tlb::IAcadLineTypePtr pActLinetype;
  OLECHECK(GetDefaultInterface()->get_ActiveLinetype(&pActLinetype));
  return pActLinetype;
}

void __fastcall TAcadDocument::set_ActiveLinetype(Autocad_tlb::IAcadLineTypePtr pActLinetype/*[in]*/)
{
  GetDefaultInterface()->set_ActiveLinetype(pActLinetype/*[in]*/);
}

Autocad_tlb::IAcadDimStylePtr __fastcall TAcadDocument::get_ActiveDimStyle(void)
{
  Autocad_tlb::IAcadDimStylePtr pActDimStyle;
  OLECHECK(GetDefaultInterface()->get_ActiveDimStyle(&pActDimStyle));
  return pActDimStyle;
}

void __fastcall TAcadDocument::set_ActiveDimStyle(Autocad_tlb::IAcadDimStylePtr pActDimStyle/*[in]*/)
{
  GetDefaultInterface()->set_ActiveDimStyle(pActDimStyle/*[in]*/);
}

Autocad_tlb::IAcadTextStylePtr __fastcall TAcadDocument::get_ActiveTextStyle(void)
{
  Autocad_tlb::IAcadTextStylePtr pActTextStyle;
  OLECHECK(GetDefaultInterface()->get_ActiveTextStyle(&pActTextStyle));
  return pActTextStyle;
}

void __fastcall TAcadDocument::set_ActiveTextStyle(Autocad_tlb::IAcadTextStylePtr pActTextStyle/*[in]*/)
{
  GetDefaultInterface()->set_ActiveTextStyle(pActTextStyle/*[in]*/);
}

Autocad_tlb::IAcadUCSPtr __fastcall TAcadDocument::get_ActiveUCS(void)
{
  Autocad_tlb::IAcadUCSPtr pActUCS;
  OLECHECK(GetDefaultInterface()->get_ActiveUCS(&pActUCS));
  return pActUCS;
}

void __fastcall TAcadDocument::set_ActiveUCS(Autocad_tlb::IAcadUCSPtr pActUCS/*[in]*/)
{
  GetDefaultInterface()->set_ActiveUCS(pActUCS/*[in]*/);
}

Autocad_tlb::IAcadViewportPtr __fastcall TAcadDocument::get_ActiveViewport(void)
{
  Autocad_tlb::IAcadViewportPtr pActView;
  OLECHECK(GetDefaultInterface()->get_ActiveViewport(&pActView));
  return pActView;
}

void __fastcall TAcadDocument::set_ActiveViewport(Autocad_tlb::IAcadViewportPtr pActView/*[in]*/)
{
  GetDefaultInterface()->set_ActiveViewport(pActView/*[in]*/);
}

Autocad_tlb::IAcadPViewportPtr __fastcall TAcadDocument::get_ActivePViewport(void)
{
  Autocad_tlb::IAcadPViewportPtr pActView;
  OLECHECK(GetDefaultInterface()->get_ActivePViewport(&pActView));
  return pActView;
}

void __fastcall TAcadDocument::set_ActivePViewport(Autocad_tlb::IAcadPViewportPtr pActView/*[in]*/)
{
  GetDefaultInterface()->set_ActivePViewport(pActView/*[in]*/);
}

Autocad_tlb::AcActiveSpace __fastcall TAcadDocument::get_ActiveSpace(void)
{
  Autocad_tlb::AcActiveSpace ActSpace;
  OLECHECK(GetDefaultInterface()->get_ActiveSpace((Autocad_tlb::AcActiveSpace*)&ActSpace));
  return ActSpace;
}

void __fastcall TAcadDocument::set_ActiveSpace(Autocad_tlb::AcActiveSpace ActSpace/*[in]*/)
{
  GetDefaultInterface()->set_ActiveSpace(ActSpace/*[in]*/);
}

Autocad_tlb::IAcadSelectionSetsPtr __fastcall TAcadDocument::get_SelectionSets(void)
{
  Autocad_tlb::IAcadSelectionSetsPtr pSelSets;
  OLECHECK(GetDefaultInterface()->get_SelectionSets(&pSelSets));
  return pSelSets;
}

Autocad_tlb::IAcadSelectionSetPtr __fastcall TAcadDocument::get_ActiveSelectionSet(void)
{
  Autocad_tlb::IAcadSelectionSetPtr pSelSet;
  OLECHECK(GetDefaultInterface()->get_ActiveSelectionSet(&pSelSet));
  return pSelSet;
}

BSTR __fastcall TAcadDocument::get_FullName(void)
{
  BSTR FullName = 0;
  OLECHECK(GetDefaultInterface()->get_FullName((BSTR*)&FullName));
  return FullName;
}

BSTR __fastcall TAcadDocument::get_Name(void)
{
  BSTR Name = 0;
  OLECHECK(GetDefaultInterface()->get_Name((BSTR*)&Name));
  return Name;
}

BSTR __fastcall TAcadDocument::get_Path(void)
{
  BSTR Path = 0;
  OLECHECK(GetDefaultInterface()->get_Path((BSTR*)&Path));
  return Path;
}

VARIANT_BOOL __fastcall TAcadDocument::get_ObjectSnapMode(void)
{
  VARIANT_BOOL fSnapMode;
  OLECHECK(GetDefaultInterface()->get_ObjectSnapMode((VARIANT_BOOL*)&fSnapMode));
  return fSnapMode;
}

void __fastcall TAcadDocument::set_ObjectSnapMode(VARIANT_BOOL fSnapMode/*[in]*/)
{
  GetDefaultInterface()->set_ObjectSnapMode(fSnapMode/*[in]*/);
}

VARIANT_BOOL __fastcall TAcadDocument::get_ReadOnly(void)
{
  VARIANT_BOOL bReadOnly;
  OLECHECK(GetDefaultInterface()->get_ReadOnly((VARIANT_BOOL*)&bReadOnly));
  return bReadOnly;
}

VARIANT_BOOL __fastcall TAcadDocument::get_Saved(void)
{
  VARIANT_BOOL bSaved;
  OLECHECK(GetDefaultInterface()->get_Saved((VARIANT_BOOL*)&bSaved));
  return bSaved;
}

VARIANT_BOOL __fastcall TAcadDocument::get_MSpace(void)
{
  VARIANT_BOOL Mode;
  OLECHECK(GetDefaultInterface()->get_MSpace((VARIANT_BOOL*)&Mode));
  return Mode;
}

void __fastcall TAcadDocument::set_MSpace(VARIANT_BOOL Mode/*[in]*/)
{
  GetDefaultInterface()->set_MSpace(Mode/*[in]*/);
}

Autocad_tlb::IAcadUtilityPtr __fastcall TAcadDocument::get_Utility(void)
{
  Autocad_tlb::IAcadUtilityPtr pUtil;
  OLECHECK(GetDefaultInterface()->get_Utility(&pUtil));
  return pUtil;
}

Autocad_tlb::IAcadSelectionSetPtr __fastcall TAcadDocument::get_PickfirstSelectionSet(void)
{
  Autocad_tlb::IAcadSelectionSetPtr pSelSet;
  OLECHECK(GetDefaultInterface()->get_PickfirstSelectionSet(&pSelSet));
  return pSelSet;
}

VARIANT_BOOL __fastcall TAcadDocument::get_Active(void)
{
  VARIANT_BOOL pvbActive;
  OLECHECK(GetDefaultInterface()->get_Active((VARIANT_BOOL*)&pvbActive));
  return pvbActive;
}

void __fastcall TAcadDocument::set_WindowState(Autocad_tlb::AcWindowState pWinState/*[in]*/)
{
  GetDefaultInterface()->set_WindowState(pWinState/*[in]*/);
}

Autocad_tlb::AcWindowState __fastcall TAcadDocument::get_WindowState(void)
{
  Autocad_tlb::AcWindowState pWinState;
  OLECHECK(GetDefaultInterface()->get_WindowState((Autocad_tlb::AcWindowState*)&pWinState));
  return pWinState;
}

void __fastcall TAcadDocument::set_Width(int pWidth/*[in]*/)
{
  GetDefaultInterface()->set_Width(pWidth/*[in]*/);
}

int __fastcall TAcadDocument::get_Width(void)
{
  int pWidth;
  OLECHECK(GetDefaultInterface()->get_Width((int*)&pWidth));
  return pWidth;
}

void __fastcall TAcadDocument::set_Height(int pHeight/*[in]*/)
{
  GetDefaultInterface()->set_Height(pHeight/*[in]*/);
}

int __fastcall TAcadDocument::get_Height(void)
{
  int pHeight;
  OLECHECK(GetDefaultInterface()->get_Height((int*)&pHeight));
  return pHeight;
}

void __fastcall TAcadDocument::set_ActiveLayout(Autocad_tlb::IAcadLayoutPtr pLayout/*[in]*/)
{
  GetDefaultInterface()->set_ActiveLayout(pLayout/*[in]*/);
}

Autocad_tlb::IAcadLayoutPtr __fastcall TAcadDocument::get_ActiveLayout(void)
{
  Autocad_tlb::IAcadLayoutPtr pLayout;
  OLECHECK(GetDefaultInterface()->get_ActiveLayout(&pLayout));
  return pLayout;
}

Autocad_tlb::LONG_PTR __fastcall TAcadDocument::get_HWND(void)
{
  Autocad_tlb::LONG_PTR HWND;
  OLECHECK(GetDefaultInterface()->get_HWND((Autocad_tlb::LONG_PTR*)&HWND));
  return HWND;
}

BSTR __fastcall TAcadDocument::get_WindowTitle(void)
{
  BSTR Title = 0;
  OLECHECK(GetDefaultInterface()->get_WindowTitle((BSTR*)&Title));
  return Title;
}

Autocad_tlb::IAcadApplicationPtr __fastcall TAcadDocument::get_Application(void)
{
  Autocad_tlb::IAcadApplicationPtr pAppObj;
  OLECHECK(GetDefaultInterface()->get_Application(&pAppObj));
  return pAppObj;
}

Autocad_tlb::IAcadDatabasePtr __fastcall TAcadDocument::get_Database(void)
{
  Autocad_tlb::IAcadDatabasePtr pDatabase;
  OLECHECK(GetDefaultInterface()->get_Database(&pDatabase));
  return pDatabase;
}

Autocad_tlb::IAcadMaterialPtr __fastcall TAcadDocument::get_ActiveMaterial(void)
{
  Autocad_tlb::IAcadMaterialPtr pActMaterial;
  OLECHECK(GetDefaultInterface()->get_ActiveMaterial(&pActMaterial));
  return pActMaterial;
}

void __fastcall TAcadDocument::set_ActiveMaterial(Autocad_tlb::IAcadMaterialPtr pActMaterial/*[in]*/)
{
  GetDefaultInterface()->set_ActiveMaterial(pActMaterial/*[in]*/);
}


};     // namespace Autocad_tlb


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Autocad_ocx
{

void __fastcall PACKAGE Register()
{
  // [8]
  TComponentClass cls_svr[] = {
                              __classid(Autocad_tlb::TAcadAcCmColor), 
                              __classid(Autocad_tlb::TAcadSortentsTable), 
                              __classid(Autocad_tlb::TAcadTableStyle), 
                              __classid(Autocad_tlb::TAcadMLeaderStyle), 
                              __classid(Autocad_tlb::TAcadDatabase), 
                              __classid(Autocad_tlb::TAcadSecurityParams), 
                              __classid(Autocad_tlb::TAcadLayerStateManager), 
                              __classid(Autocad_tlb::TAcadDocument)
                           };
  RegisterComponents("AutoCAD", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Autocad_ocx
