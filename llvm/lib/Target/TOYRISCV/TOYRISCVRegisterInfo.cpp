#include "TOYRISCVRegisterInfo.h"
#include "TOYRISCV.h"
#include "TOYRISCVSubtarget.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

#define GET_REGINFO_TARGET_DESC
#include "TOYRISCVGenRegisterInfo.inc"

using namespace llvm;

MCPhysReg const *
TOYRISCVRegisterInfo::getCalleeSavedRegs(MachineFunction const *MF) const {
  // This constant was generated by tablegen from TOYRISCVCallingConv.td
  return CSR_LP32_SaveList;
}

uint32_t const *
TOYRISCVRegisterInfo::getCallPreservedMask(MachineFunction const &MF,
                                           CallingConv::ID) const {
  return CSR_LP32_RegMask;
}

BitVector
TOYRISCVRegisterInfo::getReservedRegs(MachineFunction const &MF) const {
  constexpr uint16_t ReservedCPURegs[] = {TOYRISCV::ZERO, TOYRISCV::RA,
                                          TOYRISCV::FP,   TOYRISCV::SP,
                                          TOYRISCV::GP,   TOYRISCV::TP};
  BitVector Reserved(getNumRegs());
  for (auto const reg : ReservedCPURegs) {
    Reserved.set(reg);
  }

  return Reserved;
}

void TOYRISCVRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                               int SPAdj, unsigned FIOperandNum,
                                               RegScavenger *RS) const {
  // TODO
}

// vim: set ts=2 sw=2 sts=2:
