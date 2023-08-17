<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="en">
<context>
    <name>FaultTableInterface</name>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="14"/>
        <source>Fault description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="31"/>
        <source>Please enter search keywords</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="44"/>
        <source>Search</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="57"/>
        <source>DCAC Fault Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="71"/>
        <source>DCDC Module Fault Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="81"/>
        <source>Battery Protection Logic Explanation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="98"/>
        <source>Battery Cut-off Voltage Protection Logic Explanation for Grid-on and grid-off modes:

Grid-on mode:
  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm &quot;Discharge Not Allowed&quot; will be triggered, and the DCAC converter output power will drop to 0.
  The &quot;Discharge Not Allowed&quot; alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage or when the mode is changed to charging.
  When the battery is charged to the upper limit of the charging voltage, an alarm &quot;Charging Not Allowed&quot; will be triggered. If the DCAC is in charging mode, the charging power will drop to 0. If the DCAC is in discharge mode, it will not be affected.
  The &quot;Charging Not Allowed&quot; alarm will be cleared when the battery voltage is lower than the upper limit of the charging voltage minus the charging hysteresis voltage or when it is in discharge mode.

Grid-off mode:
  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm &quot;Discharge Not Allowed&quot; will be triggered, and the DCAC converter will shut down. The &quot;Discharge Not Allowed&quot; alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage. If there is no shutdown command, the system will resume operation.
  When the battery is charged to the upper limit of the charging voltage, an alarm &quot;Charging Not Allowed&quot; will be triggered. If the DCAC is in charging mode or in grid-off discharge mode, it will not be affected.
  The &quot;Charging Not Allowed&quot; alarm will be cleared when the battery voltage is lower than the upper limit of the charging voltage minus the charging hysteresis voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Alarm name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Alarm leve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Trigger condition</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="53"/>
        <source>Response action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="53"/>
        <source>Whether to reset
automatically and reset time</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>GridExpansion</name>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="14"/>
        <source>Grid expansion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="37"/>
        <source>Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="54"/>
        <source>Logic Explanation:
   When selecting grid expansion mode, the converter will limit the input power of the grid.
Charging and discharging power calculation in grid expansion mode:
   Charging Power: When the converter load power is less than the set grid capacity and the current battery SOC is less than the charging SOC, the converter will charge the battery with the value of (Charging Power = Grid Capacity - Load Power). When the battery SOC reaches the charging stop SOC or the battery is prohibited from charging, the charging process will stop. When the battery SOC reaches 90% and the current charging power exceeds 80% of the maximum machine output power, the charging power will be set as (Charging Power = Maximum Machine Output Power / 2).
   Discharging Power: When the converter load power is greater than the set grid capacity, the converter will discharge power to compensate for the insufficient grid power, with the value of (Discharging Power = Load Power - Grid Capacity). When the battery&apos;s SOC is less than the discharging stop SOC or the battery is prohibited from discharging, the converter will maintain zero power operation. When the battery continues to discharge to reach the Depth of Discharge (DOD), DOD protection will be applied.
   Note: The charging and discharging power will not exceed the allowed charging power and discharging power stated in the battery data sheet. Constant power setting is invalid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="87"/>
        <source>Generator Charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="95"/>
        <location filename="../GridExpansion/gridexpansion.ui" line="111"/>
        <location filename="../GridExpansion/gridexpansion.ui" line="127"/>
        <location filename="../GridExpansion/gridexpansion.ui" line="143"/>
        <source>%</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="103"/>
        <source>Grid Charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="119"/>
        <source>Charge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="135"/>
        <source>Discharge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="151"/>
        <source>Grid capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="159"/>
        <source>kW</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="173"/>
        <source>Logic Diagram</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="246"/>
        <source>Reload</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="277"/>
        <source>Previous
Page</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="40"/>
        <source>Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="40"/>
        <source>Value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="40"/>
        <source>Unit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="48"/>
        <source>0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="51"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="52"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="55"/>
        <source>Charging SOC of Grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="56"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="59"/>
        <source>Charging Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="60"/>
        <source>Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="63"/>
        <source>Discharging Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="64"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="67"/>
        <source>Grid Capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="68"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>MEGAWin</name>
    <message>
        <location filename="../win.ui" line="2437"/>
        <location filename="../win.ui" line="2559"/>
        <source>Change
Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="117"/>
        <source>Basic settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="167"/>
        <source>Function Setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="219"/>
        <location filename="../win.ui" line="269"/>
        <location filename="../win.ui" line="787"/>
        <location filename="../win.ui" line="847"/>
        <location filename="../win.ui" line="1942"/>
        <location filename="../win.ui" line="2002"/>
        <location filename="../win.ui" line="3912"/>
        <location filename="../win.ui" line="4103"/>
        <location filename="../win.ui" line="4148"/>
        <location filename="../win.ui" line="4199"/>
        <location filename="../win.ui" line="4249"/>
        <location filename="../win.ui" line="4536"/>
        <location filename="../win.ui" line="4581"/>
        <location filename="../win.ui" line="8027"/>
        <location filename="../win.ui" line="8067"/>
        <location filename="../win.ui" line="8590"/>
        <location filename="../win.ui" line="8675"/>
        <location filename="../win.cpp" line="2380"/>
        <location filename="../win.cpp" line="3504"/>
        <location filename="../win.cpp" line="3513"/>
        <source>1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="224"/>
        <location filename="../win.ui" line="274"/>
        <location filename="../win.ui" line="792"/>
        <location filename="../win.ui" line="852"/>
        <location filename="../win.ui" line="1947"/>
        <location filename="../win.ui" line="2007"/>
        <location filename="../win.ui" line="3917"/>
        <location filename="../win.ui" line="4108"/>
        <location filename="../win.ui" line="4153"/>
        <location filename="../win.ui" line="4204"/>
        <location filename="../win.ui" line="4254"/>
        <location filename="../win.ui" line="4541"/>
        <location filename="../win.ui" line="4586"/>
        <location filename="../win.ui" line="8032"/>
        <location filename="../win.ui" line="8075"/>
        <location filename="../win.ui" line="8595"/>
        <location filename="../win.ui" line="8680"/>
        <source>2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="229"/>
        <location filename="../win.ui" line="279"/>
        <location filename="../win.ui" line="797"/>
        <location filename="../win.ui" line="857"/>
        <location filename="../win.ui" line="1952"/>
        <location filename="../win.ui" line="2012"/>
        <location filename="../win.ui" line="3922"/>
        <location filename="../win.ui" line="4113"/>
        <location filename="../win.ui" line="4209"/>
        <location filename="../win.ui" line="4546"/>
        <location filename="../win.ui" line="4591"/>
        <location filename="../win.ui" line="8037"/>
        <location filename="../win.ui" line="8083"/>
        <location filename="../win.ui" line="8600"/>
        <location filename="../win.ui" line="8685"/>
        <source>3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="234"/>
        <location filename="../win.ui" line="284"/>
        <location filename="../win.ui" line="802"/>
        <location filename="../win.ui" line="862"/>
        <location filename="../win.ui" line="1957"/>
        <location filename="../win.ui" line="2017"/>
        <location filename="../win.ui" line="3927"/>
        <location filename="../win.ui" line="4118"/>
        <location filename="../win.ui" line="4214"/>
        <location filename="../win.ui" line="4551"/>
        <location filename="../win.ui" line="4596"/>
        <location filename="../win.ui" line="8042"/>
        <location filename="../win.ui" line="8091"/>
        <location filename="../win.ui" line="8605"/>
        <location filename="../win.ui" line="8690"/>
        <source>4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="239"/>
        <location filename="../win.ui" line="289"/>
        <location filename="../win.ui" line="807"/>
        <location filename="../win.ui" line="867"/>
        <location filename="../win.ui" line="1962"/>
        <location filename="../win.ui" line="2022"/>
        <location filename="../win.ui" line="3932"/>
        <location filename="../win.ui" line="4123"/>
        <location filename="../win.ui" line="4219"/>
        <location filename="../win.ui" line="4556"/>
        <location filename="../win.ui" line="4601"/>
        <location filename="../win.ui" line="8047"/>
        <location filename="../win.ui" line="8096"/>
        <location filename="../win.ui" line="8610"/>
        <location filename="../win.ui" line="8695"/>
        <source>5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="244"/>
        <location filename="../win.ui" line="294"/>
        <location filename="../win.ui" line="812"/>
        <location filename="../win.ui" line="872"/>
        <location filename="../win.ui" line="1967"/>
        <location filename="../win.ui" line="2027"/>
        <location filename="../win.ui" line="3937"/>
        <location filename="../win.ui" line="4128"/>
        <location filename="../win.ui" line="4224"/>
        <location filename="../win.ui" line="4561"/>
        <location filename="../win.ui" line="4606"/>
        <location filename="../win.ui" line="8052"/>
        <location filename="../win.ui" line="8101"/>
        <location filename="../win.ui" line="8615"/>
        <location filename="../win.ui" line="8700"/>
        <source>6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="249"/>
        <location filename="../win.ui" line="299"/>
        <location filename="../win.ui" line="817"/>
        <location filename="../win.ui" line="877"/>
        <location filename="../win.ui" line="1972"/>
        <location filename="../win.ui" line="3942"/>
        <location filename="../win.ui" line="4133"/>
        <location filename="../win.ui" line="4229"/>
        <location filename="../win.ui" line="4566"/>
        <location filename="../win.ui" line="8057"/>
        <location filename="../win.ui" line="8620"/>
        <source>7</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="254"/>
        <location filename="../win.ui" line="304"/>
        <location filename="../win.ui" line="822"/>
        <location filename="../win.ui" line="882"/>
        <location filename="../win.ui" line="1977"/>
        <location filename="../win.ui" line="3947"/>
        <location filename="../win.ui" line="4138"/>
        <location filename="../win.ui" line="4234"/>
        <location filename="../win.ui" line="4571"/>
        <location filename="../win.ui" line="8062"/>
        <location filename="../win.ui" line="8625"/>
        <location filename="../win.ui" line="9294"/>
        <source>8</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="259"/>
        <location filename="../win.ui" line="309"/>
        <location filename="../win.ui" line="827"/>
        <location filename="../win.ui" line="887"/>
        <location filename="../win.ui" line="1982"/>
        <location filename="../win.ui" line="3952"/>
        <location filename="../win.ui" line="4239"/>
        <location filename="../win.ui" line="4576"/>
        <location filename="../win.ui" line="8630"/>
        <location filename="../win.ui" line="9299"/>
        <source>9</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="264"/>
        <location filename="../win.ui" line="832"/>
        <location filename="../win.ui" line="1987"/>
        <location filename="../win.ui" line="3957"/>
        <location filename="../win.ui" line="4143"/>
        <location filename="../win.ui" line="4244"/>
        <location filename="../win.ui" line="8635"/>
        <source>10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="837"/>
        <location filename="../win.ui" line="1992"/>
        <location filename="../win.ui" line="8640"/>
        <source>11</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="842"/>
        <location filename="../win.ui" line="1997"/>
        <location filename="../win.ui" line="8645"/>
        <source>12</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="314"/>
        <location filename="../win.cpp" line="4668"/>
        <source>Battery type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="322"/>
        <location filename="../win.ui" line="338"/>
        <location filename="../win.ui" line="354"/>
        <location filename="../win.ui" line="370"/>
        <location filename="../win.ui" line="402"/>
        <location filename="../win.ui" line="418"/>
        <location filename="../win.ui" line="450"/>
        <location filename="../win.ui" line="466"/>
        <location filename="../win.ui" line="498"/>
        <location filename="../win.ui" line="546"/>
        <location filename="../win.ui" line="562"/>
        <location filename="../win.ui" line="639"/>
        <location filename="../win.ui" line="921"/>
        <location filename="../win.ui" line="942"/>
        <location filename="../win.ui" line="995"/>
        <location filename="../win.ui" line="1043"/>
        <location filename="../win.ui" line="1091"/>
        <location filename="../win.ui" line="1139"/>
        <location filename="../win.ui" line="1155"/>
        <location filename="../win.ui" line="1171"/>
        <location filename="../win.ui" line="1187"/>
        <location filename="../win.ui" line="1203"/>
        <location filename="../win.ui" line="1219"/>
        <location filename="../win.ui" line="1235"/>
        <location filename="../win.ui" line="1251"/>
        <location filename="../win.ui" line="1288"/>
        <location filename="../win.ui" line="1320"/>
        <location filename="../win.ui" line="1843"/>
        <location filename="../win.ui" line="1851"/>
        <location filename="../win.ui" line="1859"/>
        <location filename="../win.ui" line="1867"/>
        <location filename="../win.ui" line="1875"/>
        <location filename="../win.ui" line="1883"/>
        <location filename="../win.ui" line="1891"/>
        <location filename="../win.ui" line="1899"/>
        <location filename="../win.ui" line="8122"/>
        <location filename="../win.ui" line="8146"/>
        <location filename="../win.ui" line="8194"/>
        <location filename="../win.ui" line="8218"/>
        <location filename="../win.ui" line="8242"/>
        <location filename="../win.ui" line="8266"/>
        <location filename="../win.ui" line="8314"/>
        <location filename="../win.ui" line="8953"/>
        <location filename="../win.ui" line="9342"/>
        <location filename="../win.ui" line="9374"/>
        <location filename="../win.ui" line="9521"/>
        <location filename="../win.ui" line="9585"/>
        <location filename="../win.ui" line="9649"/>
        <location filename="../win.ui" line="9713"/>
        <source>-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4812"/>
        <source>ProtocolVersion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="362"/>
        <source>BMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="386"/>
        <location filename="../win.ui" line="434"/>
        <location filename="../win.ui" line="482"/>
        <location filename="../win.ui" line="530"/>
        <location filename="../win.ui" line="578"/>
        <source>bps</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4821"/>
        <source>UserPassPort</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="410"/>
        <location filename="../win.cpp" line="4686"/>
        <source>Power control type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="378"/>
        <location filename="../win.cpp" line="4748"/>
        <source>serial port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="458"/>
        <source>EMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="426"/>
        <location filename="../win.cpp" line="4757"/>
        <source>serial port 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="490"/>
        <location filename="../win.cpp" line="4839"/>
        <source>Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="506"/>
        <location filename="../win.cpp" line="4708"/>
        <source>Output power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="514"/>
        <location filename="../win.ui" line="602"/>
        <location filename="../win.ui" line="979"/>
        <location filename="../win.ui" line="6333"/>
        <location filename="../win.ui" line="6360"/>
        <location filename="../win.ui" line="8170"/>
        <location filename="../win.ui" line="8921"/>
        <location filename="../win.ui" line="8969"/>
        <location filename="../win.ui" line="8985"/>
        <location filename="../win.ui" line="9097"/>
        <source>kW</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="474"/>
        <location filename="../win.cpp" line="4767"/>
        <source>serial port 4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="538"/>
        <source>System upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="522"/>
        <location filename="../win.cpp" line="4776"/>
        <source>serial port 5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="586"/>
        <location filename="../win.cpp" line="4861"/>
        <source>Sounds</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="610"/>
        <location filename="../win.cpp" line="4794"/>
        <source>Can port 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="618"/>
        <location filename="../win.ui" line="671"/>
        <source>kbps</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8961"/>
        <location filename="../win.cpp" line="3649"/>
        <source>Charge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="663"/>
        <location filename="../win.cpp" line="4803"/>
        <source>Can port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8977"/>
        <location filename="../win.cpp" line="3658"/>
        <source>Discharge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8801"/>
        <source>Charge Vol. upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1075"/>
        <location filename="../win.ui" line="1123"/>
        <location filename="../win.ui" line="5562"/>
        <location filename="../win.ui" line="8410"/>
        <location filename="../win.ui" line="8777"/>
        <location filename="../win.ui" line="8809"/>
        <location filename="../win.ui" line="8841"/>
        <location filename="../win.ui" line="8857"/>
        <location filename="../win.ui" line="8873"/>
        <location filename="../win.ui" line="8889"/>
        <location filename="../win.ui" line="9358"/>
        <location filename="../win.ui" line="9390"/>
        <location filename="../win.ui" line="9406"/>
        <location filename="../win.ui" line="9451"/>
        <location filename="../win.ui" line="9467"/>
        <location filename="../win.ui" line="9665"/>
        <location filename="../win.ui" line="9729"/>
        <source>V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8865"/>
        <source>Discharge Vol. lower Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="747"/>
        <source>System parameter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="892"/>
        <source>Change rate of power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="900"/>
        <source>kW/s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="908"/>
        <location filename="../win.cpp" line="5014"/>
        <source>Machine type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="929"/>
        <location filename="../win.cpp" line="5120"/>
        <source>Module Number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="950"/>
        <location filename="../win.cpp" line="4914"/>
        <source>Grid frequency upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="963"/>
        <location filename="../win.ui" line="1011"/>
        <location filename="../win.ui" line="1027"/>
        <location filename="../win.ui" line="1267"/>
        <source>Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="971"/>
        <location filename="../win.cpp" line="5023"/>
        <source>Machine capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="987"/>
        <location filename="../win.cpp" line="5129"/>
        <source>Restore factory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1003"/>
        <location filename="../win.cpp" line="4923"/>
        <source>Grid frequency lower limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1019"/>
        <source>Output Fre. grade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1131"/>
        <location filename="../win.cpp" line="5156"/>
        <source>Clear Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1059"/>
        <location filename="../win.ui" line="1107"/>
        <location filename="../win.ui" line="5616"/>
        <location filename="../win.ui" line="5643"/>
        <location filename="../win.ui" line="8713"/>
        <location filename="../win.ui" line="8729"/>
        <location filename="../win.ui" line="8745"/>
        <location filename="../win.ui" line="8761"/>
        <location filename="../win.ui" line="9001"/>
        <location filename="../win.ui" line="9017"/>
        <location filename="../win.ui" line="9033"/>
        <location filename="../win.ui" line="9049"/>
        <location filename="../win.ui" line="9065"/>
        <location filename="../win.ui" line="9081"/>
        <source>%</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1067"/>
        <source>Output vol. level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1147"/>
        <location filename="../win.cpp" line="4950"/>
        <source>HVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1163"/>
        <location filename="../win.cpp" line="5059"/>
        <source>Output reactive power mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1179"/>
        <location filename="../win.cpp" line="4959"/>
        <source>LVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1211"/>
        <location filename="../win.cpp" line="4968"/>
        <source>AFD enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1259"/>
        <location filename="../win.cpp" line="5084"/>
        <source>Primary FM dead zone</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1243"/>
        <location filename="../win.cpp" line="4978"/>
        <source>Insulation detection enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1296"/>
        <location filename="../win.cpp" line="5093"/>
        <source>PFM coeff</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1304"/>
        <source>kW/Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1280"/>
        <location filename="../win.cpp" line="4987"/>
        <source>PrimaryFreq enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1328"/>
        <location filename="../win.cpp" line="5102"/>
        <source>Grid recover time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="687"/>
        <location filename="../win.ui" line="735"/>
        <location filename="../win.ui" line="1336"/>
        <source>s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="35"/>
        <source>PCS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="394"/>
        <source>User PassPort</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="626"/>
        <location filename="../win.cpp" line="4870"/>
        <source>Energy Meter Model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="679"/>
        <source>BMS Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="727"/>
        <source>EMS Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1035"/>
        <source>Backup setup parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1083"/>
        <source>Restore backup setup parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1115"/>
        <location filename="../win.cpp" line="5050"/>
        <source>Transformer Turns Ratio</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1227"/>
        <location filename="../win.cpp" line="5074"/>
        <source>System Anti-Reverse Flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1312"/>
        <location filename="../win.cpp" line="4996"/>
        <source>Inertia enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1344"/>
        <location filename="../win.cpp" line="5005"/>
        <source>CV parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1372"/>
        <source>External device</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1403"/>
        <source>DI_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1413"/>
        <source>DI_2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1423"/>
        <source>DI_3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1433"/>
        <source>DI_4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1443"/>
        <source>DI_5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1453"/>
        <source>DI_6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1493"/>
        <source>Enable/Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1498"/>
        <source>NC/NO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1503"/>
        <location filename="../win.ui" line="1810"/>
        <source>Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1508"/>
        <source>Function description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1545"/>
        <source>Access Control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1553"/>
        <source>Full Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1561"/>
        <source>Smoke</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1569"/>
        <source>Temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1588"/>
        <location filename="../win.ui" line="1632"/>
        <location filename="../win.ui" line="1676"/>
        <source>N_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1610"/>
        <source>Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1654"/>
        <location filename="../win.ui" line="1698"/>
        <source>Reserve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1713"/>
        <source>BMS protection</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1744"/>
        <source>DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1755"/>
        <location filename="../win.cpp" line="5336"/>
        <source>Prohibit charging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1766"/>
        <location filename="../win.cpp" line="5345"/>
        <source>Prohibit discharging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1911"/>
        <source>Debug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2032"/>
        <location filename="../win.cpp" line="5443"/>
        <source>Debug variable 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2040"/>
        <source>1.5V Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2048"/>
        <source>INV A inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2053"/>
        <location filename="../win.cpp" line="5451"/>
        <source>Debug variable 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2061"/>
        <source> Bus Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2069"/>
        <source>INV B inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2074"/>
        <location filename="../win.cpp" line="5459"/>
        <source>Debug variable 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2082"/>
        <source>Grid A/AB Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2087"/>
        <source>INV C inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2092"/>
        <source>Debug variable 1 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2100"/>
        <source>Grid B/BC Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2105"/>
        <location filename="../win.cpp" line="5643"/>
        <source>INV On off flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2110"/>
        <source>Debug variable 2 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2118"/>
        <source>Grid C/CA Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2123"/>
        <location filename="../win.cpp" line="5651"/>
        <source>Logic state</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2128"/>
        <source>Debug variable 3 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2136"/>
        <source>Output A Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2141"/>
        <location filename="../win.cpp" line="5659"/>
        <source>INV flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2146"/>
        <source>Debug memery var. 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2154"/>
        <source>Output B Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2159"/>
        <location filename="../win.cpp" line="5667"/>
        <source>Grid flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2164"/>
        <source>Debug memery var. 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2172"/>
        <source>Output C Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2177"/>
        <location filename="../win.cpp" line="5675"/>
        <source>Grid protect flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2182"/>
        <source>Debug memery var. 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2190"/>
        <source>INV A Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2195"/>
        <location filename="../win.cpp" line="5683"/>
        <source>Bat flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2200"/>
        <source>Input Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2208"/>
        <source>INV B Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2213"/>
        <location filename="../win.cpp" line="5691"/>
        <source>DC bus flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2221"/>
        <source>Input. Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2229"/>
        <source>INV C Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2234"/>
        <location filename="../win.cpp" line="5699"/>
        <source>INT main flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2242"/>
        <location filename="../win.cpp" line="5707"/>
        <source>parallel signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2252"/>
        <source>MonitorDebug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2264"/>
        <source>DO control:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2276"/>
        <source>DO_TurnON_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2289"/>
        <source>DO_TurnOFF_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2303"/>
        <source>Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2315"/>
        <source>Local_on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2328"/>
        <source>Local_off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2342"/>
        <location filename="../win.cpp" line="5778"/>
        <source>test data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2626"/>
        <source>100kW - TS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3098"/>
        <location filename="../win.ui" line="3162"/>
        <location filename="../win.ui" line="3178"/>
        <location filename="../win.ui" line="3194"/>
        <location filename="../win.ui" line="3243"/>
        <location filename="../win.ui" line="3259"/>
        <location filename="../win.ui" line="3275"/>
        <source>0A</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3114"/>
        <location filename="../win.ui" line="3374"/>
        <location filename="../win.ui" line="3390"/>
        <location filename="../win.ui" line="3406"/>
        <location filename="../win.ui" line="3422"/>
        <location filename="../win.ui" line="3438"/>
        <location filename="../win.ui" line="3454"/>
        <source>0V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3714"/>
        <source>40%</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3704"/>
        <source>SOC:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4295"/>
        <source>Converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4335"/>
        <source>Grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4375"/>
        <source>Load</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4611"/>
        <location filename="../win.cpp" line="1905"/>
        <location filename="../win.cpp" line="1908"/>
        <source>DC input breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4616"/>
        <location filename="../win.cpp" line="1913"/>
        <location filename="../win.cpp" line="3336"/>
        <source>converter available</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4621"/>
        <source>DO1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4626"/>
        <location filename="../win.cpp" line="1905"/>
        <location filename="../win.cpp" line="1908"/>
        <location filename="../win.cpp" line="3282"/>
        <source>DC contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4631"/>
        <location filename="../win.cpp" line="1913"/>
        <location filename="../win.cpp" line="3345"/>
        <source>DC Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4636"/>
        <location filename="../win.cpp" line="1916"/>
        <location filename="../win.cpp" line="3390"/>
        <source>DO2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4641"/>
        <location filename="../win.cpp" line="1906"/>
        <location filename="../win.cpp" line="1909"/>
        <location filename="../win.cpp" line="3291"/>
        <source>Output contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4646"/>
        <location filename="../win.cpp" line="1914"/>
        <location filename="../win.cpp" line="3354"/>
        <source>converter status</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4651"/>
        <location filename="../win.cpp" line="1917"/>
        <location filename="../win.cpp" line="3399"/>
        <source>DO3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4656"/>
        <location filename="../win.cpp" line="1906"/>
        <location filename="../win.cpp" line="1909"/>
        <source>Output breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4661"/>
        <location filename="../win.cpp" line="1914"/>
        <source>Reactive power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4666"/>
        <source>DI1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4671"/>
        <location filename="../win.cpp" line="1910"/>
        <location filename="../win.cpp" line="3309"/>
        <source>Grid contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4676"/>
        <location filename="../win.cpp" line="1914"/>
        <location filename="../win.cpp" line="3372"/>
        <source>LVRT</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4681"/>
        <source>DI2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4686"/>
        <location filename="../win.cpp" line="1906"/>
        <location filename="../win.cpp" line="1910"/>
        <source>Grid breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4696"/>
        <source>DI3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4706"/>
        <source>DI4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4711"/>
        <source>DI5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4716"/>
        <source>DI6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4845"/>
        <source>Battery Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6492"/>
        <source>prompt:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6517"/>
        <source>Normal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6710"/>
        <source>Alarm level:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6791"/>
        <location filename="../win.ui" line="6847"/>
        <location filename="../win.cpp" line="3363"/>
        <location filename="../win.cpp" line="3372"/>
        <location filename="../win.cpp" line="3390"/>
        <location filename="../win.cpp" line="3399"/>
        <location filename="../win.cpp" line="3408"/>
        <location filename="../win.cpp" line="3417"/>
        <location filename="../win.cpp" line="3426"/>
        <location filename="../win.cpp" line="3435"/>
        <location filename="../win.cpp" line="3444"/>
        <location filename="../win.cpp" line="3453"/>
        <location filename="../win.cpp" line="3561"/>
        <location filename="../win.cpp" line="5068"/>
        <location filename="../win.cpp" line="5074"/>
        <location filename="../win.cpp" line="5185"/>
        <source>Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3962"/>
        <location filename="../win.ui" line="3972"/>
        <location filename="../win.ui" line="5023"/>
        <location filename="../win.ui" line="5792"/>
        <location filename="../win.ui" line="9304"/>
        <location filename="../win.ui" line="9319"/>
        <location filename="../win.cpp" line="1044"/>
        <location filename="../win.cpp" line="1215"/>
        <location filename="../win.cpp" line="1270"/>
        <location filename="../win.cpp" line="1314"/>
        <location filename="../win.cpp" line="1375"/>
        <location filename="../win.cpp" line="1931"/>
        <source>Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3967"/>
        <location filename="../win.ui" line="3977"/>
        <location filename="../win.ui" line="5303"/>
        <location filename="../win.ui" line="6033"/>
        <location filename="../win.ui" line="9309"/>
        <location filename="../win.ui" line="9324"/>
        <location filename="../win.cpp" line="1044"/>
        <location filename="../win.cpp" line="1215"/>
        <location filename="../win.cpp" line="1270"/>
        <location filename="../win.cpp" line="1314"/>
        <location filename="../win.cpp" line="1931"/>
        <source>Value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4888"/>
        <source>120</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5532"/>
        <location filename="../win.ui" line="6252"/>
        <location filename="../win.ui" line="9314"/>
        <location filename="../win.ui" line="9329"/>
        <location filename="../win.cpp" line="1044"/>
        <source>Unit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5589"/>
        <location filename="../win.ui" line="6279"/>
        <location filename="../win.ui" line="6306"/>
        <location filename="../win.ui" line="8362"/>
        <location filename="../win.ui" line="8905"/>
        <location filename="../win.ui" line="8937"/>
        <source>A</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6387"/>
        <location filename="../win.ui" line="6414"/>
        <source>kWh</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5056"/>
        <source>Bat voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1463"/>
        <source>DO_1   </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1473"/>
        <source>DO_2    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1483"/>
        <source>DO_3    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3766"/>
        <source>Converter Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4407"/>
        <location filename="../win.cpp" line="5762"/>
        <source>Converter State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4741"/>
        <source>Converter Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5086"/>
        <location filename="../win.cpp" line="2843"/>
        <source>Bat current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5116"/>
        <location filename="../win.cpp" line="2847"/>
        <source>SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5146"/>
        <location filename="../win.cpp" line="2851"/>
        <source>SOH</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5176"/>
        <source>Cell voltage (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5206"/>
        <source>Cell voltage (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5236"/>
        <source>Cell temp. (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5266"/>
        <source>Cell temp. (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3531"/>
        <source>600</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3522"/>
        <source>100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5670"/>
        <location filename="../win.ui" line="5697"/>
        <location filename="../win.ui" line="8793"/>
        <location filename="../win.ui" line="8825"/>
        <source>mV</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5724"/>
        <location filename="../win.ui" line="5751"/>
        <source>℃</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5819"/>
        <location filename="../win.cpp" line="2871"/>
        <source>Charging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5846"/>
        <location filename="../win.cpp" line="2875"/>
        <source>Discharging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5873"/>
        <location filename="../win.cpp" line="2879"/>
        <source>Allowable charging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5901"/>
        <location filename="../win.cpp" line="2883"/>
        <source>Allowable discharging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5928"/>
        <location filename="../win.cpp" line="2887"/>
        <source>Allowable charging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5955"/>
        <location filename="../win.cpp" line="2891"/>
        <source>Allowable discharging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6564"/>
        <source>Level1 </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6611"/>
        <source>Level2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6658"/>
        <source>Level3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6763"/>
        <source>Charging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6819"/>
        <source>Discharging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6893"/>
        <source>Data report</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6947"/>
        <source>Discharge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6975"/>
        <source>1.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7001"/>
        <location filename="../win.ui" line="7241"/>
        <source>Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7038"/>
        <location filename="../win.ui" line="7092"/>
        <source>339
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7058"/>
        <location filename="../win.ui" line="7295"/>
        <source>Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7112"/>
        <location filename="../win.ui" line="7349"/>
        <source>Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7146"/>
        <source>585.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7166"/>
        <location filename="../win.ui" line="7403"/>
        <source>Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7193"/>
        <source>Charge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7221"/>
        <source>2.4
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7275"/>
        <location filename="../win.ui" line="7329"/>
        <source>2.6
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7383"/>
        <source>184.2
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7463"/>
        <source>M  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7482"/>
        <source>Y  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7518"/>
        <source>M  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7537"/>
        <source>Y  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7566"/>
        <source>Export Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7604"/>
        <source>Note:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7621"/>
        <source>Out put file:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7657"/>
        <source>Log.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7675"/>
        <source>Report.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7720"/>
        <source>Data To Export</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7950"/>
        <source>History Record</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7865"/>
        <location filename="../win.ui" line="7969"/>
        <location filename="../win.cpp" line="2265"/>
        <source>Operation Log</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8005"/>
        <source>Parameter setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8130"/>
        <location filename="../win.cpp" line="3542"/>
        <source>Control mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8154"/>
        <source>Constant power (AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8178"/>
        <location filename="../win.cpp" line="3552"/>
        <source>Machine number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8226"/>
        <source>Parallel </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8202"/>
        <source>Work mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4778"/>
        <source>Please click on &apos;Alarm Information&apos; to enter the query interface
and view the details of the alarm information you have encountered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4807"/>
        <source>Alarm
Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8250"/>
        <location filename="../win.cpp" line="3504"/>
        <source>Output power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8298"/>
        <location filename="../win.cpp" line="3513"/>
        <source>Output reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8346"/>
        <location filename="../win.cpp" line="3522"/>
        <source>Constant current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8394"/>
        <location filename="../win.cpp" line="3531"/>
        <source>Constant voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8508"/>
        <source>  Title</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8540"/>
        <location filename="../win.cpp" line="5855"/>
        <source>Return</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8549"/>
        <source>Battery setup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9135"/>
        <location filename="../win.cpp" line="2341"/>
        <source>Battery power on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9154"/>
        <location filename="../win.cpp" line="2345"/>
        <source>Battery power off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9259"/>
        <location filename="../win.ui" line="9264"/>
        <location filename="../win.ui" line="9269"/>
        <location filename="../win.ui" line="9274"/>
        <location filename="../win.ui" line="9279"/>
        <location filename="../win.ui" line="9284"/>
        <location filename="../win.ui" line="9289"/>
        <source>New Row</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9334"/>
        <location filename="../win.cpp" line="3805"/>
        <source>Capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9350"/>
        <source>Grid off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9366"/>
        <source>Cell number(2V)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9382"/>
        <source>Grid on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9398"/>
        <location filename="../win.cpp" line="3815"/>
        <source>Battery float voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9414"/>
        <source>Shutdown voltage point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9459"/>
        <location filename="../win.cpp" line="3820"/>
        <source>Battery filling voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9475"/>
        <source>Mending center point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9529"/>
        <location filename="../win.cpp" line="3825"/>
        <source>Charge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9537"/>
        <location filename="../win.ui" line="9601"/>
        <location filename="../win.ui" line="9762"/>
        <location filename="../win.ui" line="9778"/>
        <source>C</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9545"/>
        <source>Temperature filling coefficient</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9593"/>
        <location filename="../win.cpp" line="3830"/>
        <source>Discharge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9609"/>
        <source>Mending allowable setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9673"/>
        <source>Temperature alarm upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9737"/>
        <location filename="../win.cpp" line="3855"/>
        <source>Uniform charging and flushing current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9770"/>
        <location filename="../win.cpp" line="3860"/>
        <source>Float turn uniform charging current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8705"/>
        <source>DOD_OnGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7639"/>
        <source>Record.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7766"/>
        <source>status:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7799"/>
        <source>u disk disconnect!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7834"/>
        <location filename="../win.cpp" line="2261"/>
        <source>Historical Failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7899"/>
        <location filename="../win.cpp" line="2269"/>
        <source>Electricity Statistical Table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7930"/>
        <location filename="../win.cpp" line="2273"/>
        <source>Eject U disk</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8106"/>
        <source>Grid conected mode of the converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8721"/>
        <source>Turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8737"/>
        <source>DOD_OffGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8753"/>
        <source>Turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8769"/>
        <source>Charge Vol. upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8785"/>
        <source>Turn on cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8833"/>
        <source>Discharge Vol. lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8817"/>
        <source>Turn off cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8897"/>
        <source>Charge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8849"/>
        <source>Turn on total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8993"/>
        <location filename="../win.cpp" line="3667"/>
        <source>Generator turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8881"/>
        <source>Turn off total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9009"/>
        <source>Generator turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8913"/>
        <source>UPS charge power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9025"/>
        <source>Generator charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8945"/>
        <source>Monthly cycle time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1521"/>
        <source>Dry Contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1537"/>
        <source>Dry Contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1777"/>
        <source>Level 1 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1788"/>
        <source>Level 2 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1799"/>
        <source>Level 3 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1821"/>
        <source>Charge power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1832"/>
        <source>Discharge power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8650"/>
        <source>13</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8655"/>
        <source>14</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8660"/>
        <source>15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8665"/>
        <source>16</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8670"/>
        <source>17</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8929"/>
        <source>Discharge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9041"/>
        <location filename="../win.cpp" line="3694"/>
        <source>Grid charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9057"/>
        <location filename="../win.cpp" line="3703"/>
        <source>Charge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9073"/>
        <location filename="../win.cpp" line="3712"/>
        <source>Discharge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9089"/>
        <source>Grid capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9165"/>
        <source>Lead</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9224"/>
        <source>A1: Generator turn on voltage
B1: Generator turn off voltage
A1 Setting range: [250, 900]
B1 Setting range: [250, 900]
Set rule:B1 - A1 ≥ 10V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9793"/>
        <source>Automatic operation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9811"/>
        <source>SystemInformation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9826"/>
        <source>Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9842"/>
        <location filename="../win.ui" line="9847"/>
        <location filename="../win.ui" line="9852"/>
        <location filename="../win.ui" line="9857"/>
        <location filename="../win.ui" line="9862"/>
        <source>新建行</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9867"/>
        <location filename="../win.ui" line="9872"/>
        <source>新建列</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9877"/>
        <location filename="../win.cpp" line="4617"/>
        <source>Monitoring software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9892"/>
        <source>Protocol version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9897"/>
        <location filename="../win.cpp" line="4635"/>
        <source>Converter software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9902"/>
        <location filename="../win.cpp" line="4644"/>
        <source>CPLD software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9907"/>
        <source>SN:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9916"/>
        <source>Network</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9975"/>
        <source>              interface:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10016"/>
        <source>Port:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10086"/>
        <source>DHCP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10105"/>
        <source>STATIC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10121"/>
        <source>ip：</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10134"/>
        <source>netmask:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10150"/>
        <source>gateway:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10163"/>
        <source>Server ip:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10176"/>
        <source>192 . 168 . 1 . 100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10189"/>
        <source>255 . 255 . 255 . 0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10202"/>
        <source>192 . 168 .  1  . 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10215"/>
        <source> 192 . 168 . 1  . 200</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10238"/>
        <location filename="../win.cpp" line="2310"/>
        <source>Apply and Restart system</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9997"/>
        <source>eth0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10035"/>
        <source>502</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10322"/>
        <source>Menu</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10356"/>
        <source>M_01 Converter turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10384"/>
        <source>Current mode:CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1061"/>
        <source>Advance setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1166"/>
        <location filename="../win.cpp" line="3870"/>
        <source>Check</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1166"/>
        <source>StartTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1166"/>
        <source>EndTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1166"/>
        <location filename="../win.cpp" line="3873"/>
        <source>State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1166"/>
        <source>Power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2896"/>
        <source>Alarm levels uploaded from BMS, level one alarm is yellow, level two alarm is orange, and level three alarm is red;
By default, the converter does not respond to level one and level two alarms, but shuts down in response to level three alarms.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2922"/>
        <source>Inv. side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2931"/>
        <source>Inv. side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2940"/>
        <source>Inv. side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2949"/>
        <source>Inv. side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2958"/>
        <source>Inv. side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2976"/>
        <source>Active power P on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2985"/>
        <source>Reactive power Q on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2994"/>
        <source>Apparent power S on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3004"/>
        <source>Power factor PF on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3013"/>
        <source>Converter battery side voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3022"/>
        <source>Converter battery side current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3031"/>
        <source>Converter battery side power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3040"/>
        <source>Converter bus voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3049"/>
        <source>The IGBT temperature of the converter: The IGBT temperature must not exceed 102°C. Otherwise, the converter will operate at a reduced capacity. It will resume full power operation when the temperature drops to 73°C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3058"/>
        <source>”The ambient temperature.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3073"/>
        <source>Grid side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3082"/>
        <source>Grid side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3091"/>
        <source>Grid side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3100"/>
        <source>Grid side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3109"/>
        <source>Grid side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3118"/>
        <source>Grid side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3127"/>
        <source>Active power P on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3136"/>
        <source>Reactive power Q on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3145"/>
        <source>Apparent power S on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3154"/>
        <source>Frequency on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3163"/>
        <source>Power factor PF on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3178"/>
        <source>Load side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3187"/>
        <source>Load side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3196"/>
        <source>Load side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3205"/>
        <source>Load side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3214"/>
        <source>Load side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3223"/>
        <source>Load side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3232"/>
        <source>Active power P on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3241"/>
        <source>Reactive power Q on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3250"/>
        <source>Apparent power S on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3259"/>
        <source>Power factor PF on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3301"/>
        <source>The output circuit breaker has two states: On, Off. It can only be manually opened and closed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3319"/>
        <source>The power grid circuit breaker has two states: On, Off; The power grid circuit breaker can only be manually disconnected.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3337"/>
        <source>The converter has two states: Enable,Disabled. The converter is enabled when the self-check is successful. Otherwise, the converter is disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3373"/>
        <source>LVRT states : Enable , Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3469"/>
        <source>Grid conected mode of the converter </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3470"/>
        <source>When &quot;Auto&quot; is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).                                               When &quot;Grid-on&quot; is selected, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.                                               When &quot;Grid-off&quot; is selected, the converter operates in grid-off mode (VF).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3505"/>
        <source>This item can modify the power factor, where the power factor is equal to the ratio of active power to apparent power. A positive value indicates leading reactive power, while a negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3514"/>
        <source>This parameter can change the reactive power Q, positive value indicates leading reactive power, negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3523"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant voltage and modify the voltage value. Converter will operate at the constant voltage value and function as a constant voltage source.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3532"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant current and modify the current value. Converter will charge or discharge the battery with this current value. Positive values represent discharging, while negative values represent charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3543"/>
        <source>Local: Converter control through HMI, In this mode, the EMS can only read and cannot write.
Remote: In remote mode, the EMS can perform both read and write control.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3553"/>
        <source>Device number: You can set ID number, which can be set within the range of M_01 to M_12.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3562"/>
        <source>Parallel operation: When converter operates at grid-off mode in parallel, this item needs to be enabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3685"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3686"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3695"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3704"/>
        <source>Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3713"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3722"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4310"/>
        <location filename="../win.cpp" line="4324"/>
        <location filename="../win.cpp" line="4338"/>
        <location filename="../win.cpp" line="4352"/>
        <location filename="../win.cpp" line="4366"/>
        <location filename="../win.cpp" line="4380"/>
        <location filename="../win.cpp" line="4394"/>
        <location filename="../win.cpp" line="4408"/>
        <location filename="../win.cpp" line="4422"/>
        <location filename="../win.cpp" line="4436"/>
        <source>charge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4317"/>
        <location filename="../win.cpp" line="4331"/>
        <location filename="../win.cpp" line="4345"/>
        <location filename="../win.cpp" line="4359"/>
        <location filename="../win.cpp" line="4373"/>
        <location filename="../win.cpp" line="4387"/>
        <location filename="../win.cpp" line="4401"/>
        <location filename="../win.cpp" line="4415"/>
        <location filename="../win.cpp" line="4429"/>
        <location filename="../win.cpp" line="4443"/>
        <source>discharge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2286"/>
        <source>Interface</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1996"/>
        <location filename="../win.cpp" line="2000"/>
        <location filename="../win.cpp" line="2004"/>
        <location filename="../win.cpp" line="2139"/>
        <location filename="../win.cpp" line="2198"/>
        <location filename="../win.cpp" line="2202"/>
        <location filename="../win.cpp" line="2206"/>
        <location filename="../win.cpp" line="2210"/>
        <location filename="../win.cpp" line="2214"/>
        <location filename="../win.cpp" line="2218"/>
        <location filename="../win.cpp" line="2222"/>
        <location filename="../win.cpp" line="2226"/>
        <location filename="../win.cpp" line="2230"/>
        <location filename="../win.cpp" line="2234"/>
        <location filename="../win.cpp" line="2238"/>
        <location filename="../win.cpp" line="2242"/>
        <location filename="../win.cpp" line="2246"/>
        <location filename="../win.cpp" line="2250"/>
        <location filename="../win.cpp" line="2254"/>
        <location filename="../win.cpp" line="2258"/>
        <location filename="../win.cpp" line="2262"/>
        <location filename="../win.cpp" line="2266"/>
        <location filename="../win.cpp" line="2270"/>
        <location filename="../win.cpp" line="2274"/>
        <location filename="../win.cpp" line="2287"/>
        <location filename="../win.cpp" line="2291"/>
        <location filename="../win.cpp" line="2295"/>
        <location filename="../win.cpp" line="2299"/>
        <location filename="../win.cpp" line="2303"/>
        <location filename="../win.cpp" line="2307"/>
        <location filename="../win.cpp" line="2311"/>
        <location filename="../win.cpp" line="2326"/>
        <location filename="../win.cpp" line="2330"/>
        <location filename="../win.cpp" line="2334"/>
        <location filename="../win.cpp" line="2338"/>
        <location filename="../win.cpp" line="2342"/>
        <location filename="../win.cpp" line="2346"/>
        <location filename="../win.cpp" line="2840"/>
        <location filename="../win.cpp" line="2844"/>
        <location filename="../win.cpp" line="2848"/>
        <location filename="../win.cpp" line="2852"/>
        <location filename="../win.cpp" line="2856"/>
        <location filename="../win.cpp" line="2860"/>
        <location filename="../win.cpp" line="2864"/>
        <location filename="../win.cpp" line="2868"/>
        <location filename="../win.cpp" line="2872"/>
        <location filename="../win.cpp" line="2876"/>
        <location filename="../win.cpp" line="2880"/>
        <location filename="../win.cpp" line="2884"/>
        <location filename="../win.cpp" line="2888"/>
        <location filename="../win.cpp" line="2892"/>
        <location filename="../win.cpp" line="2896"/>
        <location filename="../win.cpp" line="2900"/>
        <location filename="../win.cpp" line="2904"/>
        <location filename="../win.cpp" line="5731"/>
        <location filename="../win.cpp" line="5754"/>
        <location filename="../win.cpp" line="5762"/>
        <location filename="../win.cpp" line="5770"/>
        <location filename="../win.cpp" line="5778"/>
        <location filename="../win.cpp" line="5786"/>
        <location filename="../win.cpp" line="5855"/>
        <location filename="../win.cpp" line="5880"/>
        <source>OK</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1196"/>
        <location filename="../win.cpp" line="2921"/>
        <source>Inv. voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1196"/>
        <location filename="../win.cpp" line="2930"/>
        <source>Inv. voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1196"/>
        <location filename="../win.cpp" line="2939"/>
        <source>Inv. voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1197"/>
        <location filename="../win.cpp" line="2948"/>
        <source>Inv. current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1197"/>
        <location filename="../win.cpp" line="2957"/>
        <source>Inv. current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1197"/>
        <location filename="../win.cpp" line="2966"/>
        <source>Inv. current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1916"/>
        <location filename="../win.cpp" line="3381"/>
        <source>Start Diesel Generator Signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1917"/>
        <location filename="../win.cpp" line="3408"/>
        <source>Dry contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1918"/>
        <location filename="../win.cpp" line="3417"/>
        <source>Dry contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2197"/>
        <source>Discharge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2201"/>
        <source>Discharge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2205"/>
        <source>Discharge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2209"/>
        <source>Discharge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2213"/>
        <source>Charge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2217"/>
        <source>Charge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2221"/>
        <source>Charge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2225"/>
        <source>Charge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2229"/>
        <source>Month-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2233"/>
        <source>Year-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2237"/>
        <source>Daily electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2238"/>
        <source>To view the daily charge and discharge volume, click here to jump to the histogram of daily charge and discharge volume. The horizontal axis is in day, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2241"/>
        <source>Annual electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2242"/>
        <source>To view the annual charge and discharge volume, click here to jump to the histogram of the annual charge and discharge volume, the horizontal axis is in year, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2245"/>
        <source>Month+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2249"/>
        <source>Year+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2253"/>
        <source>Monthly electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2254"/>
        <source>To view the monthly charge and discharge volume, click here to jump to the histogram of monthly charge and discharge volume. The horizontal axis is in month, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2257"/>
        <source>Total electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2258"/>
        <source>To view the total charge and discharge, click here to jump to the overview chart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2290"/>
        <source>Port</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2294"/>
        <source>Ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2298"/>
        <source>Netmask</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2302"/>
        <source>Gateway</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2306"/>
        <source>Serber ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2311"/>
        <source>This is the application and restart the system. After clicking, the system will be restarted. If there is an upgrade of the monitoring screen program, the new monitoring screen program will be used after the restart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2365"/>
        <source>CAN communication failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2368"/>
        <source>Fire alarm (High temp. alarm)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2765"/>
        <source>Power control type：CP_P-&gt;CP_N&amp;&amp;P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2768"/>
        <source>Power control type：CP_N&amp;&amp;P-&gt;CP_P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2771"/>
        <source>Grid Fre Upper limit：0.2-&gt;3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2774"/>
        <source>Grid Fre Upper limit：3-&gt;0.2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2777"/>
        <source>Voltage protection Lower limit：-10-&gt;-15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2780"/>
        <source>Voltage protection Lower limit：-15-&gt;-10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2783"/>
        <source>Operation mode：Prevent countercurrnet-&gt;Peak valley</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2792"/>
        <source>Operation mode：UPS-&gt;Prevent countercurrnet</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2789"/>
        <source>Operation mode：Manual-&gt;UPS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1995"/>
        <source>Turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1999"/>
        <source>Stand-by</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2003"/>
        <source>Turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2325"/>
        <source>DO turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2326"/>
        <source>This is the DO control closure, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2329"/>
        <source>Do turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2330"/>
        <source>This is the DO control off, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2333"/>
        <source>Local on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2334"/>
        <source>This is to start a local soft boot, only for internal debugging use.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2337"/>
        <source>Local off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2338"/>
        <source>This is to turn off the local soft boot for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2786"/>
        <source>Operation mode：Peak valley-&gt;Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2795"/>
        <source>Inv ON/Off-Grid：Off-&gt;automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2798"/>
        <source>Inv ON/Off-Grid：automatic-&gt;Off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2839"/>
        <source>Bat volage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2855"/>
        <source>Cell voltage(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2859"/>
        <source>Cell voltage(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2863"/>
        <source>Cell temp.(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2867"/>
        <source>Cell temp.(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2895"/>
        <source>Alarm level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1303"/>
        <location filename="../win.cpp" line="3258"/>
        <source>Load power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3273"/>
        <source>DC input Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3273"/>
        <location filename="../win.cpp" line="3282"/>
        <location filename="../win.cpp" line="3291"/>
        <location filename="../win.cpp" line="3300"/>
        <location filename="../win.cpp" line="3309"/>
        <location filename="../win.cpp" line="3318"/>
        <location filename="../win.cpp" line="3327"/>
        <source>On</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3274"/>
        <source>There are two states for a DC circuit breaker: On, Off.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3283"/>
        <source>The DC contactor has two states: On, Off. After the soft start of the DC side is completed, the DC contactor closes. When the DC side of the battery is disconnected and the voltage of the DC bus drops to a certain level, the DC contactor opens.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3292"/>
        <source>The output contactor has two states: On, Off. The output contactor closes after the soft start on the inv. side is completed. The output contactor opens when the converter is shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3300"/>
        <source>Output Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3310"/>
        <source>The grid contactor has two states: On, Off. When the inverter is in grid-connected mode and the grid voltage is normal, the grid contactor is closed. When the inverter is in island mode, the grid contactor is open. In the islanded state, the grid contactor remains open.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3328"/>
        <source>There are two states for the maintenance bypass circuit breaker: On, Off. This circuit breaker is only used for machine maintenance. If maintenance is required, please contact the maintenance personnel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3877"/>
        <source>End time: The system stops automatically running when the system reaches this time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3880"/>
        <source>Start time: When the system reaches this time, it starts to run automatically.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3881"/>
        <source>Select: After this function is enabled, the system automatically runs the selected function mode within the specified period.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4718"/>
        <source>Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:MEGA, LISHEN, PENGHUI, GAOTE, XIENENG, LANLI, SHENLAN, PAINENG, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD, GROUP_STANDARD, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, FARO.                                             
Select AUTO to automatically detect the battery manufacturer protocol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5059"/>
        <source>Non
adjustable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3318"/>
        <source>Grid Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2138"/>
        <source>Alarm icon</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="2975"/>
        <source>Inv. active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="2984"/>
        <source>Inv. reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="2993"/>
        <source>Inv. apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="3003"/>
        <source>Inv. power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1375"/>
        <source>System Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1996"/>
        <source>The converter off switch. Click to turn off the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2000"/>
        <source>The converter standby switch. Click the converter to enter the standby state.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2004"/>
        <source>The converter on switch. Click to turn on the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2138"/>
        <source>Alarm icon: It is not displayed when there is no alarm. When there is a minor alarm, a yellow icon is displayed. When there is a fault alarm, a red icon is displayed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2198"/>
        <source>Display today&apos;s power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2202"/>
        <source>Display this month&apos;s power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2206"/>
        <source>Display this year&apos;s power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2210"/>
        <source>Display total power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2214"/>
        <source>Display today&apos;s power charge amount</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2218"/>
        <source>Display this month&apos;s power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2222"/>
        <source>Display this year&apos;s power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2226"/>
        <source>Display total power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2230"/>
        <source>To view the data of the previous month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2234"/>
        <source>To view the data of the previous year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2246"/>
        <source>To view the data of the next month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2250"/>
        <source>To view the data of the next year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2262"/>
        <source>Export History Records, click here to export the history records to a U disk. The exported file will be named Record.csv, and it needs to be opened with Excel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2266"/>
        <source>Export operation log. Click here to export operation log to U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2270"/>
        <source>Export the battery statistics. Click here to export the battery statistics to the U disk.
The accuracy is 0.1, which means that the obtained data multiplied by 0.1 gives the actual value.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2274"/>
        <source>Eject U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2342"/>
        <source>Battery power-on: This function allows the BMS to send a command to close the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2346"/>
        <source>Battery power-off: This function allows the BMS to send a command to open the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2360"/>
        <source>0 represents an alarm event, and this item will turn red. 1 represents a status event.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2362"/>
        <source>Event start time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2364"/>
        <source>Event end time: &apos;... &apos;indicates that there is no end time,&apos;-&apos; indicates that the event is in progress.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2366"/>
        <source>event description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2367"/>
        <source>event description.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2370"/>
        <source>Converter Standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2371"/>
        <source>The grid contactor connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2372"/>
        <source>The grid breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2373"/>
        <source>The output breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2374"/>
        <source>Buck not softened</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2375"/>
        <source>Contactor off buck</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2377"/>
        <source>The grid breaker disconnected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2684"/>
        <source>System settings operation records.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2840"/>
        <source>Total voltage of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2844"/>
        <source>Total current of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2848"/>
        <source>Battery SOH uploaded from BMS, the percentage of available capacity after full charge compared to the rated capacity.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2852"/>
        <source>Battery SOC uploaded by BMS refers to the current remaining battery capacity percentage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2856"/>
        <source>The highest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2860"/>
        <source>The lowest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2864"/>
        <source>The highest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2868"/>
        <source>The lowest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2872"/>
        <source>The limit of charging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2876"/>
        <source>The limit of discharging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2880"/>
        <source>The allowable charging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2884"/>
        <source>The allowable discharging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2888"/>
        <source>The allowable charging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2892"/>
        <source>The allowable discharging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2899"/>
        <source>Charging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2900"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to charge, Disable indicates the battery is not allowed to charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2903"/>
        <source>Discharging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2904"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to discharge, Disable indicates the battery is not allowed to discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2967"/>
        <source>Inv. side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3336"/>
        <source>Disabled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3346"/>
        <source>There are three states for DC soft start: Not starting, Soft starting, and Complete. Soft start refers to the process in which the converter charges the busbar with the battery during startup, causing the busbar voltage to rise close to the battery voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3355"/>
        <source>Converter states include: OFF, AC Soft Start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Derating grid-on, Standby, Grid-OFF Charge, Constant Voltage Discharge and Constant Voltage Charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3364"/>
        <source>There are three types of reactive power regulation: Disable,PF regulation, and  regulation.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3382"/>
        <source>Signal to start the diesel generator, start the diesel generator when enabled, stop the diesel generator when disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3391"/>
        <source>Dry contact 2 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3400"/>
        <source>Dry contact 3 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3409"/>
        <source>Dry contact EPO：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3418"/>
        <source>Dry contact Shutdown：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3426"/>
        <source>Access signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3427"/>
        <source>Access signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3436"/>
        <source>Full power signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3445"/>
        <source>Smoke alarm signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5762"/>
        <source>Display the current status of the DCAC converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5770"/>
        <source>Current Mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5770"/>
        <source>Display the current control power mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5855"/>
        <source>Make sure to press the EPO button before upgrading.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1919"/>
        <location filename="../win.cpp" line="3453"/>
        <source>Fire fighting signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3454"/>
        <source>Fire fighting signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3469"/>
        <source>automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3481"/>
        <source>AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. When the advanced setting for power control mode is set to Constant Power mode (CP_N&amp;P), a positive value indicates discharging, and a negative value indicates charging.
For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3552"/>
        <source>M_01</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3577"/>
        <source>Grid-on DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3578"/>
        <source>Grid-on DOD, allowable depth of discharge in grid-on mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3586"/>
        <source>Grid-off DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3587"/>
        <source>Grid-off DOD, allowable depth of discharge in grid-off mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3595"/>
        <source>Charge Volt upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3596"/>
        <source>Charging voltage upper limit: When the battery total voltage reaches this value during charging, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3605"/>
        <source>Charging voltage upper limit hysteresis: When the battery is charging, if the battery total voltage reaches the charging voltage upper limit, the converter will shut down. When the battery total voltage drops below the charging voltage upper limit minus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3613"/>
        <source>Discharge Volt lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3614"/>
        <source>Discharge voltage lower limit: When the battery total voltage reaches this value during discharge, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3623"/>
        <source>Discharge voltage lower limit hysteresis: When the battery is discharging, if the battery total voltage drops below the discharge voltage lower limit, the converter will shut down. When the battery total voltage exceeds the discharge voltage lower limit plus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3631"/>
        <source>Charge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3632"/>
        <source>Charging current limit: The maximum allowable current on the battery side to prevent overcurrent during charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3640"/>
        <source>Discharge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3641"/>
        <source>Discharging current limit: The maximum allowable current on the battery side to prevent overcurrent during Discharging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3668"/>
        <source>When the specified SOC is reached, the diesel generator shuts down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3676"/>
        <source>Genertor turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3677"/>
        <source>When the specified SOC is reached, the diesel generator starts.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3734"/>
        <source>Start SOC: In UPS mode, when the battery SOC reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3743"/>
        <source>Stop SOC: In UPS mode, when the battery SOC reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3752"/>
        <source>Start cell voltage: In UPS mode, when the lowest voltage of a battery cell reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3761"/>
        <source>Stop cell voltage: In UPS mode, when the highest voltage of a battery cell reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3770"/>
        <source>Start total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3779"/>
        <source>Stop total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3788"/>
        <source>Backup charging power: In UPS mode, the backup charging power of the converter when the battery starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3797"/>
        <source>Monthly cycling date: On the same day of each month, a deep discharge and recharge will be performed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3811"/>
        <source>The number of battery cells connected in series in the battery stack (based on a 2V unit).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3826"/>
        <source>Charging Current Limit: The maximum allowable current on the battery side to prevent overcurrent during charging. (Upper limit: 0.25C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3831"/>
        <source>Discharge Current Limit: The maximum allowable current on the battery side to prevent overcurrent during discharge. (Upper limit: 0.5C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3836"/>
        <source>Generator Shutdown Voltage: When the specified voltage is reached, the diesel generator will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3841"/>
        <source>Generator Start Voltage: When the specified voltage is reached, the diesel generator will start up.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3845"/>
        <source>Grid-off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3846"/>
        <source>Grid-off discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3850"/>
        <source>Grid-on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3851"/>
        <source>Grid-on discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3856"/>
        <source>Uniform charging to flushing current: Upper limit of 0.025C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3861"/>
        <source>Float turn to uniform charging current: Upper limit of 0.15C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3878"/>
        <source>This working state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3879"/>
        <source>Working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4669"/>
        <source>Battery Types: Lithium, Lead-Acid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4678"/>
        <source>Battery Communication Modes: None, RS485, CAN, Ethernet. (Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as &quot;CAN&quot; or &quot;Ethernet&quot; simultaneously.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4687"/>
        <source>Constant Voltage (CV) mode: The converter will operate in constant voltage mode on the DC side.                                              Constant Current (CC) mode: The converter will operate in constant current mode on the DC side.                                              Constant Power AC (CP_AC) mode: The power level can be set at &quot;constant power.&quot; The value represents the power level, positive for discharge and negative for charge. For example, setting it to -5 means that the AC side will charge the battery with a power of 5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Conversely, setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.                                              Reserved.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4699"/>
        <source>EMS communication methods: RS485, CAN, Ethernet.                                         The setting communication methods are readable and writable in remote mode, and only readable in local mode. The unselected communication methods are only readable in both remote and local mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4709"/>
        <source>Output Power Limit: Restricts the upper limit of the set value for the power on the AC side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="594"/>
        <location filename="../win.cpp" line="4728"/>
        <source>Anti-backflow power tolerance</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4729"/>
        <source>Anti-backflow power tolerance.The default power tolerance is 10 kW. When the output power increases to &quot;output power limit + power tolerance&quot;, the output power will be reduced to &quot;output power limit - power tolerance&quot;.
(Note: This setting only takes effect in the system anti-backflow mode and is used to control the power tolerance at the grid entrance).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="330"/>
        <location filename="../win.cpp" line="4739"/>
        <source>Serial Communication Address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4740"/>
        <source>Serial Communication Address: The default value is 1, adjustable range is between 1 and 255, used for matching address during serial communication.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4749"/>
        <source>Serial Port 2 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 2 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4758"/>
        <source>Serial Port 3 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 3 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4768"/>
        <source>Serial Port 4 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 4 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4777"/>
        <source>Serial Port 5 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 5 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="570"/>
        <location filename="../win.cpp" line="4785"/>
        <source>serial port 6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4786"/>
        <source>Serial Port 6 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 6 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4795"/>
        <source>CAN1 Port: The baud rate for internal communication is 500 kbps by default and cannot be modified. </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4804"/>
        <source>CAN2 Port: Optional baud rates for the CAN2 port include 100, 125, 250, 500, and 800 kbps, with a default baud rate of 500 kbps.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4813"/>
        <source>Protocol version: View the current protocol version. The default protocol version number is V1.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4822"/>
        <source>User password: Available for resetting the user password. The default user password is 123456. (Note: The user password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="442"/>
        <location filename="../win.cpp" line="4830"/>
        <source>Admin password</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4831"/>
        <source>Admin password: Available for resetting the admin password. The default admin password is 888888. (Note: The admin password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4905"/>
        <source>Power change rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4906"/>
        <source>Power change rate: the rate at which power changes within a second .</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4915"/>
        <source>Upper limit of power grid frequency variation: The maximum range of frequency variation allowed on the AC side, which can be selected as 0.2, 0.5, 1, 5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4924"/>
        <source>Lower limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as-0.5, -1, -2, -5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4933"/>
        <source>Upper limit of voltage protection range: The maximum range of voltage variation allowed on the AC side, which can be selected as 10, 15, 20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4942"/>
        <source>Lower limit of voltage protection range: The minimum range of voltage variation allowed on the AC side, which can be selected as -10, -15, -20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4951"/>
        <source>High voltage ride through(HVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4960"/>
        <source>Low voltage ride through(LVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4969"/>
        <source>Prevent islanding effect. When islanding effect is detected (in a photovoltaic grid-on system, when a power outage occurs in the main grid, and the PV grid-connected converter generates power that matches the local load on the low-voltage side of the grid, it can easily sustain power generation independently, resulting in an &apos;island&apos; phenomenon, which endangers the safety of maintenance personnel), the converter automatically shuts down. The options for this feature can be set as &apos;Enable&apos; or &apos;prohibited&apos; .(Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4979"/>
        <source>Insulation detection enable, the insulation resistance should be greater than 33KΩ for normal start-up and operation. If it is less than 33KΩ, it should not start, and an alarm should be triggered. By default, it is disabled, but can be set as &apos;Enable&apos; or &apos;prohibited&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4988"/>
        <source>Primary frequency control enable: When the grid frequency deviates from the rated value, the active power is controlled to increase or decrease in order to maintain the grid frequency at the rated value. It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4997"/>
        <source>Rotational inertia enable: It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5006"/>
        <source>Constant voltage parallel operation enable: It can be selected as enabled or disabled.  (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5015"/>
        <source>Converter Model: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5024"/>
        <source>The rated capacity of the converter shall be based on the factory value and cannot be changed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5033"/>
        <source>Output Frequency Level: Default 50Hz, typically 50Hz or 60Hz.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5042"/>
        <source>Output Voltage Level: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5051"/>
        <source>Transformer Voltage Ratio: To be determined by the factory nameplate, not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5060"/>
        <source>Reactive Power Output Mode: Default non-adjustable, options include Power Factor, Reactive Power, non-adjustable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1195"/>
        <location filename="../win.cpp" line="5068"/>
        <source>Converter Anti-Reverse Flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5069"/>
        <source>Converter Anti-Reverse Flow: Enable, Disable; Enabling prevents converter current from flowing into the grid, while Disabling allows converter current to flow into the grid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5075"/>
        <source>System Anti-Reverse Flow: Enable, Disable;
Enabling prevents system current from flowing into the grid, while Disabling allows system current to flow into the grid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5085"/>
        <source>Frequency Deviation Deadzone: A frequency difference settings to prevent unnecessary frequency regulation actions during minor grid frequency fluctuations. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5094"/>
        <source>Active Frequency Regulation Coefficient: The active frequency regulation coefficient can be configured. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5138"/>
        <source>Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5167"/>
        <source>When the dry contact is enabled, the device will perform the selected action when there is a change in the signal.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5168"/>
        <source>Input Dry Contact:                       
Enabled: Triggers the Action when the dry contact detects a state other than the specified NO/NC.                      
Disabled: No action is taken when the dry contact detects a state other than the specified NO/NC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5177"/>
        <source>DI 1 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5185"/>
        <source>DI 2 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5193"/>
        <source>DI 3 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5201"/>
        <source>DI 4 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5209"/>
        <source>DI 5 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5217"/>
        <source>DI 6 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5328"/>
        <source>DOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5337"/>
        <source>The action performed when the charge ban is triggered;Optional function: NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5346"/>
        <source>The action to be performed when a ban is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5354"/>
        <source>level 1 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5363"/>
        <source>level 2 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5372"/>
        <source>level 3 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5381"/>
        <source>level 1 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5382"/>
        <source>The charging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5390"/>
        <source>level 2 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5391"/>
        <source>The charging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5408"/>
        <source>level 1 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5409"/>
        <source>The discharging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5418"/>
        <source>The discharging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5854"/>
        <source>Upgrade prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5876"/>
        <source>Working mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5877"/>
        <source>When selecting the manual mode, the converter’s operating status, charging or discharging power (active power), reactive power, power factor etc,can be controlled through HMI or EMS.                              When selecting the UPS mode, When the grid side is abnormal, the system will switch from zero power to grid-off discharge mode to provide energy to critical loads. Please go to the &quot;Battery Settings&quot; page to configure this mode. Note: This mode is only applicable to lithium battery mode and requires normal communication between the converter and BMS.                              Peak shaving and valley filling mode is used for peak-valley price arbitrage. The converter can operate according to the local peak-valley electricity price periods. Please set the operating time period, charging or discharging mode, charging or discharging power, and other information on the &quot;Mixed mode&quot; page.
Grid expansion.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5880"/>
        <source>Click to view grid expansion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3480"/>
        <source>Constant power(AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3486"/>
        <source>Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3721"/>
        <source>Grid_capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3733"/>
        <source>Turn_on_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3742"/>
        <source>Turn_off_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3751"/>
        <source>Turn_on_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3760"/>
        <source>Turn_off_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3769"/>
        <source>Turn_on_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3778"/>
        <source>Turn_off_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3787"/>
        <source>UPS_charge_power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3796"/>
        <source>Monthly_cycle_time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3806"/>
        <source>Capacity, the capacity of the lead-acid battery.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3810"/>
        <source>Cell_number_2V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3816"/>
        <source>This is the floating charge voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3821"/>
        <source>This is the filling voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3871"/>
        <source>Start_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3872"/>
        <source>End_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3874"/>
        <source>Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3875"/>
        <source>9:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3876"/>
        <source>10:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4618"/>
        <source>This is the monitoring version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4871"/>
        <source>Energy meter model: The energy meter model is selected according to the type of energy meter that is connected. According to the characteristics and specifications of the connected watt-hour meter, select the corresponding watt-hour meter model, which can be selected NONE, DTSD1352, AMC96-E4/KC or ADL3000-E-B.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9657"/>
        <location filename="../win.cpp" line="3835"/>
        <source>Generator turn off voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9721"/>
        <location filename="../win.cpp" line="3840"/>
        <source>Generator turn on voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="346"/>
        <location filename="../win.cpp" line="4626"/>
        <source>Protocol Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4627"/>
        <source>This is the protocol version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4636"/>
        <source>This is the converter software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4645"/>
        <source>This is the CPLD software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4653"/>
        <source>SN</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4654"/>
        <source>This is SN, the serial number of the product.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8565"/>
        <location filename="../win.cpp" line="4668"/>
        <source>Lithium</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4677"/>
        <source>BMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4698"/>
        <source>EMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4717"/>
        <source>Auto</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="554"/>
        <location filename="../win.cpp" line="4717"/>
        <source>BAT protocol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3650"/>
        <source>Set the charging power limit to allow the maximum power of charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3659"/>
        <source>The discharge power limit is set to allow the maximum power of the discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3604"/>
        <source>Charge Vol upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3622"/>
        <source>Discharge Vol lower Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4839"/>
        <source>English</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4840"/>
        <source>Set the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4853"/>
        <source>upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4861"/>
        <source>Allow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4862"/>
        <source>Set whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4870"/>
        <source>NONE</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4879"/>
        <source>20</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4879"/>
        <source>Bms Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4880"/>
        <source>BMS communication fault determination time: The BMS communication fault determination time refers to the BMS communication fault when the BMS communication is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4888"/>
        <source>EMS Com. Fault Model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4889"/>
        <source>EMS communication fault determination time: The EMS communication fault determination time refers to the time when the communication between the EMS is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1051"/>
        <location filename="../win.cpp" line="4932"/>
        <source>Vol protection upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1099"/>
        <location filename="../win.cpp" line="4941"/>
        <source>Vol protection lower limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4950"/>
        <location filename="../win.cpp" line="4959"/>
        <location filename="../win.cpp" line="4968"/>
        <location filename="../win.cpp" line="4978"/>
        <location filename="../win.cpp" line="4987"/>
        <location filename="../win.cpp" line="4996"/>
        <location filename="../win.cpp" line="5005"/>
        <source>prohibit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5032"/>
        <source>Output Fre grade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5041"/>
        <source>Output vol level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5103"/>
        <source>Grid restoration time: reserved function, setting invalid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5121"/>
        <source>Number of modules for PCS, default 1(invalid setting).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5129"/>
        <source>restore</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5130"/>
        <source>Restore the factory default Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5138"/>
        <source>Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5139"/>
        <source>Backup setting parameters: Backup setting parameters refers to backing up the parameters set on the current device so that the backup parameter Settings can be restored when needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5147"/>
        <source>Restore Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5147"/>
        <source>Restore
Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5148"/>
        <source>Restore backup setting parameters: Restore backup setting parameters means to restore the device to the last backup setting parameters and restart the device.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5156"/>
        <source>Clear</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5157"/>
        <source>Clear previous recorded data and operation data of the system.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5166"/>
        <source>Normally closed circuit (NC) or normally open circuit (NO) according to field Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5225"/>
        <source>DI_1_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5233"/>
        <source>DI_2_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5241"/>
        <source>DI_3_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5249"/>
        <source>DI_4_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5257"/>
        <source>DI_5_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5265"/>
        <source>DI_6_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5273"/>
        <source>DI_1_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1599"/>
        <location filename="../win.ui" line="1643"/>
        <location filename="../win.ui" line="1687"/>
        <location filename="../win.cpp" line="5281"/>
        <location filename="../win.cpp" line="5289"/>
        <location filename="../win.cpp" line="5297"/>
        <source>Prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5281"/>
        <source>DI_2_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5289"/>
        <source>DI_3_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5297"/>
        <source>DI_4_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5305"/>
        <source>DI_5_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5313"/>
        <source>DI_6_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5327"/>
        <location filename="../win.cpp" line="5336"/>
        <location filename="../win.cpp" line="5345"/>
        <location filename="../win.cpp" line="5363"/>
        <source>Standby</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5354"/>
        <source>NO action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5355"/>
        <source>Action to be performed when level 1 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5364"/>
        <source>Action to be performed when level 2 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5373"/>
        <source>Action that is performed when level 3 alarm is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5417"/>
        <source>level 2 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5436"/>
        <source>It is used for internal debugging only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5467"/>
        <source>Debug variable 1 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5475"/>
        <source>Debug variable 2 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5483"/>
        <source>Debug variable 3 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5491"/>
        <source>Debug memery var 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5499"/>
        <source>Debug memery var 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5507"/>
        <source>Debug memery var 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5515"/>
        <source>Input Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5523"/>
        <source>Input Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5531"/>
        <source>1.5 Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5539"/>
        <source>Bus Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5547"/>
        <source>Grid A AB Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5555"/>
        <source>Grid B BC Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5563"/>
        <source>Grid C CA Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5571"/>
        <source>Output A Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5579"/>
        <source>Output B Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5587"/>
        <source>Output C Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5595"/>
        <source>INV A Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5603"/>
        <source>INV B Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5611"/>
        <source>INV C Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5619"/>
        <source>INV A ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5627"/>
        <source>INV B ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5635"/>
        <source>INV_C_ind_Cur_revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5731"/>
        <source>static</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5731"/>
        <source>If this parameter is selected, static IP addresses are used.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5754"/>
        <source>This is an automatic IP acquisition, currently not supported.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5754"/>
        <source>dhcp</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5778"/>
        <source>Call in test data (for internal testing personnel only).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5786"/>
        <source>Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5786"/>
        <source>Click here to modify the time displayed on the HMI.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3542"/>
        <source>Local</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3561"/>
        <source>Parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4701"/>
        <location filename="../win.cpp" line="3327"/>
        <source>Maintenance Bypass Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3345"/>
        <source>Not starting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3354"/>
        <location filename="../win.cpp" line="5273"/>
        <location filename="../win.cpp" line="5305"/>
        <location filename="../win.cpp" line="5313"/>
        <location filename="../win.cpp" line="5372"/>
        <source>Shut down</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3363"/>
        <source>Reactive Power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1577"/>
        <location filename="../win.ui" line="1621"/>
        <location filename="../win.ui" line="1665"/>
        <location filename="../win.cpp" line="3381"/>
        <location filename="../win.cpp" line="5177"/>
        <location filename="../win.cpp" line="5193"/>
        <location filename="../win.cpp" line="5201"/>
        <location filename="../win.cpp" line="5209"/>
        <location filename="../win.cpp" line="5217"/>
        <source>Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3982"/>
        <source>PCS voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3992"/>
        <source>PCS voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4002"/>
        <source>PCS voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4012"/>
        <source>PCS current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4022"/>
        <source>PCS current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4032"/>
        <source>PCS current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4042"/>
        <source>PCS Active P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4047"/>
        <source>PCS Reactive P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4052"/>
        <source>PCS Parent P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4057"/>
        <source>PCS Pf</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3987"/>
        <location filename="../win.cpp" line="1200"/>
        <location filename="../win.cpp" line="3012"/>
        <source>Battery voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3997"/>
        <location filename="../win.cpp" line="1200"/>
        <location filename="../win.cpp" line="3021"/>
        <source>Battery current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4007"/>
        <location filename="../win.cpp" line="1200"/>
        <location filename="../win.cpp" line="3030"/>
        <source>Battery power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4017"/>
        <location filename="../win.cpp" line="1201"/>
        <location filename="../win.cpp" line="3039"/>
        <source>Bus voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4027"/>
        <location filename="../win.cpp" line="1201"/>
        <location filename="../win.cpp" line="3048"/>
        <source>IGBT temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4037"/>
        <location filename="../win.cpp" line="1202"/>
        <location filename="../win.cpp" line="3057"/>
        <source>Environment temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1254"/>
        <location filename="../win.cpp" line="3072"/>
        <source>Grid voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1254"/>
        <location filename="../win.cpp" line="3081"/>
        <source>Grid voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1254"/>
        <location filename="../win.cpp" line="3090"/>
        <source>Grid voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1255"/>
        <location filename="../win.cpp" line="3099"/>
        <source>Grid current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1255"/>
        <location filename="../win.cpp" line="3108"/>
        <source>Grid current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1255"/>
        <location filename="../win.cpp" line="3117"/>
        <source>Grid current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1256"/>
        <location filename="../win.cpp" line="3126"/>
        <source>Grid active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1256"/>
        <location filename="../win.cpp" line="3135"/>
        <source>Grid reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1257"/>
        <location filename="../win.cpp" line="3144"/>
        <source>Grid apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1257"/>
        <location filename="../win.cpp" line="3153"/>
        <source>Grid frequency</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1257"/>
        <location filename="../win.cpp" line="3162"/>
        <source>Grid power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1300"/>
        <location filename="../win.cpp" line="3177"/>
        <source>Load voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1300"/>
        <location filename="../win.cpp" line="3186"/>
        <source>Load voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1300"/>
        <location filename="../win.cpp" line="3195"/>
        <source>Load voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1301"/>
        <location filename="../win.cpp" line="3204"/>
        <source>Load current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1301"/>
        <location filename="../win.cpp" line="3213"/>
        <source>Load current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1301"/>
        <location filename="../win.cpp" line="3222"/>
        <source>Load current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1302"/>
        <location filename="../win.cpp" line="3231"/>
        <source>Load active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1302"/>
        <location filename="../win.cpp" line="3240"/>
        <source>Load reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1303"/>
        <location filename="../win.cpp" line="3249"/>
        <source>Load apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1906"/>
        <location filename="../win.cpp" line="1910"/>
        <source>Maintenance Bypass breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1918"/>
        <source>Access control signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1919"/>
        <location filename="../win.cpp" line="3435"/>
        <source>Full power signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1919"/>
        <location filename="../win.cpp" line="3444"/>
        <source>Smoke alarm signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2287"/>
        <source>This is the interface number, which defaults to eth0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2291"/>
        <source>This is the port number, which defaults to 502 and can be changed as needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2295"/>
        <source>This is the IP address. The default is 192.168.1.100.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2299"/>
        <source>This is the subnet mask, 255.255.255.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2303"/>
        <source>This is the gateway. The default is 192.168.1.1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2307"/>
        <source>This is the server IP address. The default is 192.168.1.200.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1074"/>
        <location filename="../win.cpp" line="2359"/>
        <source>Level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1074"/>
        <location filename="../win.cpp" line="2361"/>
        <source>Start Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1074"/>
        <location filename="../win.cpp" line="2363"/>
        <source>End Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8524"/>
        <location filename="../win.cpp" line="1074"/>
        <source>Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1112"/>
        <location filename="../win.cpp" line="2681"/>
        <source>ModificationTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1112"/>
        <location filename="../win.cpp" line="2683"/>
        <source>RecordEvent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2369"/>
        <source>Power Meter Comm fualttLead-acid abnormal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2682"/>
        <source>Time when the system Settings are modified.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5330"/>
        <location filename="../win.ui" line="5354"/>
        <location filename="../win.ui" line="5378"/>
        <location filename="../win.ui" line="5402"/>
        <location filename="../win.ui" line="5426"/>
        <location filename="../win.ui" line="5450"/>
        <location filename="../win.ui" line="5474"/>
        <location filename="../win.ui" line="5498"/>
        <location filename="../win.ui" line="6060"/>
        <location filename="../win.ui" line="6084"/>
        <location filename="../win.ui" line="6108"/>
        <location filename="../win.ui" line="6132"/>
        <location filename="../win.ui" line="6156"/>
        <location filename="../win.ui" line="6180"/>
        <location filename="../win.ui" line="9434"/>
        <location filename="../win.ui" line="9495"/>
        <location filename="../win.ui" line="9565"/>
        <location filename="../win.ui" line="9629"/>
        <location filename="../win.ui" line="9693"/>
        <location filename="../win.cpp" line="2358"/>
        <location filename="../win.cpp" line="3480"/>
        <source>0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1741"/>
        <source>Change Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1749"/>
        <source>切换语言</source>
        <translation>Change Language</translation>
    </message>
</context>
<context>
    <name>Menu</name>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="14"/>
        <source>Form</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="34"/>
        <source>Host</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="60"/>
        <source>Rt.Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="86"/>
        <source>Record</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="112"/>
        <source>System</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="143"/>
        <source>Turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="169"/>
        <source>Stand-by</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="195"/>
        <source>Turn off</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>Specification</name>
    <message>
        <location filename="../Specification/Specification.cpp" line="36"/>
        <source>OK</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>UpgradeTools</name>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="14"/>
        <source>UpgradeTools</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="43"/>
        <source>MPS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="66"/>
        <source>MPS Upgrade app V2.0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="102"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="502"/>
        <source> Message:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="132"/>
        <source> Mounting finished 
 File checked ok 
 Monitor Upadate file not exited 
 DCAC Upadate file ready 
 DCDC Upadate file not exited 
 Start copying...

 DCAC_Update.hex 
 UPDATE_BEGIN 
 Unknown signal received 
 Unknown signal received 
 Unknown signal received 
 ERASE GOING 
 ERASE GOING 
 BLOCK_DATATRANS_END
 BLOCK_CHECKSUM_OK 
 BLOCK_CHECKSUM_OK
 BLOCK_HEAD_OK
 BLOCK_CHECKSUM_OK
 BLOCK_DATATRANS_END
 BLOCK_HEAD_OK 
</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="174"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="438"/>
        <source>Module number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="230"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="58"/>
        <source>DCDC Upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="251"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="63"/>
        <source>DCAC Upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="274"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="661"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="68"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="94"/>
        <source>Monitor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="295"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="682"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="72"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="98"/>
        <source>Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="316"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="703"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="76"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="102"/>
        <source>Restore</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="339"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="81"/>
        <source>Apply and restart</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="391"/>
        <source>PCS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="414"/>
        <source>PCS Upgrade Tools V2.0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="532"/>
        <source> Mounting finished 
 File checked ok 
 Monitor.hex not exited
 DSPUpadate ok
 Start copying...
 
 DSPUpdate.hex
 UPDATE_BEGIN</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="566"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="121"/>
        <source>Monitor.hex</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="587"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="125"/>
        <source>DSPUpdate.hex</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="612"/>
        <source>Baud rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="636"/>
        <source>500k</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="726"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="106"/>
        <source>DSP Upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="747"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="112"/>
        <source>Restart</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="60"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="65"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="69"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="73"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="77"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="82"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="91"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="95"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="99"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="103"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="108"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="113"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="122"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="126"/>
        <source>OK</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="59"/>
        <source>DCDC Upgrade: Insert a u disk and check for the presence of the DCDC upgrade program &apos;DCDC_Update.hex&apos;. Click on DCDC, and then upgrade the corresponding DCDC module according to the selected module number above.                                
(Note: Before upgrading the DCDC, ensure that the ship mode switch on the DCDC module is set to the OFF position.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="64"/>
        <source>DCAC Upgrade: Insert the u disk and check if there is a DCAC upgrade program called &apos;DCAC_Update.hex&apos;. Click to upgrade the DCAC.                                
(Note: Press the EPO button before upgrading.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="69"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="95"/>
        <source>After inserting the u disk and checking that there is a Monitor upgrade program &apos;Monitor.hex&apos;, click to upgrade the monitor program.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="73"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="99"/>
        <source>Backup: Click to backup the current program files.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="77"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="103"/>
        <source>Restore: Restore to the most recent backup program files.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="82"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="113"/>
        <source>Click to restart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="82"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="113"/>
        <source>Previous Page</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="90"/>
        <source>Baud Rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="91"/>
        <source>Baud Rate: Default is 500k and cannot be modified.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="107"/>
        <source>DSP Upgrade: Insert the u disk and check if there is a DSP upgrade program called &apos;DSPUpdate.hex&apos;. Click to upgrade the DSP.                                
(Note: Press the EPO button before upgrading.))</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="122"/>
        <source>This is the name of the monitoring upgrade program.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="126"/>
        <source>This is the DSP upgrade program name.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
