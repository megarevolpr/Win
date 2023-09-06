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
        <location filename="../win.ui" line="158"/>
        <location filename="../win.ui" line="2656"/>
        <source>Change
Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="187"/>
        <source>Basic settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="222"/>
        <source>Function Setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="268"/>
        <location filename="../win.ui" line="318"/>
        <location filename="../win.ui" line="845"/>
        <location filename="../win.ui" line="905"/>
        <location filename="../win.ui" line="1948"/>
        <location filename="../win.ui" line="2008"/>
        <location filename="../win.ui" line="4258"/>
        <location filename="../win.ui" line="4443"/>
        <location filename="../win.ui" line="4488"/>
        <location filename="../win.ui" line="4533"/>
        <location filename="../win.ui" line="4583"/>
        <location filename="../win.ui" line="4854"/>
        <location filename="../win.ui" line="4899"/>
        <location filename="../win.ui" line="8478"/>
        <location filename="../win.ui" line="8518"/>
        <location filename="../win.ui" line="9015"/>
        <location filename="../win.ui" line="9100"/>
        <location filename="../win.cpp" line="2338"/>
        <location filename="../win.cpp" line="3462"/>
        <location filename="../win.cpp" line="3471"/>
        <source>1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="273"/>
        <location filename="../win.ui" line="323"/>
        <location filename="../win.ui" line="850"/>
        <location filename="../win.ui" line="910"/>
        <location filename="../win.ui" line="1953"/>
        <location filename="../win.ui" line="2013"/>
        <location filename="../win.ui" line="4263"/>
        <location filename="../win.ui" line="4448"/>
        <location filename="../win.ui" line="4493"/>
        <location filename="../win.ui" line="4538"/>
        <location filename="../win.ui" line="4588"/>
        <location filename="../win.ui" line="4859"/>
        <location filename="../win.ui" line="4904"/>
        <location filename="../win.ui" line="8483"/>
        <location filename="../win.ui" line="8526"/>
        <location filename="../win.ui" line="9020"/>
        <location filename="../win.ui" line="9105"/>
        <source>2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="278"/>
        <location filename="../win.ui" line="328"/>
        <location filename="../win.ui" line="855"/>
        <location filename="../win.ui" line="915"/>
        <location filename="../win.ui" line="1958"/>
        <location filename="../win.ui" line="2018"/>
        <location filename="../win.ui" line="4268"/>
        <location filename="../win.ui" line="4453"/>
        <location filename="../win.ui" line="4543"/>
        <location filename="../win.ui" line="4864"/>
        <location filename="../win.ui" line="4909"/>
        <location filename="../win.ui" line="8488"/>
        <location filename="../win.ui" line="8534"/>
        <location filename="../win.ui" line="9025"/>
        <location filename="../win.ui" line="9110"/>
        <source>3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="283"/>
        <location filename="../win.ui" line="333"/>
        <location filename="../win.ui" line="860"/>
        <location filename="../win.ui" line="920"/>
        <location filename="../win.ui" line="1963"/>
        <location filename="../win.ui" line="2023"/>
        <location filename="../win.ui" line="4273"/>
        <location filename="../win.ui" line="4458"/>
        <location filename="../win.ui" line="4548"/>
        <location filename="../win.ui" line="4869"/>
        <location filename="../win.ui" line="4914"/>
        <location filename="../win.ui" line="8493"/>
        <location filename="../win.ui" line="8542"/>
        <location filename="../win.ui" line="9030"/>
        <location filename="../win.ui" line="9115"/>
        <source>4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="288"/>
        <location filename="../win.ui" line="338"/>
        <location filename="../win.ui" line="865"/>
        <location filename="../win.ui" line="925"/>
        <location filename="../win.ui" line="1968"/>
        <location filename="../win.ui" line="2028"/>
        <location filename="../win.ui" line="4278"/>
        <location filename="../win.ui" line="4463"/>
        <location filename="../win.ui" line="4553"/>
        <location filename="../win.ui" line="4874"/>
        <location filename="../win.ui" line="4919"/>
        <location filename="../win.ui" line="8498"/>
        <location filename="../win.ui" line="8547"/>
        <location filename="../win.ui" line="9035"/>
        <location filename="../win.ui" line="9120"/>
        <source>5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="293"/>
        <location filename="../win.ui" line="343"/>
        <location filename="../win.ui" line="870"/>
        <location filename="../win.ui" line="930"/>
        <location filename="../win.ui" line="1973"/>
        <location filename="../win.ui" line="2033"/>
        <location filename="../win.ui" line="4283"/>
        <location filename="../win.ui" line="4468"/>
        <location filename="../win.ui" line="4558"/>
        <location filename="../win.ui" line="4879"/>
        <location filename="../win.ui" line="4924"/>
        <location filename="../win.ui" line="8503"/>
        <location filename="../win.ui" line="8552"/>
        <location filename="../win.ui" line="9040"/>
        <location filename="../win.ui" line="9125"/>
        <source>6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="298"/>
        <location filename="../win.ui" line="348"/>
        <location filename="../win.ui" line="875"/>
        <location filename="../win.ui" line="935"/>
        <location filename="../win.ui" line="1978"/>
        <location filename="../win.ui" line="4288"/>
        <location filename="../win.ui" line="4473"/>
        <location filename="../win.ui" line="4563"/>
        <location filename="../win.ui" line="4884"/>
        <location filename="../win.ui" line="8508"/>
        <location filename="../win.ui" line="9045"/>
        <source>7</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="303"/>
        <location filename="../win.ui" line="353"/>
        <location filename="../win.ui" line="880"/>
        <location filename="../win.ui" line="940"/>
        <location filename="../win.ui" line="1983"/>
        <location filename="../win.ui" line="4293"/>
        <location filename="../win.ui" line="4478"/>
        <location filename="../win.ui" line="4568"/>
        <location filename="../win.ui" line="4889"/>
        <location filename="../win.ui" line="8513"/>
        <location filename="../win.ui" line="9050"/>
        <location filename="../win.ui" line="9695"/>
        <source>8</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="308"/>
        <location filename="../win.ui" line="358"/>
        <location filename="../win.ui" line="885"/>
        <location filename="../win.ui" line="945"/>
        <location filename="../win.ui" line="1988"/>
        <location filename="../win.ui" line="4298"/>
        <location filename="../win.ui" line="4573"/>
        <location filename="../win.ui" line="4894"/>
        <location filename="../win.ui" line="9055"/>
        <location filename="../win.ui" line="9700"/>
        <source>9</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="313"/>
        <location filename="../win.ui" line="890"/>
        <location filename="../win.ui" line="1993"/>
        <location filename="../win.ui" line="4303"/>
        <location filename="../win.ui" line="4483"/>
        <location filename="../win.ui" line="4578"/>
        <location filename="../win.ui" line="9060"/>
        <source>10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="895"/>
        <location filename="../win.ui" line="1998"/>
        <location filename="../win.ui" line="9065"/>
        <source>11</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="900"/>
        <location filename="../win.ui" line="2003"/>
        <location filename="../win.ui" line="9070"/>
        <source>12</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="363"/>
        <location filename="../win.cpp" line="4626"/>
        <source>Battery type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="371"/>
        <location filename="../win.ui" line="387"/>
        <location filename="../win.ui" line="403"/>
        <location filename="../win.ui" line="419"/>
        <location filename="../win.ui" line="451"/>
        <location filename="../win.ui" line="467"/>
        <location filename="../win.ui" line="499"/>
        <location filename="../win.ui" line="515"/>
        <location filename="../win.ui" line="547"/>
        <location filename="../win.ui" line="595"/>
        <location filename="../win.ui" line="611"/>
        <location filename="../win.ui" line="688"/>
        <location filename="../win.ui" line="979"/>
        <location filename="../win.ui" line="1000"/>
        <location filename="../win.ui" line="1053"/>
        <location filename="../win.ui" line="1101"/>
        <location filename="../win.ui" line="1149"/>
        <location filename="../win.ui" line="1197"/>
        <location filename="../win.ui" line="1213"/>
        <location filename="../win.ui" line="1229"/>
        <location filename="../win.ui" line="1245"/>
        <location filename="../win.ui" line="1261"/>
        <location filename="../win.ui" line="1277"/>
        <location filename="../win.ui" line="1293"/>
        <location filename="../win.ui" line="1309"/>
        <location filename="../win.ui" line="1346"/>
        <location filename="../win.ui" line="1378"/>
        <location filename="../win.ui" line="1834"/>
        <location filename="../win.ui" line="1842"/>
        <location filename="../win.ui" line="1850"/>
        <location filename="../win.ui" line="1858"/>
        <location filename="../win.ui" line="1866"/>
        <location filename="../win.ui" line="1874"/>
        <location filename="../win.ui" line="1882"/>
        <location filename="../win.ui" line="1890"/>
        <location filename="../win.ui" line="8573"/>
        <location filename="../win.ui" line="8597"/>
        <location filename="../win.ui" line="8645"/>
        <location filename="../win.ui" line="8669"/>
        <location filename="../win.ui" line="8693"/>
        <location filename="../win.ui" line="8717"/>
        <location filename="../win.ui" line="8765"/>
        <location filename="../win.ui" line="9378"/>
        <location filename="../win.ui" line="9743"/>
        <location filename="../win.ui" line="9775"/>
        <location filename="../win.ui" line="9922"/>
        <location filename="../win.ui" line="9986"/>
        <location filename="../win.ui" line="10050"/>
        <location filename="../win.ui" line="10114"/>
        <source>-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4770"/>
        <source>ProtocolVersion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="411"/>
        <source>BMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="435"/>
        <location filename="../win.ui" line="483"/>
        <location filename="../win.ui" line="531"/>
        <location filename="../win.ui" line="579"/>
        <location filename="../win.ui" line="627"/>
        <source>bps</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4779"/>
        <source>UserPassPort</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="459"/>
        <location filename="../win.cpp" line="4644"/>
        <source>Power control type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="427"/>
        <location filename="../win.cpp" line="4706"/>
        <source>serial port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="507"/>
        <source>EMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="475"/>
        <location filename="../win.cpp" line="4715"/>
        <source>serial port 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="539"/>
        <location filename="../win.cpp" line="4797"/>
        <source>Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="555"/>
        <location filename="../win.cpp" line="4666"/>
        <source>Output power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="563"/>
        <location filename="../win.ui" line="651"/>
        <location filename="../win.ui" line="1037"/>
        <location filename="../win.ui" line="6697"/>
        <location filename="../win.ui" line="6724"/>
        <location filename="../win.ui" line="8621"/>
        <location filename="../win.ui" line="9346"/>
        <location filename="../win.ui" line="9394"/>
        <location filename="../win.ui" line="9410"/>
        <location filename="../win.ui" line="9522"/>
        <source>kW</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="523"/>
        <location filename="../win.cpp" line="4725"/>
        <source>serial port 4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="587"/>
        <source>System upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="571"/>
        <location filename="../win.cpp" line="4734"/>
        <source>serial port 5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="635"/>
        <location filename="../win.cpp" line="4819"/>
        <source>Sounds</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="659"/>
        <location filename="../win.cpp" line="4752"/>
        <source>Can port 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="667"/>
        <location filename="../win.ui" line="720"/>
        <source>kbps</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9386"/>
        <location filename="../win.cpp" line="3607"/>
        <source>Charge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="712"/>
        <location filename="../win.cpp" line="4761"/>
        <source>Can port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9402"/>
        <location filename="../win.cpp" line="3616"/>
        <source>Discharge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9226"/>
        <source>Charge Vol. upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1133"/>
        <location filename="../win.ui" line="1181"/>
        <location filename="../win.ui" line="5920"/>
        <location filename="../win.ui" line="8861"/>
        <location filename="../win.ui" line="9202"/>
        <location filename="../win.ui" line="9234"/>
        <location filename="../win.ui" line="9266"/>
        <location filename="../win.ui" line="9282"/>
        <location filename="../win.ui" line="9298"/>
        <location filename="../win.ui" line="9314"/>
        <location filename="../win.ui" line="9759"/>
        <location filename="../win.ui" line="9791"/>
        <location filename="../win.ui" line="9807"/>
        <location filename="../win.ui" line="9852"/>
        <location filename="../win.ui" line="9868"/>
        <location filename="../win.ui" line="10066"/>
        <location filename="../win.ui" line="10130"/>
        <source>V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9290"/>
        <source>Discharge Vol. lower Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="802"/>
        <source>System parameter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="958"/>
        <source>kW/s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="966"/>
        <location filename="../win.cpp" line="4972"/>
        <source>Machine type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="987"/>
        <location filename="../win.cpp" line="5082"/>
        <source>Module Number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1021"/>
        <location filename="../win.ui" line="1069"/>
        <location filename="../win.ui" line="1085"/>
        <location filename="../win.ui" line="1325"/>
        <source>Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1029"/>
        <location filename="../win.cpp" line="4981"/>
        <source>Machine capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1045"/>
        <location filename="../win.cpp" line="5091"/>
        <source>Restore factory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1077"/>
        <source>Output Fre. grade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1189"/>
        <location filename="../win.cpp" line="5118"/>
        <source>Clear Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1117"/>
        <location filename="../win.ui" line="1165"/>
        <location filename="../win.ui" line="5974"/>
        <location filename="../win.ui" line="6001"/>
        <location filename="../win.ui" line="9138"/>
        <location filename="../win.ui" line="9154"/>
        <location filename="../win.ui" line="9170"/>
        <location filename="../win.ui" line="9186"/>
        <location filename="../win.ui" line="9426"/>
        <location filename="../win.ui" line="9442"/>
        <location filename="../win.ui" line="9458"/>
        <location filename="../win.ui" line="9474"/>
        <location filename="../win.ui" line="9490"/>
        <location filename="../win.ui" line="9506"/>
        <source>%</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1125"/>
        <source>Output vol. level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1205"/>
        <location filename="../win.cpp" line="4908"/>
        <source>HVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1221"/>
        <location filename="../win.cpp" line="5017"/>
        <source>Output reactive power mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1237"/>
        <location filename="../win.cpp" line="4917"/>
        <source>LVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1269"/>
        <location filename="../win.cpp" line="4926"/>
        <source>AFD enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1317"/>
        <location filename="../win.cpp" line="5046"/>
        <source>Primary FM dead zone</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1301"/>
        <location filename="../win.cpp" line="4936"/>
        <source>Insulation detection enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1354"/>
        <location filename="../win.cpp" line="5055"/>
        <source>PFM coeff</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1362"/>
        <source>kW/Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1338"/>
        <location filename="../win.cpp" line="4945"/>
        <source>PrimaryFreq enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1386"/>
        <location filename="../win.cpp" line="5064"/>
        <source>Grid recover time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="736"/>
        <location filename="../win.ui" line="784"/>
        <location filename="../win.ui" line="1394"/>
        <source>s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="41"/>
        <source>PCS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="443"/>
        <source>User PassPort</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="675"/>
        <location filename="../win.cpp" line="4828"/>
        <source>Energy Meter Model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="728"/>
        <source>BMS Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="776"/>
        <source>EMS Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1008"/>
        <location filename="../win.cpp" line="4872"/>
        <source>ULFV</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1061"/>
        <location filename="../win.cpp" line="4881"/>
        <source>LLFV</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1093"/>
        <source>Backup setup parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1141"/>
        <source>Restore backup setup parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1173"/>
        <location filename="../win.cpp" line="5008"/>
        <source>Transformer Turns Ratio</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1285"/>
        <location filename="../win.cpp" line="5036"/>
        <source>System Anti-Reverse Flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1370"/>
        <location filename="../win.cpp" line="4954"/>
        <source>Inertia enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1402"/>
        <location filename="../win.cpp" line="4963"/>
        <source>CV parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1438"/>
        <source>External device</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1478"/>
        <source>DI_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1483"/>
        <source>DI_2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1488"/>
        <source>DI_3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1493"/>
        <source>DI_4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1498"/>
        <source>DI_5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1503"/>
        <source>DI_6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1523"/>
        <source>Enable/Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1528"/>
        <source>NC/NO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1533"/>
        <location filename="../win.ui" line="1819"/>
        <source>Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1538"/>
        <source>Function description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1575"/>
        <source>Access Control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1583"/>
        <source>Full Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1591"/>
        <source>Smoke</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1599"/>
        <source>Temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1618"/>
        <location filename="../win.ui" line="1662"/>
        <location filename="../win.ui" line="1706"/>
        <source>N_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1640"/>
        <source>Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1684"/>
        <location filename="../win.ui" line="1728"/>
        <source>Reserve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1749"/>
        <source>BMS protection</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1789"/>
        <source>DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1794"/>
        <location filename="../win.cpp" line="5298"/>
        <source>Prohibit charging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1799"/>
        <location filename="../win.cpp" line="5307"/>
        <source>Prohibit discharging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1908"/>
        <source>Debug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2038"/>
        <location filename="../win.cpp" line="5405"/>
        <source>Debug variable 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2046"/>
        <source>1.5V Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2054"/>
        <source>INV A inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2059"/>
        <location filename="../win.cpp" line="5413"/>
        <source>Debug variable 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2067"/>
        <source> Bus Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2075"/>
        <source>INV B inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2080"/>
        <location filename="../win.cpp" line="5421"/>
        <source>Debug variable 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2088"/>
        <source>Grid A/AB Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2093"/>
        <source>INV C inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2098"/>
        <source>Debug variable 1 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2106"/>
        <source>Grid B/BC Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2111"/>
        <location filename="../win.cpp" line="5605"/>
        <source>INV On off flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2116"/>
        <source>Debug variable 2 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2124"/>
        <source>Grid C/CA Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2129"/>
        <location filename="../win.cpp" line="5613"/>
        <source>Logic state</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2134"/>
        <source>Debug variable 3 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2142"/>
        <source>Output A Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2147"/>
        <location filename="../win.cpp" line="5621"/>
        <source>INV flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2152"/>
        <source>Debug memery var. 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2160"/>
        <source>Output B Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2165"/>
        <location filename="../win.cpp" line="5629"/>
        <source>Grid flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2170"/>
        <source>Debug memery var. 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2178"/>
        <source>Output C Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2183"/>
        <location filename="../win.cpp" line="5637"/>
        <source>Grid protect flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2188"/>
        <source>Debug memery var. 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2196"/>
        <source>INV A Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2201"/>
        <location filename="../win.cpp" line="5645"/>
        <source>Bat flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2206"/>
        <source>Input Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2214"/>
        <source>INV B Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2219"/>
        <location filename="../win.cpp" line="5653"/>
        <source>DC bus flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2227"/>
        <source>Input. Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2235"/>
        <source>INV C Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2240"/>
        <location filename="../win.cpp" line="5661"/>
        <source>INT main flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2248"/>
        <location filename="../win.cpp" line="5669"/>
        <source>parallel signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2266"/>
        <source>MonitorDebug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2317"/>
        <source>DO control:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2329"/>
        <source>DO_TurnON_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2342"/>
        <source>DO_TurnOFF_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2378"/>
        <source>Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2403"/>
        <source>Local_on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2390"/>
        <source>Local_off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2462"/>
        <location filename="../win.cpp" line="5740"/>
        <source>test data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2698"/>
        <source>100kW - TS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3404"/>
        <location filename="../win.ui" line="3521"/>
        <location filename="../win.ui" line="3582"/>
        <location filename="../win.ui" line="3643"/>
        <location filename="../win.ui" line="3907"/>
        <location filename="../win.ui" line="3923"/>
        <location filename="../win.ui" line="3939"/>
        <source>0A</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3366"/>
        <location filename="../win.ui" line="3505"/>
        <location filename="../win.ui" line="3566"/>
        <location filename="../win.ui" line="3627"/>
        <location filename="../win.ui" line="3753"/>
        <location filename="../win.ui" line="3769"/>
        <location filename="../win.ui" line="3785"/>
        <source>0V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3328"/>
        <source>40%</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3312"/>
        <source>SOC:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4629"/>
        <source>Converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4669"/>
        <source>Grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4709"/>
        <source>Load</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4929"/>
        <location filename="../win.cpp" line="1868"/>
        <location filename="../win.cpp" line="1871"/>
        <source>DC input breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4934"/>
        <location filename="../win.cpp" line="1876"/>
        <location filename="../win.cpp" line="3294"/>
        <source>converter available</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4939"/>
        <source>DO1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4944"/>
        <location filename="../win.cpp" line="1868"/>
        <location filename="../win.cpp" line="1871"/>
        <location filename="../win.cpp" line="3240"/>
        <source>DC contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4949"/>
        <location filename="../win.cpp" line="1876"/>
        <location filename="../win.cpp" line="3303"/>
        <source>DC Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4954"/>
        <location filename="../win.cpp" line="1879"/>
        <location filename="../win.cpp" line="3348"/>
        <source>DO2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4959"/>
        <location filename="../win.cpp" line="1869"/>
        <location filename="../win.cpp" line="1872"/>
        <location filename="../win.cpp" line="3249"/>
        <source>Output contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4964"/>
        <location filename="../win.cpp" line="1877"/>
        <location filename="../win.cpp" line="3312"/>
        <source>converter status</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4969"/>
        <location filename="../win.cpp" line="1880"/>
        <location filename="../win.cpp" line="3357"/>
        <source>DO3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4974"/>
        <location filename="../win.cpp" line="1869"/>
        <location filename="../win.cpp" line="1872"/>
        <source>Output breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4979"/>
        <location filename="../win.cpp" line="1877"/>
        <source>Reactive power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4984"/>
        <source>DI1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4989"/>
        <location filename="../win.cpp" line="1873"/>
        <location filename="../win.cpp" line="3267"/>
        <source>Grid contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4994"/>
        <location filename="../win.cpp" line="1877"/>
        <location filename="../win.cpp" line="3330"/>
        <source>LVRT</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4999"/>
        <source>DI2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5004"/>
        <location filename="../win.cpp" line="1869"/>
        <location filename="../win.cpp" line="1873"/>
        <source>Grid breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5014"/>
        <source>DI3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5024"/>
        <source>DI4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5029"/>
        <source>DI5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5034"/>
        <source>DI6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5209"/>
        <source>Battery Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6859"/>
        <source>prompt:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6887"/>
        <source>Normal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7119"/>
        <source>Alarm level:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7203"/>
        <location filename="../win.ui" line="7262"/>
        <location filename="../win.cpp" line="3321"/>
        <location filename="../win.cpp" line="3330"/>
        <location filename="../win.cpp" line="3348"/>
        <location filename="../win.cpp" line="3357"/>
        <location filename="../win.cpp" line="3366"/>
        <location filename="../win.cpp" line="3375"/>
        <location filename="../win.cpp" line="3384"/>
        <location filename="../win.cpp" line="3393"/>
        <location filename="../win.cpp" line="3402"/>
        <location filename="../win.cpp" line="3411"/>
        <location filename="../win.cpp" line="3519"/>
        <location filename="../win.cpp" line="5026"/>
        <location filename="../win.cpp" line="5036"/>
        <location filename="../win.cpp" line="5147"/>
        <source>Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4308"/>
        <location filename="../win.ui" line="4318"/>
        <location filename="../win.ui" line="5381"/>
        <location filename="../win.ui" line="6153"/>
        <location filename="../win.ui" line="9705"/>
        <location filename="../win.ui" line="9720"/>
        <location filename="../win.cpp" line="1048"/>
        <location filename="../win.cpp" line="1186"/>
        <location filename="../win.cpp" line="1248"/>
        <location filename="../win.cpp" line="1295"/>
        <location filename="../win.cpp" line="1360"/>
        <location filename="../win.cpp" line="1897"/>
        <source>Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4313"/>
        <location filename="../win.ui" line="4323"/>
        <location filename="../win.ui" line="5661"/>
        <location filename="../win.ui" line="6397"/>
        <location filename="../win.ui" line="9710"/>
        <location filename="../win.ui" line="9725"/>
        <location filename="../win.cpp" line="1048"/>
        <location filename="../win.cpp" line="1186"/>
        <location filename="../win.cpp" line="1248"/>
        <location filename="../win.cpp" line="1295"/>
        <location filename="../win.cpp" line="1897"/>
        <source>Value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4846"/>
        <source>120</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5890"/>
        <location filename="../win.ui" line="6616"/>
        <location filename="../win.ui" line="9715"/>
        <location filename="../win.ui" line="9730"/>
        <location filename="../win.cpp" line="1048"/>
        <source>Unit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5947"/>
        <location filename="../win.ui" line="6643"/>
        <location filename="../win.ui" line="6670"/>
        <location filename="../win.ui" line="8813"/>
        <location filename="../win.ui" line="9330"/>
        <location filename="../win.ui" line="9362"/>
        <source>A</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6751"/>
        <location filename="../win.ui" line="6778"/>
        <source>kWh</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5414"/>
        <source>Bat voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1508"/>
        <source>DO_1   </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1513"/>
        <source>DO_2    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1518"/>
        <source>DO_3    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4104"/>
        <source>Converter Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4743"/>
        <location filename="../win.cpp" line="5724"/>
        <source>Converter State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5059"/>
        <source>Converter Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5444"/>
        <location filename="../win.cpp" line="2801"/>
        <source>Bat current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5474"/>
        <location filename="../win.cpp" line="2805"/>
        <source>SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5504"/>
        <location filename="../win.cpp" line="2809"/>
        <source>SOH</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5534"/>
        <source>Cell voltage (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5564"/>
        <source>Cell voltage (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5594"/>
        <source>Cell temp. (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5624"/>
        <source>Cell temp. (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3489"/>
        <source>600</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3480"/>
        <source>100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6028"/>
        <location filename="../win.ui" line="6055"/>
        <location filename="../win.ui" line="9218"/>
        <location filename="../win.ui" line="9250"/>
        <source>mV</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6082"/>
        <location filename="../win.ui" line="6109"/>
        <source>℃</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6180"/>
        <location filename="../win.cpp" line="2829"/>
        <source>Charging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6207"/>
        <location filename="../win.cpp" line="2833"/>
        <source>Discharging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6234"/>
        <location filename="../win.cpp" line="2837"/>
        <source>Allowable charging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6262"/>
        <location filename="../win.cpp" line="2841"/>
        <source>Allowable discharging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6289"/>
        <location filename="../win.cpp" line="2845"/>
        <source>Allowable charging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6316"/>
        <location filename="../win.cpp" line="2849"/>
        <source>Allowable discharging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6943"/>
        <source>Level1 </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6999"/>
        <source>Level2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7055"/>
        <source>Level3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7175"/>
        <source>Charging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7234"/>
        <source>Discharging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7308"/>
        <source>Data report</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7370"/>
        <source>Discharge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7398"/>
        <source>1.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7418"/>
        <location filename="../win.ui" line="7628"/>
        <source>Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7455"/>
        <location filename="../win.ui" line="7503"/>
        <source>339
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7469"/>
        <location filename="../win.ui" line="7676"/>
        <source>Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7517"/>
        <location filename="../win.ui" line="7724"/>
        <source>Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7551"/>
        <source>585.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7565"/>
        <location filename="../win.ui" line="7772"/>
        <source>Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7586"/>
        <source>Charge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7614"/>
        <source>2.4
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7662"/>
        <location filename="../win.ui" line="7710"/>
        <source>2.6
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7758"/>
        <source>184.2
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7863"/>
        <source>M  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7882"/>
        <source>Y  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7918"/>
        <source>M  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7937"/>
        <source>Y  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7966"/>
        <source>Export Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8027"/>
        <source>Note:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8044"/>
        <source>Out put file:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8080"/>
        <source>Log.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8098"/>
        <source>Report.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8143"/>
        <source>Data To Export</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8398"/>
        <source>History Record</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8282"/>
        <location filename="../win.ui" line="8417"/>
        <location filename="../win.cpp" line="2223"/>
        <source>Operation Log</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8447"/>
        <source>Parameter setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8581"/>
        <location filename="../win.cpp" line="3500"/>
        <source>Control mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8605"/>
        <source>Constant power (AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8629"/>
        <location filename="../win.cpp" line="3510"/>
        <source>Machine number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8677"/>
        <source>Parallel </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8653"/>
        <source>Work mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5097"/>
        <source>Please click on &apos;Alarm Information&apos; to enter the query interface
and view the details of the alarm information you have encountered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5158"/>
        <source>Alarm
Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8701"/>
        <location filename="../win.cpp" line="3462"/>
        <source>Output power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8749"/>
        <location filename="../win.cpp" line="3471"/>
        <source>Output reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8797"/>
        <location filename="../win.cpp" line="3480"/>
        <source>Constant current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8845"/>
        <location filename="../win.cpp" line="3489"/>
        <source>Constant voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8955"/>
        <source>  Title</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8975"/>
        <source>Return</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8984"/>
        <source>Battery setup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9560"/>
        <location filename="../win.cpp" line="2299"/>
        <source>Battery power on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9579"/>
        <location filename="../win.cpp" line="2303"/>
        <source>Battery power off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9660"/>
        <location filename="../win.ui" line="9665"/>
        <location filename="../win.ui" line="9670"/>
        <location filename="../win.ui" line="9675"/>
        <location filename="../win.ui" line="9680"/>
        <location filename="../win.ui" line="9685"/>
        <location filename="../win.ui" line="9690"/>
        <source>New Row</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9735"/>
        <location filename="../win.cpp" line="3763"/>
        <source>Capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9751"/>
        <source>Grid off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9767"/>
        <source>Cell number(2V)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9783"/>
        <source>Grid on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9799"/>
        <location filename="../win.cpp" line="3773"/>
        <source>Battery float voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9815"/>
        <source>Shutdown voltage point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9860"/>
        <location filename="../win.cpp" line="3778"/>
        <source>Battery filling voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9876"/>
        <source>Mending center point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9930"/>
        <location filename="../win.cpp" line="3783"/>
        <source>Charge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9938"/>
        <location filename="../win.ui" line="10002"/>
        <location filename="../win.ui" line="10163"/>
        <location filename="../win.ui" line="10179"/>
        <source>C</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9946"/>
        <source>Temperature filling coefficient</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9994"/>
        <location filename="../win.cpp" line="3788"/>
        <source>Discharge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10010"/>
        <source>Mending allowable setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10074"/>
        <source>Temperature alarm upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10138"/>
        <location filename="../win.cpp" line="3813"/>
        <source>Uniform charging and flushing current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10171"/>
        <location filename="../win.cpp" line="3818"/>
        <source>Float turn uniform charging current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9130"/>
        <source>DOD_OnGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8062"/>
        <source>Record.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8183"/>
        <source>status:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8216"/>
        <source>u disk disconnect!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8251"/>
        <location filename="../win.cpp" line="2219"/>
        <source>Historical Failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8316"/>
        <location filename="../win.cpp" line="2227"/>
        <source>Electricity Statistical Table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8347"/>
        <location filename="../win.cpp" line="2231"/>
        <source>Eject U disk</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8557"/>
        <source>Grid conected mode of the converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9146"/>
        <source>Turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9162"/>
        <source>DOD_OffGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9178"/>
        <source>Turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9194"/>
        <source>Charge Vol. upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9210"/>
        <source>Turn on cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9258"/>
        <source>Discharge Vol. lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9242"/>
        <source>Turn off cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9322"/>
        <source>Charge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9274"/>
        <source>Turn on total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9418"/>
        <location filename="../win.cpp" line="3625"/>
        <source>Generator turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9306"/>
        <source>Turn off total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9434"/>
        <source>Generator turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9338"/>
        <source>UPS charge power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9450"/>
        <source>Generator charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9370"/>
        <source>Monthly cycle time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1551"/>
        <source>Dry Contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1567"/>
        <source>Dry Contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1804"/>
        <source>Level 1 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1809"/>
        <source>Level 2 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1814"/>
        <source>Level 3 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1824"/>
        <source>Charge power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1829"/>
        <source>Discharge power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9075"/>
        <source>13</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9080"/>
        <source>14</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9085"/>
        <source>15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9090"/>
        <source>16</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9095"/>
        <source>17</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9354"/>
        <source>Discharge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9466"/>
        <location filename="../win.cpp" line="3652"/>
        <source>Grid charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9482"/>
        <location filename="../win.cpp" line="3661"/>
        <source>Charge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9498"/>
        <location filename="../win.cpp" line="3670"/>
        <source>Discharge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9514"/>
        <source>Grid capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9591"/>
        <source>Lead</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9631"/>
        <source>A1: Generator turn on voltage
B1: Generator turn off voltage
A1 Setting range: [250, 900]
B1 Setting range: [250, 900]
Set rule:B1 - A1 ≥ 10V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10197"/>
        <source>Automatic operation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10211"/>
        <source>SystemInformation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10219"/>
        <source>Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10229"/>
        <location filename="../win.ui" line="10234"/>
        <location filename="../win.ui" line="10239"/>
        <location filename="../win.ui" line="10244"/>
        <location filename="../win.ui" line="10249"/>
        <source>新建行</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10254"/>
        <location filename="../win.ui" line="10259"/>
        <source>新建列</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10264"/>
        <location filename="../win.cpp" line="4575"/>
        <source>Monitoring software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10279"/>
        <source>Protocol version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10284"/>
        <location filename="../win.cpp" line="4593"/>
        <source>Converter software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10289"/>
        <location filename="../win.cpp" line="4602"/>
        <source>CPLD software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10294"/>
        <source>SN:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10305"/>
        <source>Network</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10345"/>
        <source>              interface:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10386"/>
        <source>Port:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10455"/>
        <source>DHCP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10471"/>
        <source>STATIC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10491"/>
        <source>ip：</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10521"/>
        <source>netmask:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10554"/>
        <source>gateway:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10584"/>
        <source>Server ip:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10504"/>
        <source>192 . 168 . 1 . 100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10537"/>
        <source>255 . 255 . 255 . 0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10567"/>
        <source>192 . 168 .  1  . 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10597"/>
        <source> 192 . 168 . 1  . 200</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10624"/>
        <location filename="../win.cpp" line="2268"/>
        <source>Apply and Restart system</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10367"/>
        <source>eth0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10408"/>
        <source>502</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10712"/>
        <source>Menu</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10753"/>
        <source>M_01 Converter turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10788"/>
        <source>Current mode:CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1052"/>
        <source>Advance setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <location filename="../win.cpp" line="3828"/>
        <source>Check</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <source>StartTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <source>EndTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <location filename="../win.cpp" line="3831"/>
        <source>State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <source>Power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2156"/>
        <source>Display today&apos;s AC-side power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2160"/>
        <source>Display this month&apos;s AC-side power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2164"/>
        <source>Display this year&apos;s AC-side power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2168"/>
        <source>Display total AC-side power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2172"/>
        <source>Display today&apos;s AC-side power charge amount</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2176"/>
        <source>Display this month&apos;s AC-side power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2180"/>
        <source>Display this year&apos;s AC-side power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2184"/>
        <source>Display total AC-side power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2854"/>
        <source>Alarm levels uploaded from BMS, level one alarm is yellow, level two alarm is orange, and level three alarm is red;
By default, the converter does not respond to level one and level two alarms, but shuts down in response to level three alarms.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2880"/>
        <source>Inv. side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2889"/>
        <source>Inv. side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2898"/>
        <source>Inv. side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2907"/>
        <source>Inv. side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2916"/>
        <source>Inv. side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2934"/>
        <source>Active power P on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2943"/>
        <source>Reactive power Q on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2952"/>
        <source>Apparent power S on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2962"/>
        <source>Power factor PF on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2971"/>
        <source>Converter battery side voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2980"/>
        <source>Converter battery side current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2989"/>
        <source>Converter battery side power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2998"/>
        <source>Converter bus voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3007"/>
        <source>The IGBT temperature of the converter: The IGBT temperature must not exceed 102°C. Otherwise, the converter will operate at a reduced capacity. It will resume full power operation when the temperature drops to 73°C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3016"/>
        <source>”The ambient temperature.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3031"/>
        <source>Grid side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3040"/>
        <source>Grid side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3049"/>
        <source>Grid side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3058"/>
        <source>Grid side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3067"/>
        <source>Grid side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3076"/>
        <source>Grid side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3085"/>
        <source>Active power P on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3094"/>
        <source>Reactive power Q on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3103"/>
        <source>Apparent power S on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3112"/>
        <source>Frequency on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3121"/>
        <source>Power factor PF on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3136"/>
        <source>Load side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3145"/>
        <source>Load side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3154"/>
        <source>Load side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3163"/>
        <source>Load side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3172"/>
        <source>Load side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3181"/>
        <source>Load side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3190"/>
        <source>Active power P on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3199"/>
        <source>Reactive power Q on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3208"/>
        <source>Apparent power S on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3217"/>
        <source>Power factor PF on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3259"/>
        <source>The output circuit breaker has two states: On, Off. It can only be manually opened and closed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3277"/>
        <source>The power grid circuit breaker has two states: On, Off; The power grid circuit breaker can only be manually disconnected.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3295"/>
        <source>The converter has two states: Enable,Disabled. The converter is enabled when the self-check is successful. Otherwise, the converter is disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3331"/>
        <source>LVRT states : Enable , Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3427"/>
        <source>Grid conected mode of the converter </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3428"/>
        <source>When &quot;Auto&quot; is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).                                               When &quot;Grid-on&quot; is selected, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.                                               When &quot;Grid-off&quot; is selected, the converter operates in grid-off mode (VF).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3439"/>
        <source>AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. When the advanced setting for power control mode is set to Constant Power mode (CP_AC), a positive value indicates discharging, and a negative value indicates charging.
For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3463"/>
        <source>This item can modify the power factor, where the power factor is equal to the ratio of active power to apparent power. A positive value indicates leading reactive power, while a negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3472"/>
        <source>This parameter can change the reactive power Q, positive value indicates leading reactive power, negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3481"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant voltage and modify the voltage value. Converter will operate at the constant voltage value and function as a constant voltage source.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3490"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant current and modify the current value. Converter will charge or discharge the battery with this current value. Positive values represent discharging, while negative values represent charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3501"/>
        <source>Local: Converter control through HMI, In this mode, the EMS can only read and cannot write.
Remote: In remote mode, the EMS can perform both read and write control.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3511"/>
        <source>Device number: You can set ID number, which can be set within the range of M_01 to M_12.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3520"/>
        <source>Parallel operation: When converter operates at grid-off mode in parallel, this item needs to be enabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3643"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3644"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3653"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3662"/>
        <source>Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3671"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3680"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4268"/>
        <location filename="../win.cpp" line="4282"/>
        <location filename="../win.cpp" line="4296"/>
        <location filename="../win.cpp" line="4310"/>
        <location filename="../win.cpp" line="4324"/>
        <location filename="../win.cpp" line="4338"/>
        <location filename="../win.cpp" line="4352"/>
        <location filename="../win.cpp" line="4366"/>
        <location filename="../win.cpp" line="4380"/>
        <location filename="../win.cpp" line="4394"/>
        <source>charge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4275"/>
        <location filename="../win.cpp" line="4289"/>
        <location filename="../win.cpp" line="4303"/>
        <location filename="../win.cpp" line="4317"/>
        <location filename="../win.cpp" line="4331"/>
        <location filename="../win.cpp" line="4345"/>
        <location filename="../win.cpp" line="4359"/>
        <location filename="../win.cpp" line="4373"/>
        <location filename="../win.cpp" line="4387"/>
        <location filename="../win.cpp" line="4401"/>
        <source>discharge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2244"/>
        <source>Interface</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1952"/>
        <location filename="../win.cpp" line="1956"/>
        <location filename="../win.cpp" line="1960"/>
        <location filename="../win.cpp" line="2097"/>
        <location filename="../win.cpp" line="2156"/>
        <location filename="../win.cpp" line="2160"/>
        <location filename="../win.cpp" line="2164"/>
        <location filename="../win.cpp" line="2168"/>
        <location filename="../win.cpp" line="2172"/>
        <location filename="../win.cpp" line="2176"/>
        <location filename="../win.cpp" line="2180"/>
        <location filename="../win.cpp" line="2184"/>
        <location filename="../win.cpp" line="2188"/>
        <location filename="../win.cpp" line="2192"/>
        <location filename="../win.cpp" line="2196"/>
        <location filename="../win.cpp" line="2200"/>
        <location filename="../win.cpp" line="2204"/>
        <location filename="../win.cpp" line="2208"/>
        <location filename="../win.cpp" line="2212"/>
        <location filename="../win.cpp" line="2216"/>
        <location filename="../win.cpp" line="2220"/>
        <location filename="../win.cpp" line="2224"/>
        <location filename="../win.cpp" line="2228"/>
        <location filename="../win.cpp" line="2232"/>
        <location filename="../win.cpp" line="2245"/>
        <location filename="../win.cpp" line="2249"/>
        <location filename="../win.cpp" line="2253"/>
        <location filename="../win.cpp" line="2257"/>
        <location filename="../win.cpp" line="2261"/>
        <location filename="../win.cpp" line="2265"/>
        <location filename="../win.cpp" line="2269"/>
        <location filename="../win.cpp" line="2284"/>
        <location filename="../win.cpp" line="2288"/>
        <location filename="../win.cpp" line="2292"/>
        <location filename="../win.cpp" line="2296"/>
        <location filename="../win.cpp" line="2300"/>
        <location filename="../win.cpp" line="2304"/>
        <location filename="../win.cpp" line="2798"/>
        <location filename="../win.cpp" line="2802"/>
        <location filename="../win.cpp" line="2806"/>
        <location filename="../win.cpp" line="2810"/>
        <location filename="../win.cpp" line="2814"/>
        <location filename="../win.cpp" line="2818"/>
        <location filename="../win.cpp" line="2822"/>
        <location filename="../win.cpp" line="2826"/>
        <location filename="../win.cpp" line="2830"/>
        <location filename="../win.cpp" line="2834"/>
        <location filename="../win.cpp" line="2838"/>
        <location filename="../win.cpp" line="2842"/>
        <location filename="../win.cpp" line="2846"/>
        <location filename="../win.cpp" line="2850"/>
        <location filename="../win.cpp" line="2854"/>
        <location filename="../win.cpp" line="2858"/>
        <location filename="../win.cpp" line="2862"/>
        <location filename="../win.cpp" line="5693"/>
        <location filename="../win.cpp" line="5716"/>
        <location filename="../win.cpp" line="5724"/>
        <location filename="../win.cpp" line="5732"/>
        <location filename="../win.cpp" line="5740"/>
        <location filename="../win.cpp" line="5748"/>
        <location filename="../win.cpp" line="5842"/>
        <source>OK</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1167"/>
        <location filename="../win.cpp" line="2879"/>
        <source>Inv. voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1167"/>
        <location filename="../win.cpp" line="2888"/>
        <source>Inv. voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1167"/>
        <location filename="../win.cpp" line="2897"/>
        <source>Inv. voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1168"/>
        <location filename="../win.cpp" line="2906"/>
        <source>Inv. current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1168"/>
        <location filename="../win.cpp" line="2915"/>
        <source>Inv. current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1168"/>
        <location filename="../win.cpp" line="2924"/>
        <source>Inv. current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1879"/>
        <location filename="../win.cpp" line="3339"/>
        <source>Start Diesel Generator Signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1880"/>
        <location filename="../win.cpp" line="3366"/>
        <source>Dry contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1881"/>
        <location filename="../win.cpp" line="3375"/>
        <source>Dry contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2155"/>
        <source>Discharge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2159"/>
        <source>Discharge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2163"/>
        <source>Discharge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2167"/>
        <source>Discharge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2171"/>
        <source>Charge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2175"/>
        <source>Charge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2179"/>
        <source>Charge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2183"/>
        <source>Charge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2187"/>
        <source>Month-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2191"/>
        <source>Year-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2195"/>
        <source>Daily electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2196"/>
        <source>To view the daily charge and discharge volume, click here to jump to the histogram of daily charge and discharge volume. The horizontal axis is in day, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2199"/>
        <source>Annual electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2200"/>
        <source>To view the annual charge and discharge volume, click here to jump to the histogram of the annual charge and discharge volume, the horizontal axis is in year, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2203"/>
        <source>Month+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2207"/>
        <source>Year+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2211"/>
        <source>Monthly electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2212"/>
        <source>To view the monthly charge and discharge volume, click here to jump to the histogram of monthly charge and discharge volume. The horizontal axis is in month, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2215"/>
        <source>Total electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2216"/>
        <source>To view the total charge and discharge, click here to jump to the overview chart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2248"/>
        <source>Port</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2252"/>
        <source>Ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2256"/>
        <source>Netmask</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2260"/>
        <source>Gateway</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2264"/>
        <source>Serber ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2269"/>
        <source>This is the application and restart the system. After clicking, the system will be restarted. If there is an upgrade of the monitoring screen program, the new monitoring screen program will be used after the restart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2323"/>
        <source>CAN communication failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2326"/>
        <source>Fire alarm (High temp. alarm)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2723"/>
        <source>Power control type：CP_P-&gt;CP_N&amp;&amp;P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2726"/>
        <source>Power control type：CP_N&amp;&amp;P-&gt;CP_P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2729"/>
        <source>Grid Fre Upper limit：0.2-&gt;3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2732"/>
        <source>Grid Fre Upper limit：3-&gt;0.2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2735"/>
        <source>Voltage protection Lower limit：-10-&gt;-15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2738"/>
        <source>Voltage protection Lower limit：-15-&gt;-10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2741"/>
        <source>Operation mode：Prevent countercurrnet-&gt;Peak valley</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2750"/>
        <source>Operation mode：UPS-&gt;Prevent countercurrnet</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2747"/>
        <source>Operation mode：Manual-&gt;UPS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1951"/>
        <source>Turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1955"/>
        <source>Stand-by</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1959"/>
        <source>Turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2283"/>
        <source>DO turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2284"/>
        <source>This is the DO control closure, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2287"/>
        <source>Do turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2288"/>
        <source>This is the DO control off, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2291"/>
        <source>Local on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2292"/>
        <source>This is to start a local soft boot, only for internal debugging use.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2295"/>
        <source>Local off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2296"/>
        <source>This is to turn off the local soft boot for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2744"/>
        <source>Operation mode：Peak valley-&gt;Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2753"/>
        <source>Inv ON/Off-Grid：Off-&gt;automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2756"/>
        <source>Inv ON/Off-Grid：automatic-&gt;Off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2797"/>
        <source>Bat volage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2813"/>
        <source>Cell voltage(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2817"/>
        <source>Cell voltage(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2821"/>
        <source>Cell temp.(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2825"/>
        <source>Cell temp.(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2853"/>
        <source>Alarm level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1281"/>
        <location filename="../win.cpp" line="3216"/>
        <source>Load power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3231"/>
        <source>DC input Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3231"/>
        <location filename="../win.cpp" line="3240"/>
        <location filename="../win.cpp" line="3249"/>
        <location filename="../win.cpp" line="3258"/>
        <location filename="../win.cpp" line="3267"/>
        <location filename="../win.cpp" line="3276"/>
        <location filename="../win.cpp" line="3285"/>
        <source>On</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3232"/>
        <source>There are two states for a DC circuit breaker: On, Off.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3241"/>
        <source>The DC contactor has two states: On, Off. After the soft start of the DC side is completed, the DC contactor closes. When the DC side of the battery is disconnected and the voltage of the DC bus drops to a certain level, the DC contactor opens.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3250"/>
        <source>The output contactor has two states: On, Off. The output contactor closes after the soft start on the inv. side is completed. The output contactor opens when the converter is shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3258"/>
        <source>Output Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3268"/>
        <source>The grid contactor has two states: On, Off. When the inverter is in grid-connected mode and the grid voltage is normal, the grid contactor is closed. When the inverter is in island mode, the grid contactor is open. In the islanded state, the grid contactor remains open.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3286"/>
        <source>There are two states for the maintenance bypass circuit breaker: On, Off. This circuit breaker is only used for machine maintenance. If maintenance is required, please contact the maintenance personnel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3835"/>
        <source>End time: The system stops automatically running when the system reaches this time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3838"/>
        <source>Start time: When the system reaches this time, it starts to run automatically.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3839"/>
        <source>Select: After this function is enabled, the system automatically runs the selected function mode within the specified period.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4676"/>
        <source>Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:MEGA, LISHEN, PENGHUI, GAOTE, XIENENG, LANLI, SHENLAN, PAINENG, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD, GROUP_STANDARD, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, FARO.                                             
Select AUTO to automatically detect the battery manufacturer protocol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5017"/>
        <source>Non
adjustable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3276"/>
        <source>Grid Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2096"/>
        <source>Alarm icon</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1169"/>
        <location filename="../win.cpp" line="2933"/>
        <source>Inv. active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1169"/>
        <location filename="../win.cpp" line="2942"/>
        <source>Inv. reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1169"/>
        <location filename="../win.cpp" line="2951"/>
        <source>Inv. apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1169"/>
        <location filename="../win.cpp" line="2961"/>
        <source>Inv. power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1360"/>
        <source>System Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1952"/>
        <source>The converter off switch. Click to turn off the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1956"/>
        <source>The converter standby switch. Click the converter to enter the standby state.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1960"/>
        <source>The converter on switch. Click to turn on the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2096"/>
        <source>Alarm icon: It is not displayed when there is no alarm. When there is a minor alarm, a yellow icon is displayed. When there is a fault alarm, a red icon is displayed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2188"/>
        <source>To view the data of the previous month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2192"/>
        <source>To view the data of the previous year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2204"/>
        <source>To view the data of the next month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2208"/>
        <source>To view the data of the next year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2220"/>
        <source>Export History Records, click here to export the history records to a U disk. The exported file will be named Record.csv, and it needs to be opened with Excel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2224"/>
        <source>Export operation log. Click here to export operation log to U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2228"/>
        <source>Export the battery statistics. Click here to export the battery statistics to the U disk.
The accuracy is 0.1, which means that the obtained data multiplied by 0.1 gives the actual value.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2232"/>
        <source>Eject U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2300"/>
        <source>Battery power-on: This function allows the BMS to send a command to close the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2304"/>
        <source>Battery power-off: This function allows the BMS to send a command to open the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2318"/>
        <source>0 represents an alarm event, and this item will turn red. 1 represents a status event.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2320"/>
        <source>Event start time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2322"/>
        <source>Event end time: &apos;... &apos;indicates that there is no end time,&apos;-&apos; indicates that the event is in progress.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2324"/>
        <source>event description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2325"/>
        <source>event description.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2328"/>
        <source>Converter Standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2329"/>
        <source>The grid contactor connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2330"/>
        <source>The grid breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2331"/>
        <source>The output breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2332"/>
        <source>Buck not softened</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2333"/>
        <source>Contactor off buck</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2335"/>
        <source>The grid breaker disconnected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2642"/>
        <source>System settings operation records.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2798"/>
        <source>Total voltage of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2802"/>
        <source>Total current of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2806"/>
        <source>Battery SOH uploaded from BMS, the percentage of available capacity after full charge compared to the rated capacity.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2810"/>
        <source>Battery SOC uploaded by BMS refers to the current remaining battery capacity percentage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2814"/>
        <source>The highest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2818"/>
        <source>The lowest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2822"/>
        <source>The highest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2826"/>
        <source>The lowest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2830"/>
        <source>The limit of charging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2834"/>
        <source>The limit of discharging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2838"/>
        <source>The allowable charging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2842"/>
        <source>The allowable discharging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2846"/>
        <source>The allowable charging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2850"/>
        <source>The allowable discharging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2857"/>
        <source>Charging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2858"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to charge, Disable indicates the battery is not allowed to charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2861"/>
        <source>Discharging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2862"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to discharge, Disable indicates the battery is not allowed to discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2925"/>
        <source>Inv. side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3294"/>
        <source>Disabled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3304"/>
        <source>There are three states for DC soft start: Not starting, Soft starting, and Complete. Soft start refers to the process in which the converter charges the busbar with the battery during startup, causing the busbar voltage to rise close to the battery voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3313"/>
        <source>Converter states include: OFF, AC Soft Start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Derating grid-on, Standby, Grid-OFF Charge, Constant Voltage Discharge and Constant Voltage Charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3322"/>
        <source>There are three types of reactive power regulation: Disable,PF regulation, and  regulation.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3340"/>
        <source>Signal to start the diesel generator, start the diesel generator when enabled, stop the diesel generator when disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3349"/>
        <source>Dry contact 2 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3358"/>
        <source>Dry contact 3 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3367"/>
        <source>Dry contact EPO：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3376"/>
        <source>Dry contact Shutdown：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3384"/>
        <source>Access signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3385"/>
        <source>Access signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3394"/>
        <source>Full power signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3403"/>
        <source>Smoke alarm signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4873"/>
        <source>Upper limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as 0.2, 0.5, 1, 5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5724"/>
        <source>Display the current status of the DCAC converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5732"/>
        <source>Current Mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5732"/>
        <source>Display the current control power mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5817"/>
        <source>Make sure to press the EPO button before upgrading.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1882"/>
        <location filename="../win.cpp" line="3411"/>
        <source>Fire fighting signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3412"/>
        <source>Fire fighting signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3427"/>
        <source>automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3510"/>
        <source>M_01</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3535"/>
        <source>Grid-on DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3536"/>
        <source>Grid-on DOD, allowable depth of discharge in grid-on mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3544"/>
        <source>Grid-off DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3545"/>
        <source>Grid-off DOD, allowable depth of discharge in grid-off mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3553"/>
        <source>Charge Volt upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3554"/>
        <source>Charging voltage upper limit: When the battery total voltage reaches this value during charging, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3563"/>
        <source>Charging voltage upper limit hysteresis: When the battery is charging, if the battery total voltage reaches the charging voltage upper limit, the converter will shut down. When the battery total voltage drops below the charging voltage upper limit minus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3571"/>
        <source>Discharge Volt lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3572"/>
        <source>Discharge voltage lower limit: When the battery total voltage reaches this value during discharge, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3581"/>
        <source>Discharge voltage lower limit hysteresis: When the battery is discharging, if the battery total voltage drops below the discharge voltage lower limit, the converter will shut down. When the battery total voltage exceeds the discharge voltage lower limit plus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3589"/>
        <source>Charge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3590"/>
        <source>Charging current limit: The maximum allowable current on the battery side to prevent overcurrent during charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3598"/>
        <source>Discharge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3599"/>
        <source>Discharging current limit: The maximum allowable current on the battery side to prevent overcurrent during Discharging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3626"/>
        <source>When the specified SOC is reached, the diesel generator shuts down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3634"/>
        <source>Genertor turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3635"/>
        <source>When the specified SOC is reached, the diesel generator starts.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3692"/>
        <source>Start SOC: In UPS mode, when the battery SOC reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3701"/>
        <source>Stop SOC: In UPS mode, when the battery SOC reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3710"/>
        <source>Start cell voltage: In UPS mode, when the lowest voltage of a battery cell reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3719"/>
        <source>Stop cell voltage: In UPS mode, when the highest voltage of a battery cell reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3728"/>
        <source>Start total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3737"/>
        <source>Stop total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3746"/>
        <source>Backup charging power: In UPS mode, the backup charging power of the converter when the battery starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3755"/>
        <source>Monthly cycling date: On the same day of each month, a deep discharge and recharge will be performed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3769"/>
        <source>The number of battery cells connected in series in the battery stack (based on a 2V unit).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3784"/>
        <source>Charging Current Limit: The maximum allowable current on the battery side to prevent overcurrent during charging. (Upper limit: 0.25C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3789"/>
        <source>Discharge Current Limit: The maximum allowable current on the battery side to prevent overcurrent during discharge. (Upper limit: 0.5C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3794"/>
        <source>Generator Shutdown Voltage: When the specified voltage is reached, the diesel generator will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3799"/>
        <source>Generator Start Voltage: When the specified voltage is reached, the diesel generator will start up.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3803"/>
        <source>Grid-off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3804"/>
        <source>Grid-off discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3808"/>
        <source>Grid-on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3809"/>
        <source>Grid-on discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3814"/>
        <source>Uniform charging to flushing current: Upper limit of 0.025C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3819"/>
        <source>Float turn to uniform charging current: Upper limit of 0.15C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3836"/>
        <source>This working state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3837"/>
        <source>Working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4627"/>
        <source>Battery Types: Lithium, Lead-Acid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4636"/>
        <source>Battery Communication Modes: None, RS485, CAN, Ethernet. (Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as &quot;CAN&quot; or &quot;Ethernet&quot; simultaneously.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4645"/>
        <source>Constant Voltage (CV) mode: The converter will operate in constant voltage mode on the DC side.                                              Constant Current (CC) mode: The converter will operate in constant current mode on the DC side.                                              Constant Power AC (CP_AC) mode: The power level can be set at &quot;constant power.&quot; The value represents the power level, positive for discharge and negative for charge. For example, setting it to -5 means that the AC side will charge the battery with a power of 5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Conversely, setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.                                              Reserved.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4657"/>
        <source>EMS communication methods: RS485, CAN, Ethernet.                                         The setting communication methods are readable and writable in remote mode, and only readable in local mode. The unselected communication methods are only readable in both remote and local mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4667"/>
        <source>Output Power Limit: Restricts the upper limit of the set value for the power on the AC side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="643"/>
        <location filename="../win.cpp" line="4686"/>
        <source>Anti-backflow power tolerance</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4687"/>
        <source>Anti-backflow power tolerance.The default power tolerance is 10 kW. When the output power increases to &quot;output power limit + power tolerance&quot;, the output power will be reduced to &quot;output power limit - power tolerance&quot;.
(Note: This setting only takes effect in the system anti-backflow mode and is used to control the power tolerance at the grid entrance).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="379"/>
        <location filename="../win.cpp" line="4697"/>
        <source>Serial Communication Address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4698"/>
        <source>Serial Communication Address: The default value is 1, adjustable range is between 1 and 255, used for matching address during serial communication.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4707"/>
        <source>Serial Port 2 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 2 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4716"/>
        <source>Serial Port 3 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 3 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4726"/>
        <source>Serial Port 4 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 4 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4735"/>
        <source>Serial Port 5 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 5 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="619"/>
        <location filename="../win.cpp" line="4743"/>
        <source>serial port 6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4744"/>
        <source>Serial Port 6 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 6 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4753"/>
        <source>CAN1 Port: The baud rate for internal communication is 500 kbps by default and cannot be modified. </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4762"/>
        <source>CAN2 Port: Optional baud rates for the CAN2 port include 100, 125, 250, 500, and 800 kbps, with a default baud rate of 500 kbps.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4771"/>
        <source>Protocol version: View the current protocol version. The default protocol version number is V1.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4780"/>
        <source>User password: Available for resetting the user password. The default user password is 123456. (Note: The user password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="491"/>
        <location filename="../win.cpp" line="4788"/>
        <source>Admin password</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4789"/>
        <source>Admin password: Available for resetting the admin password. The default admin password is 888888. (Note: The admin password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="950"/>
        <location filename="../win.cpp" line="4863"/>
        <source>Power change rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4864"/>
        <source>Power change rate: the rate at which power changes within a second .</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4882"/>
        <source>Lower limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as-0.5, -1, -2, -5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4891"/>
        <source>Upper limit of voltage protection range: The maximum range of voltage variation allowed on the AC side, which can be selected as 10, 15, 20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4900"/>
        <source>Lower limit of voltage protection range: The minimum range of voltage variation allowed on the AC side, which can be selected as -10, -15, -20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4909"/>
        <source>High voltage ride through(HVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4918"/>
        <source>Low voltage ride through(LVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4927"/>
        <source>Prevent islanding effect. When islanding effect is detected (in a photovoltaic grid-on system, when a power outage occurs in the main grid, and the PV grid-connected converter generates power that matches the local load on the low-voltage side of the grid, it can easily sustain power generation independently, resulting in an &apos;island&apos; phenomenon, which endangers the safety of maintenance personnel), the converter automatically shuts down. The options for this feature can be set as &apos;Enable&apos; or &apos;prohibited&apos; .(Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4937"/>
        <source>Insulation detection enable, the insulation resistance should be greater than 33KΩ for normal start-up and operation. If it is less than 33KΩ, it should not start, and an alarm should be triggered. By default, it is disabled, but can be set as &apos;Enable&apos; or &apos;prohibited&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4946"/>
        <source>Primary frequency control enable: When the grid frequency deviates from the rated value, the active power is controlled to increase or decrease in order to maintain the grid frequency at the rated value. It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4955"/>
        <source>Rotational inertia enable: It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4964"/>
        <source>Constant voltage parallel operation enable: It can be selected as enabled or disabled.  (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4973"/>
        <source>Converter Model: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4982"/>
        <source>The rated capacity of the converter shall be based on the factory value and cannot be changed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4991"/>
        <source>Output Frequency Level: Default 50Hz, typically 50Hz or 60Hz.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5000"/>
        <source>Output Voltage Level: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5009"/>
        <source>Transformer Voltage Ratio: To be determined by the factory nameplate, not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5018"/>
        <source>Reactive Power Output Mode: Default non-adjustable, options include Power Factor, Reactive Power, non-adjustable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1253"/>
        <location filename="../win.cpp" line="5026"/>
        <source>Converter Anti-Reverse Flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5027"/>
        <source>Converter Anti-Reverse Flow: Enable, Disable; Enabling prevents converter current from flowing into the grid, while Disabling allows converter current to flow into the grid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5037"/>
        <source>System Anti-Reverse Flow: Enable, Disable;
Enabling prevents system current from flowing into the grid, while Disabling allows system current to flow into the grid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5047"/>
        <source>Frequency Deviation Deadzone: A frequency difference settings to prevent unnecessary frequency regulation actions during minor grid frequency fluctuations. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5056"/>
        <source>Active Frequency Regulation Coefficient: The active frequency regulation coefficient can be configured. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5100"/>
        <source>Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5129"/>
        <source>When the dry contact is enabled, the device will perform the selected action when there is a change in the signal.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5130"/>
        <source>Input Dry Contact:                       
Enabled: Triggers the Action when the dry contact detects a state other than the specified NO/NC.                      
Disabled: No action is taken when the dry contact detects a state other than the specified NO/NC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5139"/>
        <source>DI 1 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5147"/>
        <source>DI 2 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5155"/>
        <source>DI 3 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5163"/>
        <source>DI 4 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5171"/>
        <source>DI 5 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5179"/>
        <source>DI 6 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5290"/>
        <source>DOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5299"/>
        <source>The action performed when the charge ban is triggered;Optional function: NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5308"/>
        <source>The action to be performed when a ban is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5316"/>
        <source>level 1 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5325"/>
        <source>level 2 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5334"/>
        <source>level 3 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5343"/>
        <source>level 1 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5344"/>
        <source>The charging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5352"/>
        <source>level 2 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5353"/>
        <source>The charging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5370"/>
        <source>level 1 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5371"/>
        <source>The discharging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5380"/>
        <source>The discharging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5816"/>
        <source>Upgrade prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5817"/>
        <source>NEXT</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5817"/>
        <source>Cancel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5838"/>
        <source>Working mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5839"/>
        <source>When selecting the manual mode, the converter’s operating status, charging or discharging power (active power), reactive power, power factor etc,can be controlled through HMI or EMS.                              When selecting the UPS mode, When the grid side is abnormal, the system will switch from zero power to grid-off discharge mode to provide energy to critical loads. Please go to the &quot;Battery Settings&quot; page to configure this mode. Note: This mode is only applicable to lithium battery mode and requires normal communication between the converter and BMS.                              Peak shaving and valley filling mode is used for peak-valley price arbitrage. The converter can operate according to the local peak-valley electricity price periods. Please set the operating time period, charging or discharging mode, charging or discharging power, and other information on the &quot;Mixed mode&quot; page.
Grid expansion.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5842"/>
        <source>Click to view grid expansion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3438"/>
        <source>Constant power(AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3444"/>
        <source>Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3679"/>
        <source>Grid_capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3691"/>
        <source>Turn_on_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3700"/>
        <source>Turn_off_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3709"/>
        <source>Turn_on_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3718"/>
        <source>Turn_off_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3727"/>
        <source>Turn_on_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3736"/>
        <source>Turn_off_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3745"/>
        <source>UPS_charge_power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3754"/>
        <source>Monthly_cycle_time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3764"/>
        <source>Capacity, the capacity of the lead-acid battery.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3768"/>
        <source>Cell_number_2V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3774"/>
        <source>This is the floating charge voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3779"/>
        <source>This is the filling voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3829"/>
        <source>Start_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3830"/>
        <source>End_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3832"/>
        <source>Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3833"/>
        <source>9:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3834"/>
        <source>10:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4576"/>
        <source>This is the monitoring version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4829"/>
        <source>Energy meter model: The energy meter model is selected according to the type of energy meter that is connected. According to the characteristics and specifications of the connected watt-hour meter, select the corresponding watt-hour meter model, which can be selected NONE, DTSD1352, AMC96-E4/KC or ADL3000-E-B.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10058"/>
        <location filename="../win.cpp" line="3793"/>
        <source>Generator turn off voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10122"/>
        <location filename="../win.cpp" line="3798"/>
        <source>Generator turn on voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="395"/>
        <location filename="../win.cpp" line="4584"/>
        <source>Protocol Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4585"/>
        <source>This is the protocol version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4594"/>
        <source>This is the converter software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4603"/>
        <source>This is the CPLD software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4611"/>
        <source>SN</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4612"/>
        <source>This is SN, the serial number of the product.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8994"/>
        <location filename="../win.cpp" line="4626"/>
        <source>Lithium</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4635"/>
        <source>BMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4656"/>
        <source>EMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4675"/>
        <source>Auto</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="603"/>
        <location filename="../win.cpp" line="4675"/>
        <source>BAT protocol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3608"/>
        <source>Set the charging power limit to allow the maximum power of charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3617"/>
        <source>The discharge power limit is set to allow the maximum power of the discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3562"/>
        <source>Charge Vol upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3580"/>
        <source>Discharge Vol lower Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4797"/>
        <source>English</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4798"/>
        <source>Set the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4811"/>
        <source>upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4819"/>
        <source>Allow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4820"/>
        <source>Set whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4828"/>
        <source>NONE</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4837"/>
        <source>20</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4837"/>
        <source>Bms Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4838"/>
        <source>BMS communication fault determination time: The BMS communication fault determination time refers to the BMS communication fault when the BMS communication is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4846"/>
        <source>EMS Com. Fault Model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4847"/>
        <source>EMS communication fault determination time: The EMS communication fault determination time refers to the time when the communication between the EMS is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1109"/>
        <location filename="../win.cpp" line="4890"/>
        <source>Vol protection upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1157"/>
        <location filename="../win.cpp" line="4899"/>
        <source>Vol protection lower limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4908"/>
        <location filename="../win.cpp" line="4917"/>
        <location filename="../win.cpp" line="4926"/>
        <location filename="../win.cpp" line="4936"/>
        <location filename="../win.cpp" line="4945"/>
        <location filename="../win.cpp" line="4954"/>
        <location filename="../win.cpp" line="4963"/>
        <source>prohibit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4990"/>
        <source>Output Fre grade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4999"/>
        <source>Output vol level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5065"/>
        <source>Grid restoration time: reserved function, setting invalid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5083"/>
        <source>Number of modules for PCS, default 1(invalid setting).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5091"/>
        <source>restore</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5092"/>
        <source>Restore the factory default Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5100"/>
        <source>Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5101"/>
        <source>Backup setting parameters: Backup setting parameters refers to backing up the parameters set on the current device so that the backup parameter Settings can be restored when needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5109"/>
        <source>Restore Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5109"/>
        <source>Restore
Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5110"/>
        <source>Restore backup setting parameters: Restore backup setting parameters means to restore the device to the last backup setting parameters and restart the device.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5118"/>
        <source>Clear</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5119"/>
        <source>Clear previous recorded data and operation data of the system.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5128"/>
        <source>Normally closed circuit (NC) or normally open circuit (NO) according to field Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5187"/>
        <source>DI_1_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5195"/>
        <source>DI_2_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5203"/>
        <source>DI_3_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5211"/>
        <source>DI_4_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5219"/>
        <source>DI_5_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5227"/>
        <source>DI_6_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5235"/>
        <source>DI_1_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1629"/>
        <location filename="../win.ui" line="1673"/>
        <location filename="../win.ui" line="1717"/>
        <location filename="../win.cpp" line="5243"/>
        <location filename="../win.cpp" line="5251"/>
        <location filename="../win.cpp" line="5259"/>
        <source>Prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5243"/>
        <source>DI_2_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5251"/>
        <source>DI_3_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5259"/>
        <source>DI_4_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5267"/>
        <source>DI_5_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5275"/>
        <source>DI_6_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5289"/>
        <location filename="../win.cpp" line="5298"/>
        <location filename="../win.cpp" line="5307"/>
        <location filename="../win.cpp" line="5325"/>
        <source>Standby</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5316"/>
        <source>NO action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5317"/>
        <source>Action to be performed when level 1 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5326"/>
        <source>Action to be performed when level 2 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5335"/>
        <source>Action that is performed when level 3 alarm is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5379"/>
        <source>level 2 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5398"/>
        <source>It is used for internal debugging only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5429"/>
        <source>Debug variable 1 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5437"/>
        <source>Debug variable 2 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5445"/>
        <source>Debug variable 3 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5453"/>
        <source>Debug memery var 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5461"/>
        <source>Debug memery var 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5469"/>
        <source>Debug memery var 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5477"/>
        <source>Input Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5485"/>
        <source>Input Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5493"/>
        <source>1.5 Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5501"/>
        <source>Bus Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5509"/>
        <source>Grid A AB Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5517"/>
        <source>Grid B BC Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5525"/>
        <source>Grid C CA Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5533"/>
        <source>Output A Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5541"/>
        <source>Output B Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5549"/>
        <source>Output C Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5557"/>
        <source>INV A Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5565"/>
        <source>INV B Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5573"/>
        <source>INV C Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5581"/>
        <source>INV A ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5589"/>
        <source>INV B ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5597"/>
        <source>INV_C_ind_Cur_revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5693"/>
        <source>static</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5693"/>
        <source>If this parameter is selected, static IP addresses are used.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5716"/>
        <source>This is an automatic IP acquisition, currently not supported.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5716"/>
        <source>dhcp</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5740"/>
        <source>Call in test data (for internal testing personnel only).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5748"/>
        <source>Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5748"/>
        <source>Click here to modify the time displayed on the HMI.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3500"/>
        <source>Local</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3519"/>
        <source>Parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5019"/>
        <location filename="../win.cpp" line="3285"/>
        <source>Maintenance Bypass Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3303"/>
        <source>Not starting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3312"/>
        <location filename="../win.cpp" line="5235"/>
        <location filename="../win.cpp" line="5267"/>
        <location filename="../win.cpp" line="5275"/>
        <location filename="../win.cpp" line="5334"/>
        <source>Shut down</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3321"/>
        <source>Reactive Power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1607"/>
        <location filename="../win.ui" line="1651"/>
        <location filename="../win.ui" line="1695"/>
        <location filename="../win.cpp" line="3339"/>
        <location filename="../win.cpp" line="5139"/>
        <location filename="../win.cpp" line="5155"/>
        <location filename="../win.cpp" line="5163"/>
        <location filename="../win.cpp" line="5171"/>
        <location filename="../win.cpp" line="5179"/>
        <source>Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4328"/>
        <source>PCS voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4338"/>
        <source>PCS voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4348"/>
        <source>PCS voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4358"/>
        <source>PCS current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4368"/>
        <source>PCS current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4378"/>
        <source>PCS current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4388"/>
        <source>PCS Active P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4393"/>
        <source>PCS Reactive P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4398"/>
        <source>PCS Parent P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4403"/>
        <source>PCS Pf</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4333"/>
        <location filename="../win.cpp" line="1171"/>
        <location filename="../win.cpp" line="2970"/>
        <source>Battery voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4343"/>
        <location filename="../win.cpp" line="1171"/>
        <location filename="../win.cpp" line="2979"/>
        <source>Battery current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4353"/>
        <location filename="../win.cpp" line="1171"/>
        <location filename="../win.cpp" line="2988"/>
        <source>Battery power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4363"/>
        <location filename="../win.cpp" line="1172"/>
        <location filename="../win.cpp" line="2997"/>
        <source>Bus voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4373"/>
        <location filename="../win.cpp" line="1172"/>
        <location filename="../win.cpp" line="3006"/>
        <source>IGBT temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4383"/>
        <location filename="../win.cpp" line="1173"/>
        <location filename="../win.cpp" line="3015"/>
        <source>Environment temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1229"/>
        <location filename="../win.cpp" line="3030"/>
        <source>Grid voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1229"/>
        <location filename="../win.cpp" line="3039"/>
        <source>Grid voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1229"/>
        <location filename="../win.cpp" line="3048"/>
        <source>Grid voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1230"/>
        <location filename="../win.cpp" line="3057"/>
        <source>Grid current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1230"/>
        <location filename="../win.cpp" line="3066"/>
        <source>Grid current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1230"/>
        <location filename="../win.cpp" line="3075"/>
        <source>Grid current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1231"/>
        <location filename="../win.cpp" line="3084"/>
        <source>Grid active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1231"/>
        <location filename="../win.cpp" line="3093"/>
        <source>Grid reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1232"/>
        <location filename="../win.cpp" line="3102"/>
        <source>Grid apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1232"/>
        <location filename="../win.cpp" line="3111"/>
        <source>Grid frequency</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1232"/>
        <location filename="../win.cpp" line="3120"/>
        <source>Grid power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1278"/>
        <location filename="../win.cpp" line="3135"/>
        <source>Load voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1278"/>
        <location filename="../win.cpp" line="3144"/>
        <source>Load voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1278"/>
        <location filename="../win.cpp" line="3153"/>
        <source>Load voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1279"/>
        <location filename="../win.cpp" line="3162"/>
        <source>Load current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1279"/>
        <location filename="../win.cpp" line="3171"/>
        <source>Load current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1279"/>
        <location filename="../win.cpp" line="3180"/>
        <source>Load current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1280"/>
        <location filename="../win.cpp" line="3189"/>
        <source>Load active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1280"/>
        <location filename="../win.cpp" line="3198"/>
        <source>Load reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1281"/>
        <location filename="../win.cpp" line="3207"/>
        <source>Load apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1869"/>
        <location filename="../win.cpp" line="1873"/>
        <source>Maintenance Bypass breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1881"/>
        <source>Access control signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1882"/>
        <location filename="../win.cpp" line="3393"/>
        <source>Full power signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1882"/>
        <location filename="../win.cpp" line="3402"/>
        <source>Smoke alarm signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2245"/>
        <source>This is the interface number, which defaults to eth0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2249"/>
        <source>This is the port number, which defaults to 502 and can be changed as needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2253"/>
        <source>This is the IP address. The default is 192.168.1.100.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2257"/>
        <source>This is the subnet mask, 255.255.255.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2261"/>
        <source>This is the gateway. The default is 192.168.1.1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2265"/>
        <source>This is the server IP address. The default is 192.168.1.200.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1065"/>
        <location filename="../win.cpp" line="2317"/>
        <source>Level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1065"/>
        <location filename="../win.cpp" line="2319"/>
        <source>Start Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1065"/>
        <location filename="../win.cpp" line="2321"/>
        <source>End Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8965"/>
        <location filename="../win.cpp" line="1065"/>
        <source>Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1103"/>
        <location filename="../win.cpp" line="2639"/>
        <source>ModificationTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1103"/>
        <location filename="../win.cpp" line="2641"/>
        <source>RecordEvent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2327"/>
        <source>Power Meter Comm fualttLead-acid abnormal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2640"/>
        <source>Time when the system Settings are modified.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5688"/>
        <location filename="../win.ui" line="5712"/>
        <location filename="../win.ui" line="5736"/>
        <location filename="../win.ui" line="5760"/>
        <location filename="../win.ui" line="5784"/>
        <location filename="../win.ui" line="5808"/>
        <location filename="../win.ui" line="5832"/>
        <location filename="../win.ui" line="5856"/>
        <location filename="../win.ui" line="6424"/>
        <location filename="../win.ui" line="6448"/>
        <location filename="../win.ui" line="6472"/>
        <location filename="../win.ui" line="6496"/>
        <location filename="../win.ui" line="6520"/>
        <location filename="../win.ui" line="6544"/>
        <location filename="../win.ui" line="9835"/>
        <location filename="../win.ui" line="9896"/>
        <location filename="../win.ui" line="9966"/>
        <location filename="../win.ui" line="10030"/>
        <location filename="../win.ui" line="10094"/>
        <location filename="../win.cpp" line="2316"/>
        <location filename="../win.cpp" line="3438"/>
        <source>0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1719"/>
        <source>Change Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1727"/>
        <source>切换语言</source>
        <translation>Change Language</translation>
    </message>
</context>
<context>
    <name>Menu</name>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="20"/>
        <source>Form</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="49"/>
        <source>Host</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="80"/>
        <source>Rt.Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="115"/>
        <source>Record</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="146"/>
        <source>System</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="186"/>
        <source>Turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="217"/>
        <source>Stand-by</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="248"/>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="91"/>
        <source>Monitor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="295"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="682"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="72"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="95"/>
        <source>Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="316"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="703"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="76"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="99"/>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="115"/>
        <source>Monitor.hex</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="587"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="119"/>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="103"/>
        <source>DSP Upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="747"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="109"/>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="88"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="92"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="96"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="100"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="105"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="110"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="116"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="120"/>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="92"/>
        <source>After inserting the u disk and checking that there is a Monitor upgrade program &apos;Monitor.hex&apos;, click to upgrade the monitor program.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="73"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="96"/>
        <source>Backup: Click to backup the current program files.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="77"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="100"/>
        <source>Restore: Restore to the most recent backup program files.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="82"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="110"/>
        <source>Click to restart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="87"/>
        <source>Baud Rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="88"/>
        <source>Baud Rate: Default is 500k and cannot be modified.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="104"/>
        <source>DSP Upgrade: Insert the u disk and check if there is a DSP upgrade program called &apos;DSPUpdate.hex&apos;. Click to upgrade the DSP.                                
(Note: Press the EPO button before upgrading.))</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="116"/>
        <source>This is the name of the monitoring upgrade program.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="120"/>
        <source>This is the DSP upgrade program name.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
