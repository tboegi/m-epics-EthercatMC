#!/usr/bin/env python
#

import datetime
import inspect
import unittest
import os
from AxisMr import AxisMr
from AxisCom import AxisCom

filnam = os.path.basename(__file__)[0:3]
tc_no_base = int(os.path.basename(__file__)[0:3]) * 10
###


def lineno():
    return inspect.currentframe().f_back.f_lineno


class Test(unittest.TestCase):
    url_string = os.getenv("TESTEDMOTORAXIS")
    print(
        f"{datetime.datetime.now():%Y-%m-%d %H:%M:%S} {filnam} url_string={url_string}"
    )

    axisCom = AxisCom(url_string, log_debug=False)
    axisMr = AxisMr(axisCom)
    old_PwrAuto = axisCom.get("-PwrAuto")
    old_DHLM = axisCom.get("-CfgDHLM")
    old_DLLM = axisCom.get("-CfgDLLM")

    print(f"{datetime.datetime.now():%Y-%m-%d %H:%M:%S} {filnam}")

    # Make sure that motor is homed
    def test_TC_92101(self):
        tc_no = tc_no_base + 1
        self.axisCom.putDbgStrToLOG("Start " + str(int(tc_no)), wait=True)
        self.axisCom.put("-PwrAuto", 0)
        self.axisMr.setValueOnSimulator(tc_no, "bAxisHomed", 1)
        self.axisMr.powerOnHomeAxis(tc_no)
        # self.axisMr.setValueOnSimulator(tc_no, "fHighHardLimitPos", self.old_HLM)
        # self.axisMr.setValueOnSimulator(tc_no, "fLowHardLimitPos", self.old_LLM)
        self.axisCom.putDbgStrToLOG("Passed " + str(tc_no), wait=True)

    # low limit switch
    def test_TC_92102(self):
        tc_no = tc_no_base + 2
        self.axisCom.putDbgStrToLOG("Start " + str(int(tc_no)), wait=True)
        # self.axisMr.setSoftLimitsOff(tc_no, disableDHLM=False)
        self.axisMr.setSoftLimitsOff(tc_no)
        self.axisMr.moveWait(tc_no, self.old_DLLM)
        self.axisCom.put(".JOGR", 1)
        wait_for_done = 60
        self.axisMr.waitForStartAndDone(tc_no, wait_for_done)
        rbv = self.axisCom.get(".RBV", use_monitor=False)
        self.axisMr.setSoftLimitsOn(tc_no, low_limit=rbv, high_limit=self.old_DHLM)
        self.axisMr.setSoftLimitsOff(tc_no, disableDLLM=False)
        lls = self.axisCom.get(".LLS", use_monitor=False)
        passed = lls
        if passed:
            self.axisCom.putDbgStrToLOG("Passed " + str(tc_no), wait=True)
        else:
            self.axisCom.putDbgStrToLOG("Failed " + str(tc_no), wait=True)
        assert passed

    def teardown_class(self):
        tc_no = int(filnam) * 10000 + 9999
        print(
            f"{datetime.datetime.now():%Y-%m-%d %H:%M:%S} {filnam}:{lineno()} {tc_no} teardown_class"
        )
        if False:
            self.axisMr.setSoftLimitsOn(
                tc_no, low_limit=self.old_LLM, high_limit=self.old_HLM
            )
            self.axisCom.put("-PwrAuto", self.old_PwrAuto)
        self.axisCom.close()
