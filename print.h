#ifndef PRINT_H
#define PRINT_H
#include "file.h"
const QString MicroBitTable[29][32] = {

 //1
 {"Reserve","Reserve","STBAR","EXINT","Reserve","IDXRSEL","IDXRSEL","IDXRSEL","IDXRSEL","Reserve","Reserve","Reserve","Reserve","STFL","STPS","JLMN",
 "JLML","JEXFLG","JZD","JRFT","JET","JNCn","JNInD","JNInI","JNIn","IDXIn","RTN","JSR","JMP","RET","WAIT","NOP"},

 {"Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "IDSLRSEL","IDSLRSEL","IDSLRSEL","IDSLRSEL","JumpDirSetVal","JumpDirSetVal","JumpDirSetVal","JumpDirSetVal","JumpDirSetVal","JumpDirSetVal","JumpDirSetVal",
  "JumpDirSetVal","JumpDirSetVal","JumpDirSetVal","JumpDirSetVal","JumpDirSetVal"
 },

 {"Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "IDXSETm","Reserve","Reserve","CFLGnSel","CFLGnSel","CFLGnSel","CFLGnSel","Reserve","Reserve","IDXSETmSET","IDXSETmSET","Reserve","Reserve","Reserve","Reserve","Reserve"
  },

 {"LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal",
  "LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal",
  "LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal"
  },

 //5
 {"Reserve","Reserve","STBAR","EXINT","Reserve","LpIDXRSel","LpIDXRSel","LpIDXRSel","LpIDXRSel","Reserve","Reserve","Reserve","Reserve","STFL","STPS","JLMN",
  "JLML","JEXFLG","JZD","JRFT","JET","JNCn","JNInD","JNInI","JNIn","IDXIn","RTN","JSR","JMP","RET","WAIT","NOP"
 },

 {"Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "IDXLRSel","IDXLRSel","IDXLRSel","IDXLRSel","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal",
  "JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal"
 },

 {"Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "IDXSETm","Reserve","Reserve","CFLGnSEL","CFLGnSEL","CFLGnSEL","CFLGnSEL","Reserve","Reserve","IDXSETmSET","IDXSETmSET","Reserve",
  "Reserve","Reserve","Reserve","Reserve"
 },

 {"LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal",
  "LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal",
  "LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal",
  "LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal"
 },
 //9
 {"Reserve","Reserve","STBAR","EXINT","Reserve","LpIDXRSel","LpIDXRSel","LpIDXRSel",
  "LpIDXRSel","Reserve","Reserve","Reserve","Reserve","STFL","STPS","JLMN",
  "JLML","JEXFLG","JZD","JRFT", "JET","JNCn","JNInd","JNInI",
  "JNIn","IDXIn","RTN","JSR","JMP","RET","WAIT","NOP"
  },
 {"Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "IDXLRSEL","IDXLRSEL","IDXLRSEL","IDXLRSEL","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal",
  "JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal","JmpDirSetVal"
 },

 {"Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "IDXSETm","Reserve","Reserve","CFLGnSel","CFLGnSel","CFLGnSel","CFLGnSel","Reserve",
  "CFLGnSel","IDXSETmSET","IDXSETmSET","Reserve","Reserve","Reserve","Reserve","Reserve"
  },

  {"LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal",
   "LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal",
   "LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal",
   "LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal","LpDirSetVal"
  },
  //13
  {"Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
   "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
   "Reserve","Reserve","Split1way","Split1way","Split1way","Split1way","Split1way","Split1way",
   "Split1way","Reserve","Reserve","Reserve","MEND","MSTART","Rserve","Reserve"
    },
  {"Split2way","Split2way","Split2way","Split2way","Split2way","Split2way","Split2way","Reserve",
   "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
   "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
   "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve"
    },
  {"DirSetSel","DirSetSel","DirSetSel","DirSetSel","DirSetSel","DirSetSel","Reserve","Reserve",
   "DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData",
   "DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData",
   "DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData"
  },
  {"Reserve","XCRegInSel","XCRegInSel","XCRegInSel","XSRegInSel","XSRegInSel","XSRegInSel","XKRegInSel",
   "XKRegInSel","XKRegInSel","XCDnRegSel","XCDnRegSel","XCDnRegSel","XCDnRegSel","XCurAddRegALU","XCurAddrRegALU",
   "XCurAddrRegALU","XCurAddrRegALU","XCurAddrRegALU","XCurAddrRegALU","XCurAddrRegALU","XBDNRegSel","XBDNRegSel","XBDNRegSel",
   "XBDNRegSel","XBaseAddrRegALU","XBaseAddrRegALU","XBaseAddrRegALU","XBaseAddrRegALU","XBaseAddrRegALU","XBaseAddrRegALU","XBaseAddrRegALU"
  },
  //17
 {"DirSetSel","DirSetSel","DirSetSel","DirSetSel","DirSetSel","DirSetSel","Reserve","Reserve",
  "DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData",
  "DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData",
  "DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData"
 },
 {"Reserve","YCRegInSel","YCRegInSel","YCRegInSel","YSRegInSel","YSRegInSel","YSRegInSel","YKRegInSel",
  "YKRegInSel""YKRegInSel","YCDnRegSel","YCDnRegSel","YCDnRegSel","YCDnRegSel","YCurAddrRegALU","YCurAddrRegALU",
  "YCurAddrRegALU","YCurAddrRegALU","YCurAddrRegALU","YCurAddrRegALU","YCurAddrRegALU","YBDNRegSel","YBDNRegSel","YBDNRegSel",
  "YBDNRegSel","YBaseAddrRegALU","YBaseAddrRegALU","YBaseAddrRegALU","YBaseAddrRegALU","YBaseAddrRegALU","YBaseAddrRegALU","YBaseAddrRegALU"
 },
 {"D4RegALU","D4RegALU","D4RegALU","D4RegALU","D3RegALU","D3RegALU","D3RegALU","D3RegALU",
  "YTEN","YRegInSel","YRegInSel","YRegInSel","XTEn","XRegInSel","XRegInSel","XRegInSel",
  "YoutSet","YoutSet","XoutSet","XoutSet","YTOutSet","YTOutSet","YTOutSet","YTOutSet",
  "LHAXSwap","INV","INV","INV","XTOutSel","XTOutSel","XTOutSel","XTOutSel"
 },
 {"YR4RegInSel","YR4RegInSel","YR4RegInSel","YR3RegInSel",
  "YR3RegInSel","YR3RegInSel","YR2RegInSel","YR2RegInSel",
  "YR2RegInSel","YR1RegInSel","YR1RegInSel","YR1RegInSel",
  "Reserve","YCALUInSel","YCALUInSel","YCALUInSel",
  "XR4RegInSel","XR4RegInSel","XR4RegInSel","XR3RegInSel",
  "XR3RegInSel","XR3RegInSel","XR2RegInSel","XR2RegInSel",
  "XR2RegInSel","XR1RegInSel","XR1RegInSel","XR1RegInSel",
  "Reserve","XCALUInSel","XCALUInSel","XCALUInSel"
 },
 //21
 {"Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","ZBaseAddrALU","ZBaseAddrALU","ZBaseAddrALU","ZBaseAddrALU","ZBaseAddrALU","ZBaseAddrALU"
 },
 {"TP1BaseDataRegALU","TP1BaseDataRegALU","TP1BaseDataRegALU","TP1BaseDataRegALU","TP1BaseDataRegALU","TP1BaseDataRegALU","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","DMBDirSetData1","DMBDirSetData1",
  "DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1",
  "DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1","DMBDirSetData1"
 },
 {"TP2BaseDataRegALU","TP2BaseDataRegALU","TP2BaseDataRegALU","TP2BaseDataRegALU","TP2BaseDataRegALU","TP2BaseDataRegALU","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","DMBDirSetData2","DMBDirSetData2",
  "DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2",
  "DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2","DMBDirSetData2"
 },
 {"INV","INV","TP/FP/DSCR change","TP/FP/DSCR change","TP/FP/DSCR change","DataHold","Reserve","Reserve",
  "AddrFunSel","AddrFunSel","AddrFunSel","AddrFunSel","CCDRegALU","CCDRegALU","CCDRegALU","RCDRegALU",
  "RCDRegALU","RCDRegALU","DSDRegALU","DSDRegALU","DSDRegALU","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve","Reserve"
 },
 //25
 {"Reserve","Reserve","Reserve","DirSetReg","DirSetReg","DirSetReg","DirSetReg","DirSetReg",
  "Reserve","D6Sel","D6Sel","D6Sel","Reserve","TPH2Sel","TPH2Sel","TPH2Sel",
  "Reserve","Reserve","Reserve","DirSetReg","DirSetReg","DirSetReg","DirSetReg","DirSetReg",
  "Reserve","D5Sel","D5Sel","D5Sel","Reserve","TPH1Sel","TPH1Sel","TPH1Sel"
 },
 {"YASL","YALD","YASV","XALD","XASV","Reserve","Reserve","Reserve",
  "PSMEN","PSMADDALU","PSMADDALU","PSMADDALU","PSMADDALU","PSMADDALU","Reserve","Reserve",
  "Reserve","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData",
  "DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData","DirSetData"
 },
 {"RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit",
  "RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit",
  "RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit",
  "RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit"
 },
 {"Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","DBMEN","DBMADDALU",
  "DBMADDALU","DBMADDALU","DBMADDALU","DBMADDALU",
  "R2","R","W2","W",
  "M1","M2","Reserve","Reserve",
  "RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit",
  "RealTimeBit","RealTimeBit","RealTimeBit","RealTimeBit"
 },
 {"PSCROff","FMSCROff","DUTSCROff","AriamOff",
  "Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","Reserve",
  "Reserve","Reserve","Reserve","RealTimePinSel",
  "RealTimePinSel","RealTimePinSel","RealTimePinSel","RealTimePinSel"
 }
};


#endif // PRINT_H
