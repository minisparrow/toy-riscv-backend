#if !defined TOYRISCVSUBTARGET_H_INCLUDED
#define TOYRISCVSUBTARGET_H_INCLUDED

#include "TOYRISCVFrameLowering.h"
#include "TOYRISCVISelLowering.h"
#include "TOYRISCVInstrInfo.h"
#include "llvm/CodeGen/SelectionDAGTargetInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/MC/MCInstrItineraries.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"

#define GET_SUBTARGETINFO_HEADER
#include "TOYRISCVGenSubtargetInfo.inc"

#define DEBUG_TYPE "toyriscv-subtarget"

namespace llvm {

class StringRef;
class TOYRISCVTargetMachine;
class TOYRISCVSubtarget : public TOYRISCVGenSubtargetInfo {
  virtual void anchor();

protected:
  bool HasRV64 = false; // FeatureRV64 is set to this field in TOYRISCV.td
  MVT XLenVT = MVT::i32;
  InstrItineraryData InstrItins;
  Triple TargetTriple;
  const TOYRISCVTargetMachine &TM;
  TOYRISCVFrameLowering FrameLowering;

public:
  TOYRISCVSubtarget(Triple const &TT, StringRef &CPU, StringRef &TuneCPU,
                    StringRef &FS, TOYRISCVTargetMachine const &_TM);

  TOYRISCVSubtarget &initializeSubtargetDependencies(StringRef CPU,
                                                     StringRef TuneCPU,
                                                     StringRef FS,
                                                     const TargetMachine &TM);

  void ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU, StringRef FS);
};

} // namespace llvm

#endif // TOYRISCVSUBTARGET_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
