<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="en">
<context>
    <name>FaultTableInterface</name>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="14"/>
        <source>MainWindow</source>
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
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="89"/>
        <source>Battery Cut-off Voltage Protection Logic Explanation for Grid-on and grid-off modes:

Grid-on mode:
  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm &quot;Discharge Not Allowed&quot; will be triggered, and the DCAC converter output power will drop to 0.
  The &quot;Discharge Not Allowed&quot; alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage or when the mode is changed to charging.
  When the battery is charged to the upper limit of the charging voltage, an alarm &quot;Charging Not Allowed&quot; will be triggered. If the DCAC is in charging mode, the charging power will drop to 0. If the DCAC is in discharge mode, it will not be affected.
  The &quot;Charging Not Allowed&quot; alarm will be cleared when the battery voltage is lower than the upper limit of the charging voltage minus the charging hysteresis voltage or when it is in discharge mode.

Grid-off mode:
  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm &quot;Discharge Not Allowed&quot; will be triggered, and the DCAC converter will shut down. The &quot;Discharge Not Allowed&quot; alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage. If there is no shutdown command, the system will resume operation.
  When the battery is charged to the upper limit of the charging voltage, an alarm &quot;Charging Not Allowed&quot; will be triggered. If the DCAC is in charging mode or in grid-off discharge mode, it will not be affected.
  The &quot;Charging Not All</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="51"/>
        <source>Alarm name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="51"/>
        <source>Alarm leve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="51"/>
        <source>Trigger condition</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Response action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Whether to reset
automatically and reset time</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>GridExpansion</name>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="14"/>
        <source>MainWindow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="37"/>
        <source>Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="51"/>
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
        <location filename="../GridExpansion/gridexpansion.cpp" line="39"/>
        <source>Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="39"/>
        <source>Value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="39"/>
        <source>Unit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="47"/>
        <source>0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="50"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="51"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="54"/>
        <source>Charging SOC of Grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="55"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="58"/>
        <source>Charging Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="59"/>
        <source>Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="62"/>
        <source>Discharging Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="63"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="66"/>
        <source>Grid Capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="67"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>MEGAWin</name>
    <message>
        <location filename="../win.ui" line="2403"/>
        <location filename="../win.ui" line="2524"/>
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
        <location filename="../win.ui" line="1910"/>
        <location filename="../win.ui" line="1970"/>
        <location filename="../win.ui" line="3856"/>
        <location filename="../win.ui" line="4044"/>
        <location filename="../win.ui" line="4089"/>
        <location filename="../win.ui" line="4137"/>
        <location filename="../win.ui" line="4187"/>
        <location filename="../win.ui" line="4471"/>
        <location filename="../win.ui" line="4516"/>
        <location filename="../win.ui" line="7962"/>
        <location filename="../win.ui" line="8002"/>
        <location filename="../win.ui" line="8525"/>
        <location filename="../win.ui" line="8610"/>
        <location filename="../win.cpp" line="2382"/>
        <location filename="../win.cpp" line="3465"/>
        <location filename="../win.cpp" line="3474"/>
        <source>1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="224"/>
        <location filename="../win.ui" line="274"/>
        <location filename="../win.ui" line="792"/>
        <location filename="../win.ui" line="852"/>
        <location filename="../win.ui" line="1915"/>
        <location filename="../win.ui" line="1975"/>
        <location filename="../win.ui" line="3861"/>
        <location filename="../win.ui" line="4049"/>
        <location filename="../win.ui" line="4094"/>
        <location filename="../win.ui" line="4142"/>
        <location filename="../win.ui" line="4192"/>
        <location filename="../win.ui" line="4476"/>
        <location filename="../win.ui" line="4521"/>
        <location filename="../win.ui" line="7967"/>
        <location filename="../win.ui" line="8010"/>
        <location filename="../win.ui" line="8530"/>
        <location filename="../win.ui" line="8615"/>
        <source>2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="229"/>
        <location filename="../win.ui" line="279"/>
        <location filename="../win.ui" line="797"/>
        <location filename="../win.ui" line="857"/>
        <location filename="../win.ui" line="1920"/>
        <location filename="../win.ui" line="1980"/>
        <location filename="../win.ui" line="3866"/>
        <location filename="../win.ui" line="4054"/>
        <location filename="../win.ui" line="4147"/>
        <location filename="../win.ui" line="4481"/>
        <location filename="../win.ui" line="4526"/>
        <location filename="../win.ui" line="7972"/>
        <location filename="../win.ui" line="8018"/>
        <location filename="../win.ui" line="8535"/>
        <location filename="../win.ui" line="8620"/>
        <source>3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="234"/>
        <location filename="../win.ui" line="284"/>
        <location filename="../win.ui" line="802"/>
        <location filename="../win.ui" line="862"/>
        <location filename="../win.ui" line="1925"/>
        <location filename="../win.ui" line="1985"/>
        <location filename="../win.ui" line="3871"/>
        <location filename="../win.ui" line="4059"/>
        <location filename="../win.ui" line="4152"/>
        <location filename="../win.ui" line="4486"/>
        <location filename="../win.ui" line="4531"/>
        <location filename="../win.ui" line="7977"/>
        <location filename="../win.ui" line="8026"/>
        <location filename="../win.ui" line="8540"/>
        <location filename="../win.ui" line="8625"/>
        <source>4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="239"/>
        <location filename="../win.ui" line="289"/>
        <location filename="../win.ui" line="807"/>
        <location filename="../win.ui" line="867"/>
        <location filename="../win.ui" line="1930"/>
        <location filename="../win.ui" line="1990"/>
        <location filename="../win.ui" line="3876"/>
        <location filename="../win.ui" line="4064"/>
        <location filename="../win.ui" line="4157"/>
        <location filename="../win.ui" line="4491"/>
        <location filename="../win.ui" line="4536"/>
        <location filename="../win.ui" line="7982"/>
        <location filename="../win.ui" line="8031"/>
        <location filename="../win.ui" line="8545"/>
        <location filename="../win.ui" line="8630"/>
        <source>5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="244"/>
        <location filename="../win.ui" line="294"/>
        <location filename="../win.ui" line="812"/>
        <location filename="../win.ui" line="872"/>
        <location filename="../win.ui" line="1935"/>
        <location filename="../win.ui" line="1995"/>
        <location filename="../win.ui" line="3881"/>
        <location filename="../win.ui" line="4069"/>
        <location filename="../win.ui" line="4162"/>
        <location filename="../win.ui" line="4496"/>
        <location filename="../win.ui" line="4541"/>
        <location filename="../win.ui" line="7987"/>
        <location filename="../win.ui" line="8036"/>
        <location filename="../win.ui" line="8550"/>
        <location filename="../win.ui" line="8635"/>
        <source>6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="249"/>
        <location filename="../win.ui" line="299"/>
        <location filename="../win.ui" line="817"/>
        <location filename="../win.ui" line="877"/>
        <location filename="../win.ui" line="1940"/>
        <location filename="../win.ui" line="3886"/>
        <location filename="../win.ui" line="4074"/>
        <location filename="../win.ui" line="4167"/>
        <location filename="../win.ui" line="4501"/>
        <location filename="../win.ui" line="7992"/>
        <location filename="../win.ui" line="8555"/>
        <source>7</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="254"/>
        <location filename="../win.ui" line="304"/>
        <location filename="../win.ui" line="822"/>
        <location filename="../win.ui" line="882"/>
        <location filename="../win.ui" line="1945"/>
        <location filename="../win.ui" line="3891"/>
        <location filename="../win.ui" line="4079"/>
        <location filename="../win.ui" line="4172"/>
        <location filename="../win.ui" line="4506"/>
        <location filename="../win.ui" line="7997"/>
        <location filename="../win.ui" line="8560"/>
        <location filename="../win.ui" line="9226"/>
        <source>8</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="259"/>
        <location filename="../win.ui" line="309"/>
        <location filename="../win.ui" line="827"/>
        <location filename="../win.ui" line="887"/>
        <location filename="../win.ui" line="1950"/>
        <location filename="../win.ui" line="3896"/>
        <location filename="../win.ui" line="4177"/>
        <location filename="../win.ui" line="4511"/>
        <location filename="../win.ui" line="8565"/>
        <location filename="../win.ui" line="9231"/>
        <source>9</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="264"/>
        <location filename="../win.ui" line="832"/>
        <location filename="../win.ui" line="1955"/>
        <location filename="../win.ui" line="3901"/>
        <location filename="../win.ui" line="4084"/>
        <location filename="../win.ui" line="4182"/>
        <location filename="../win.ui" line="8570"/>
        <source>10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="837"/>
        <location filename="../win.ui" line="1960"/>
        <location filename="../win.ui" line="8575"/>
        <source>11</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="842"/>
        <location filename="../win.ui" line="1965"/>
        <location filename="../win.ui" line="8580"/>
        <source>12</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="314"/>
        <location filename="../win.cpp" line="4628"/>
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
        <location filename="../win.ui" line="1251"/>
        <location filename="../win.ui" line="1288"/>
        <location filename="../win.ui" line="1320"/>
        <location filename="../win.ui" line="1811"/>
        <location filename="../win.ui" line="1819"/>
        <location filename="../win.ui" line="1827"/>
        <location filename="../win.ui" line="1835"/>
        <location filename="../win.ui" line="1843"/>
        <location filename="../win.ui" line="1851"/>
        <location filename="../win.ui" line="1859"/>
        <location filename="../win.ui" line="1867"/>
        <location filename="../win.ui" line="8057"/>
        <location filename="../win.ui" line="8081"/>
        <location filename="../win.ui" line="8129"/>
        <location filename="../win.ui" line="8153"/>
        <location filename="../win.ui" line="8177"/>
        <location filename="../win.ui" line="8201"/>
        <location filename="../win.ui" line="8249"/>
        <location filename="../win.ui" line="8888"/>
        <location filename="../win.ui" line="9274"/>
        <location filename="../win.ui" line="9306"/>
        <location filename="../win.ui" line="9453"/>
        <location filename="../win.ui" line="9517"/>
        <location filename="../win.ui" line="9581"/>
        <location filename="../win.ui" line="9645"/>
        <source>-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4772"/>
        <source>ProtocolVersion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="362"/>
        <source>BMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="378"/>
        <source>serial port 1</source>
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
        <location filename="../win.cpp" line="4781"/>
        <source>UserPassPort</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="410"/>
        <location filename="../win.cpp" line="4646"/>
        <source>Power control type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="426"/>
        <location filename="../win.cpp" line="4708"/>
        <source>serial port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="458"/>
        <source>EMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="474"/>
        <location filename="../win.cpp" line="4717"/>
        <source>serial port 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="490"/>
        <location filename="../win.cpp" line="4799"/>
        <source>Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="506"/>
        <location filename="../win.cpp" line="4668"/>
        <source>Output power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="514"/>
        <location filename="../win.ui" line="602"/>
        <location filename="../win.ui" line="979"/>
        <location filename="../win.ui" line="6268"/>
        <location filename="../win.ui" line="6295"/>
        <location filename="../win.ui" line="8105"/>
        <location filename="../win.ui" line="8856"/>
        <location filename="../win.ui" line="8904"/>
        <location filename="../win.ui" line="8920"/>
        <location filename="../win.ui" line="9032"/>
        <source>kW</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="522"/>
        <location filename="../win.cpp" line="4727"/>
        <source>serial port 4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="538"/>
        <source>System upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="570"/>
        <location filename="../win.cpp" line="4736"/>
        <source>serial port 5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="586"/>
        <location filename="../win.cpp" line="4821"/>
        <source>Sounds</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="610"/>
        <location filename="../win.cpp" line="4754"/>
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
        <location filename="../win.ui" line="8896"/>
        <location filename="../win.cpp" line="3609"/>
        <source>Charge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="663"/>
        <location filename="../win.cpp" line="4763"/>
        <source>Can port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8912"/>
        <location filename="../win.cpp" line="3618"/>
        <source>Discharge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8736"/>
        <source>Charge Vol. upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1075"/>
        <location filename="../win.ui" line="1123"/>
        <location filename="../win.ui" line="5497"/>
        <location filename="../win.ui" line="8345"/>
        <location filename="../win.ui" line="8712"/>
        <location filename="../win.ui" line="8744"/>
        <location filename="../win.ui" line="8776"/>
        <location filename="../win.ui" line="8792"/>
        <location filename="../win.ui" line="8808"/>
        <location filename="../win.ui" line="8824"/>
        <location filename="../win.ui" line="9290"/>
        <location filename="../win.ui" line="9322"/>
        <location filename="../win.ui" line="9338"/>
        <location filename="../win.ui" line="9383"/>
        <location filename="../win.ui" line="9399"/>
        <location filename="../win.ui" line="9597"/>
        <location filename="../win.ui" line="9661"/>
        <source>V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8800"/>
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
        <location filename="../win.cpp" line="4974"/>
        <source>Machine type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="929"/>
        <location filename="../win.cpp" line="5073"/>
        <source>Module Number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="950"/>
        <location filename="../win.cpp" line="4874"/>
        <source>Grid frequency upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="963"/>
        <location filename="../win.ui" line="1011"/>
        <location filename="../win.ui" line="1027"/>
        <location filename="../win.ui" line="1235"/>
        <source>Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="971"/>
        <location filename="../win.cpp" line="4983"/>
        <source>Machine capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="987"/>
        <location filename="../win.cpp" line="5082"/>
        <source>Restore factory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1003"/>
        <location filename="../win.cpp" line="4883"/>
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
        <location filename="../win.cpp" line="5109"/>
        <source>Clear Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1059"/>
        <location filename="../win.ui" line="1107"/>
        <location filename="../win.ui" line="5551"/>
        <location filename="../win.ui" line="5578"/>
        <location filename="../win.ui" line="8648"/>
        <location filename="../win.ui" line="8664"/>
        <location filename="../win.ui" line="8680"/>
        <location filename="../win.ui" line="8696"/>
        <location filename="../win.ui" line="8936"/>
        <location filename="../win.ui" line="8952"/>
        <location filename="../win.ui" line="8968"/>
        <location filename="../win.ui" line="8984"/>
        <location filename="../win.ui" line="9000"/>
        <location filename="../win.ui" line="9016"/>
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
        <location filename="../win.cpp" line="4910"/>
        <source>HVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1163"/>
        <location filename="../win.cpp" line="5019"/>
        <source>Output reactive power mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1179"/>
        <location filename="../win.cpp" line="4919"/>
        <source>LVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1211"/>
        <location filename="../win.cpp" line="4928"/>
        <source>AFD enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1227"/>
        <location filename="../win.cpp" line="5037"/>
        <source>Primary FM dead zone</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1243"/>
        <location filename="../win.cpp" line="4938"/>
        <source>Insulation detection enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1259"/>
        <location filename="../win.cpp" line="5046"/>
        <source>PFM coeff</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1267"/>
        <source>kW/Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1280"/>
        <location filename="../win.cpp" line="4947"/>
        <source>PrimaryFreq enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1296"/>
        <location filename="../win.cpp" line="5055"/>
        <source>Grid recover time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="687"/>
        <location filename="../win.ui" line="735"/>
        <location filename="../win.ui" line="1304"/>
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
        <location filename="../win.cpp" line="4830"/>
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
        <location filename="../win.cpp" line="5010"/>
        <source>Transformer Turns Ratio</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1312"/>
        <location filename="../win.cpp" line="4956"/>
        <source>Inertia enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1336"/>
        <location filename="../win.cpp" line="4965"/>
        <source>CV parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1364"/>
        <source>External device</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1395"/>
        <source>DI_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1405"/>
        <source>DI_2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1415"/>
        <source>DI_3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1425"/>
        <source>DI_4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1435"/>
        <source>DI_5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1445"/>
        <source>DI_6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1485"/>
        <source>Enable/Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1490"/>
        <source>NC/NO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1495"/>
        <location filename="../win.ui" line="1796"/>
        <source>Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1500"/>
        <source>Function description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1537"/>
        <source>Access Control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1545"/>
        <source>Full Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1553"/>
        <source>Smoke</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1561"/>
        <source>Temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1580"/>
        <location filename="../win.ui" line="1624"/>
        <location filename="../win.ui" line="1668"/>
        <source>N_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1602"/>
        <source>Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1646"/>
        <location filename="../win.ui" line="1690"/>
        <source>Reserve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1705"/>
        <source>BMS protection</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1736"/>
        <source>DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1746"/>
        <location filename="../win.cpp" line="5289"/>
        <source>Prohibit charging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1756"/>
        <location filename="../win.cpp" line="5298"/>
        <source>Prohibit discharging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1801"/>
        <source>Charge power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1806"/>
        <source>Discharge power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1879"/>
        <source>Debug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2000"/>
        <location filename="../win.cpp" line="5396"/>
        <source>Debug variable 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2008"/>
        <source>1.5V Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2016"/>
        <source>INV A inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2021"/>
        <location filename="../win.cpp" line="5404"/>
        <source>Debug variable 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2029"/>
        <source> Bus Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2037"/>
        <source>INV B inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2042"/>
        <location filename="../win.cpp" line="5412"/>
        <source>Debug variable 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2050"/>
        <source>Grid A/AB Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2055"/>
        <source>INV C inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2060"/>
        <source>Debug variable 1 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2068"/>
        <source>Grid B/BC Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2073"/>
        <location filename="../win.cpp" line="5596"/>
        <source>INV On off flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2078"/>
        <source>Debug variable 2 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2086"/>
        <source>Grid C/CA Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2091"/>
        <location filename="../win.cpp" line="5604"/>
        <source>Logic state</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2096"/>
        <source>Debug variable 3 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2104"/>
        <source>Output A Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2109"/>
        <location filename="../win.cpp" line="5612"/>
        <source>INV flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2114"/>
        <source>Debug memery var. 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2122"/>
        <source>Output B Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2127"/>
        <location filename="../win.cpp" line="5620"/>
        <source>Grid flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2132"/>
        <source>Debug memery var. 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2140"/>
        <source>Output C Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2145"/>
        <location filename="../win.cpp" line="5628"/>
        <source>Grid protect flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2150"/>
        <source>Debug memery var. 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2158"/>
        <source>INV A Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2163"/>
        <location filename="../win.cpp" line="5636"/>
        <source>Bat flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2168"/>
        <source>Input Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2176"/>
        <source>INV B Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2181"/>
        <location filename="../win.cpp" line="5644"/>
        <source>DC bus flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2189"/>
        <source>Input. Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2197"/>
        <source>INV C Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2202"/>
        <location filename="../win.cpp" line="5652"/>
        <source>INT main flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2210"/>
        <location filename="../win.cpp" line="5660"/>
        <source>parallel signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2220"/>
        <source>MonitorDebug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2232"/>
        <source>DO control:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2244"/>
        <source>DO_TurnON_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2257"/>
        <source>DO_TurnOFF_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2271"/>
        <source>Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2283"/>
        <source>Local_on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2296"/>
        <source>Local_off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2310"/>
        <location filename="../win.cpp" line="5715"/>
        <source>test data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2591"/>
        <source>100kW - TS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4232"/>
        <source>Converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4271"/>
        <source>Grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4310"/>
        <source>Load</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4546"/>
        <location filename="../win.cpp" line="1905"/>
        <location filename="../win.cpp" line="1908"/>
        <source>DC input breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4551"/>
        <location filename="../win.cpp" line="1913"/>
        <location filename="../win.cpp" line="3297"/>
        <source>converter available</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4556"/>
        <source>DO1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4561"/>
        <location filename="../win.cpp" line="1905"/>
        <location filename="../win.cpp" line="1908"/>
        <location filename="../win.cpp" line="3243"/>
        <source>DC contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4566"/>
        <location filename="../win.cpp" line="1913"/>
        <location filename="../win.cpp" line="3306"/>
        <source>DC Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4571"/>
        <location filename="../win.cpp" line="1916"/>
        <location filename="../win.cpp" line="3351"/>
        <source>DO2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4576"/>
        <location filename="../win.cpp" line="1906"/>
        <location filename="../win.cpp" line="1909"/>
        <location filename="../win.cpp" line="3252"/>
        <source>Output contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4581"/>
        <location filename="../win.cpp" line="1914"/>
        <location filename="../win.cpp" line="3315"/>
        <source>converter status</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4586"/>
        <location filename="../win.cpp" line="1917"/>
        <location filename="../win.cpp" line="3360"/>
        <source>DO3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4591"/>
        <location filename="../win.cpp" line="1906"/>
        <location filename="../win.cpp" line="1909"/>
        <source>Output breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4596"/>
        <location filename="../win.cpp" line="1914"/>
        <source>Reactive power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4601"/>
        <source>DI1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4606"/>
        <location filename="../win.cpp" line="1910"/>
        <location filename="../win.cpp" line="3270"/>
        <source>Grid contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4611"/>
        <location filename="../win.cpp" line="1914"/>
        <location filename="../win.cpp" line="3333"/>
        <source>LVRT</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4616"/>
        <source>DI2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4621"/>
        <location filename="../win.cpp" line="1906"/>
        <location filename="../win.cpp" line="1910"/>
        <source>Grid breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4631"/>
        <source>DI3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4641"/>
        <source>DI4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4646"/>
        <source>DI5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4651"/>
        <source>DI6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4780"/>
        <source>Battery Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6427"/>
        <source>prompt:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6452"/>
        <source>Normal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6645"/>
        <source>Alarm level:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6726"/>
        <location filename="../win.ui" line="6782"/>
        <location filename="../win.cpp" line="3324"/>
        <location filename="../win.cpp" line="3351"/>
        <location filename="../win.cpp" line="3360"/>
        <location filename="../win.cpp" line="3369"/>
        <location filename="../win.cpp" line="3378"/>
        <location filename="../win.cpp" line="3387"/>
        <location filename="../win.cpp" line="3396"/>
        <location filename="../win.cpp" line="3405"/>
        <location filename="../win.cpp" line="3414"/>
        <location filename="../win.cpp" line="3521"/>
        <location filename="../win.cpp" line="5138"/>
        <source>Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3906"/>
        <location filename="../win.ui" line="3916"/>
        <location filename="../win.ui" line="4958"/>
        <location filename="../win.ui" line="5727"/>
        <location filename="../win.ui" line="9236"/>
        <location filename="../win.ui" line="9251"/>
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
        <location filename="../win.ui" line="3911"/>
        <location filename="../win.ui" line="3921"/>
        <location filename="../win.ui" line="5238"/>
        <location filename="../win.ui" line="5968"/>
        <location filename="../win.ui" line="9241"/>
        <location filename="../win.ui" line="9256"/>
        <location filename="../win.cpp" line="1044"/>
        <location filename="../win.cpp" line="1215"/>
        <location filename="../win.cpp" line="1270"/>
        <location filename="../win.cpp" line="1314"/>
        <location filename="../win.cpp" line="1931"/>
        <source>Value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4848"/>
        <source>120</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5467"/>
        <location filename="../win.ui" line="6187"/>
        <location filename="../win.ui" line="9246"/>
        <location filename="../win.ui" line="9261"/>
        <location filename="../win.cpp" line="1044"/>
        <source>Unit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5524"/>
        <location filename="../win.ui" line="6214"/>
        <location filename="../win.ui" line="6241"/>
        <location filename="../win.ui" line="8297"/>
        <location filename="../win.ui" line="8840"/>
        <location filename="../win.ui" line="8872"/>
        <source>A</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6322"/>
        <location filename="../win.ui" line="6349"/>
        <source>kWh</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4991"/>
        <source>Bat voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1455"/>
        <source>DO_1   </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1465"/>
        <source>DO_2    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1475"/>
        <source>DO_3    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3713"/>
        <source>Converter Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4342"/>
        <source>Converter State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4676"/>
        <source>Converter Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5021"/>
        <location filename="../win.cpp" line="2804"/>
        <source>Bat current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5051"/>
        <location filename="../win.cpp" line="2808"/>
        <source>SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5081"/>
        <location filename="../win.cpp" line="2812"/>
        <source>SOH</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5111"/>
        <source>Cell voltage (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5141"/>
        <source>Cell voltage (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5171"/>
        <source>Cell temp. (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5201"/>
        <source>Cell temp. (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3492"/>
        <source>600</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3483"/>
        <source>100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5605"/>
        <location filename="../win.ui" line="5632"/>
        <location filename="../win.ui" line="8728"/>
        <location filename="../win.ui" line="8760"/>
        <source>mV</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5659"/>
        <location filename="../win.ui" line="5686"/>
        <source>℃</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5754"/>
        <location filename="../win.cpp" line="2832"/>
        <source>Charging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5781"/>
        <location filename="../win.cpp" line="2836"/>
        <source>Discharging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5808"/>
        <location filename="../win.cpp" line="2840"/>
        <source>Allowable charging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5836"/>
        <location filename="../win.cpp" line="2844"/>
        <source>Allowable discharging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5863"/>
        <location filename="../win.cpp" line="2848"/>
        <source>Allowable charging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5890"/>
        <location filename="../win.cpp" line="2852"/>
        <source>Allowable discharging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6499"/>
        <source>Level1 </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6546"/>
        <source>Level2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6593"/>
        <source>Level3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6698"/>
        <source>Charging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6754"/>
        <source>Discharging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6828"/>
        <source>Data report</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6882"/>
        <source>Discharge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6910"/>
        <source>1.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6936"/>
        <location filename="../win.ui" line="7176"/>
        <source>Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6973"/>
        <location filename="../win.ui" line="7027"/>
        <source>339
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6993"/>
        <location filename="../win.ui" line="7230"/>
        <source>Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7047"/>
        <location filename="../win.ui" line="7284"/>
        <source>Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7081"/>
        <source>585.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7101"/>
        <location filename="../win.ui" line="7338"/>
        <source>Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7128"/>
        <source>Charge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7156"/>
        <source>2.4
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7210"/>
        <location filename="../win.ui" line="7264"/>
        <source>2.6
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7318"/>
        <source>184.2
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7398"/>
        <source>M  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7417"/>
        <source>Y  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7453"/>
        <source>M  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7472"/>
        <source>Y  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7501"/>
        <source>Export Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7539"/>
        <source>Note:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7556"/>
        <source>Out put file:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7592"/>
        <source>Log.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7610"/>
        <source>Report.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7655"/>
        <source>Data To Export</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7885"/>
        <source>History Record</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7800"/>
        <location filename="../win.ui" line="7904"/>
        <location filename="../win.cpp" line="2267"/>
        <source>Operation Log</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7940"/>
        <source>Parameter setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8065"/>
        <location filename="../win.cpp" line="3503"/>
        <source>Control mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8089"/>
        <source>Constant power (AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8113"/>
        <location filename="../win.cpp" line="3512"/>
        <source>Machine number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8161"/>
        <source>Parallel </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8137"/>
        <source>Work mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4713"/>
        <source>Please click on &apos;Alarm Information&apos; to enter the query interface
and view the details of the alarm information you have encountered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4742"/>
        <source>Alarm
Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8185"/>
        <location filename="../win.cpp" line="3465"/>
        <source>Output power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8233"/>
        <location filename="../win.cpp" line="3474"/>
        <source>Output reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8281"/>
        <location filename="../win.cpp" line="3483"/>
        <source>Constant current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8329"/>
        <location filename="../win.cpp" line="3492"/>
        <source>Constant voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8443"/>
        <source>  Title</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8475"/>
        <location filename="../win.cpp" line="5789"/>
        <source>Return</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8484"/>
        <source>Battery setup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9070"/>
        <location filename="../win.cpp" line="2343"/>
        <source>Battery power on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9089"/>
        <location filename="../win.cpp" line="2347"/>
        <source>Battery power off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9191"/>
        <location filename="../win.ui" line="9196"/>
        <location filename="../win.ui" line="9201"/>
        <location filename="../win.ui" line="9206"/>
        <location filename="../win.ui" line="9211"/>
        <location filename="../win.ui" line="9216"/>
        <location filename="../win.ui" line="9221"/>
        <source>New Row</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9266"/>
        <location filename="../win.cpp" line="3765"/>
        <source>Capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9282"/>
        <source>Grid off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9298"/>
        <source>Cell number(2V)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9314"/>
        <source>Grid on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9330"/>
        <location filename="../win.cpp" line="3775"/>
        <source>Battery float voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9346"/>
        <source>Shutdown voltage point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9391"/>
        <location filename="../win.cpp" line="3780"/>
        <source>Battery filling voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9407"/>
        <source>Mending center point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9461"/>
        <location filename="../win.cpp" line="3785"/>
        <source>Charge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9469"/>
        <location filename="../win.ui" line="9533"/>
        <location filename="../win.ui" line="9694"/>
        <location filename="../win.ui" line="9710"/>
        <source>C</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9477"/>
        <source>Temperature filling coefficient</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9525"/>
        <location filename="../win.cpp" line="3790"/>
        <source>Discharge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9541"/>
        <source>Mending allowable setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9605"/>
        <source>Temperature alarm upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9669"/>
        <location filename="../win.cpp" line="3815"/>
        <source>Uniform charging and flushing current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9702"/>
        <location filename="../win.cpp" line="3820"/>
        <source>Float turn uniform charging current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8640"/>
        <source>DOD_OnGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7574"/>
        <source>Record.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7701"/>
        <source>status:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7734"/>
        <source>u disk disconnect!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7769"/>
        <location filename="../win.cpp" line="2263"/>
        <source>Historical Failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7834"/>
        <location filename="../win.cpp" line="2271"/>
        <source>Electricity Statistical Table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7865"/>
        <location filename="../win.cpp" line="2275"/>
        <source>Eject U disk</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8041"/>
        <source>Grid conected mode of the converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8656"/>
        <source>Turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8672"/>
        <source>DOD_OffGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8688"/>
        <source>Turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8704"/>
        <source>Charge Vol. upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8720"/>
        <source>Turn on cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8768"/>
        <source>Discharge Vol. lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8752"/>
        <source>Turn off cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8832"/>
        <source>Charge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8784"/>
        <source>Turn on total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8928"/>
        <location filename="../win.cpp" line="3627"/>
        <source>Generator turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8816"/>
        <source>Turn off total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8944"/>
        <source>Generator turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8848"/>
        <source>UPS charge power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8960"/>
        <source>Generator charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8880"/>
        <source>Monthly cycle time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1513"/>
        <source>Dry Contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1529"/>
        <source>Dry Contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1766"/>
        <source>Level 1 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1776"/>
        <source>Level 2 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1786"/>
        <source>Level 3 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8585"/>
        <source>13</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8590"/>
        <source>14</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8595"/>
        <source>15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8600"/>
        <source>16</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8605"/>
        <source>17</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8864"/>
        <source>Discharge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8976"/>
        <location filename="../win.cpp" line="3654"/>
        <source>Grid charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8992"/>
        <location filename="../win.cpp" line="3663"/>
        <source>Charge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9008"/>
        <location filename="../win.cpp" line="3672"/>
        <source>Discharge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9024"/>
        <source>Grid capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9100"/>
        <source>Lead</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9156"/>
        <source>A1: Generator turn on voltage
B1: Generator turn off voltage
A1 Setting range: [250, 900]
B1 Setting range: [250, 900]
Set rule:B1 - A1 ≥ 10V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9725"/>
        <source>Automatic operation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9740"/>
        <source>SystemInformation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9755"/>
        <source>Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9771"/>
        <location filename="../win.ui" line="9776"/>
        <location filename="../win.ui" line="9781"/>
        <location filename="../win.ui" line="9786"/>
        <location filename="../win.ui" line="9791"/>
        <source>新建行</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9796"/>
        <location filename="../win.ui" line="9801"/>
        <source>新建列</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9806"/>
        <location filename="../win.cpp" line="4577"/>
        <source>Monitoring software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9821"/>
        <source>Protocol version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9826"/>
        <location filename="../win.cpp" line="4595"/>
        <source>Converter software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9831"/>
        <location filename="../win.cpp" line="4604"/>
        <source>CPLD software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9836"/>
        <source>SN:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9845"/>
        <source>Network</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9904"/>
        <source>              interface:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9945"/>
        <source>Port:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10015"/>
        <source>DHCP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10034"/>
        <source>STATIC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10050"/>
        <source>ip：</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10063"/>
        <source>netmask:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10079"/>
        <source>gateway:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10092"/>
        <source>Server ip:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10105"/>
        <source>192 . 168 . 1 . 100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10118"/>
        <source>255 . 255 . 255 . 0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10131"/>
        <source>192 . 168 .  1  . 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10144"/>
        <source> 192 . 168 . 1  . 200</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10167"/>
        <location filename="../win.cpp" line="2312"/>
        <source>Apply and Restart system</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9926"/>
        <source>eth0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9964"/>
        <source>502</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10251"/>
        <source>Menu</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10285"/>
        <source>M_01 Converter turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10325"/>
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
        <location filename="../win.cpp" line="3830"/>
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
        <location filename="../win.cpp" line="3833"/>
        <source>State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1166"/>
        <source>Power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2857"/>
        <source>Alarm levels uploaded from BMS, level one alarm is yellow, level two alarm is orange, and level three alarm is red;
By default, the converter does not respond to level one and level two alarms, but shuts down in response to level three alarms.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2883"/>
        <source>Inv. side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2892"/>
        <source>Inv. side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2901"/>
        <source>Inv. side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2910"/>
        <source>Inv. side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2919"/>
        <source>Inv. side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2937"/>
        <source>Active power P on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2946"/>
        <source>Reactive power Q on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2955"/>
        <source>Apparent power S on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2965"/>
        <source>Power factor PF on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2974"/>
        <source>Converter battery side voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2983"/>
        <source>Converter battery side current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2992"/>
        <source>Converter battery side power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3001"/>
        <source>Converter bus voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3010"/>
        <source>The IGBT temperature of the converter: The IGBT temperature must not exceed 102°C. Otherwise, the converter will operate at a reduced capacity. It will resume full power operation when the temperature drops to 73°C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3019"/>
        <source>”The ambient temperature.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3034"/>
        <source>Grid side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3043"/>
        <source>Grid side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3052"/>
        <source>Grid side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3061"/>
        <source>Grid side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3070"/>
        <source>Grid side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3079"/>
        <source>Grid side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3088"/>
        <source>Active power P on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3097"/>
        <source>Reactive power Q on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3106"/>
        <source>Apparent power S on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3115"/>
        <source>Frequency on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3124"/>
        <source>Power factor PF on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3139"/>
        <source>Load side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3148"/>
        <source>Load side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3157"/>
        <source>Load side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3166"/>
        <source>Load side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3175"/>
        <source>Load side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3184"/>
        <source>Load side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3193"/>
        <source>Active power P on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3202"/>
        <source>Reactive power Q on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3211"/>
        <source>Apparent power S on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3220"/>
        <source>Power factor PF on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3430"/>
        <source>Grid conected mode of the converter </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3431"/>
        <source>When &quot;Auto&quot; is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).                                               When &quot;Grid-on&quot; is selected, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.                                               When &quot;Grid-off&quot; is selected, the converter operates in grid-off mode (VF).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3466"/>
        <source>This item can modify the power factor, where the power factor is equal to the ratio of active power to apparent power. A positive value indicates leading reactive power, while a negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3475"/>
        <source>This parameter can change the reactive power Q, positive value indicates leading reactive power, negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3484"/>
        <location filename="../win.cpp" line="3504"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant voltage and modify the voltage value. Converter will operate at the constant voltage value and function as a constant voltage source.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3493"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant current and modify the current value. Converter will charge or discharge the battery with this current value. Positive values represent discharging, while negative values represent charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3513"/>
        <source>Device number: You can set ID number, which can be set within the range of M_01 to M_12.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3522"/>
        <source>Parallel operation: When converter operates at grid-off mode in parallel, this item needs to be enabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3645"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3646"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3655"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3664"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3673"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4270"/>
        <location filename="../win.cpp" line="4284"/>
        <location filename="../win.cpp" line="4298"/>
        <location filename="../win.cpp" line="4312"/>
        <location filename="../win.cpp" line="4326"/>
        <location filename="../win.cpp" line="4340"/>
        <location filename="../win.cpp" line="4354"/>
        <location filename="../win.cpp" line="4368"/>
        <location filename="../win.cpp" line="4382"/>
        <location filename="../win.cpp" line="4396"/>
        <source>charge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4277"/>
        <location filename="../win.cpp" line="4291"/>
        <location filename="../win.cpp" line="4305"/>
        <location filename="../win.cpp" line="4319"/>
        <location filename="../win.cpp" line="4333"/>
        <location filename="../win.cpp" line="4347"/>
        <location filename="../win.cpp" line="4361"/>
        <location filename="../win.cpp" line="4375"/>
        <location filename="../win.cpp" line="4389"/>
        <location filename="../win.cpp" line="4403"/>
        <source>discharge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2288"/>
        <source>Interface</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1998"/>
        <location filename="../win.cpp" line="2002"/>
        <location filename="../win.cpp" line="2006"/>
        <location filename="../win.cpp" line="2141"/>
        <location filename="../win.cpp" line="2200"/>
        <location filename="../win.cpp" line="2204"/>
        <location filename="../win.cpp" line="2208"/>
        <location filename="../win.cpp" line="2212"/>
        <location filename="../win.cpp" line="2216"/>
        <location filename="../win.cpp" line="2220"/>
        <location filename="../win.cpp" line="2224"/>
        <location filename="../win.cpp" line="2228"/>
        <location filename="../win.cpp" line="2232"/>
        <location filename="../win.cpp" line="2236"/>
        <location filename="../win.cpp" line="2240"/>
        <location filename="../win.cpp" line="2244"/>
        <location filename="../win.cpp" line="2248"/>
        <location filename="../win.cpp" line="2252"/>
        <location filename="../win.cpp" line="2256"/>
        <location filename="../win.cpp" line="2260"/>
        <location filename="../win.cpp" line="2264"/>
        <location filename="../win.cpp" line="2268"/>
        <location filename="../win.cpp" line="2272"/>
        <location filename="../win.cpp" line="2276"/>
        <location filename="../win.cpp" line="2289"/>
        <location filename="../win.cpp" line="2293"/>
        <location filename="../win.cpp" line="2297"/>
        <location filename="../win.cpp" line="2301"/>
        <location filename="../win.cpp" line="2305"/>
        <location filename="../win.cpp" line="2309"/>
        <location filename="../win.cpp" line="2313"/>
        <location filename="../win.cpp" line="2328"/>
        <location filename="../win.cpp" line="2332"/>
        <location filename="../win.cpp" line="2336"/>
        <location filename="../win.cpp" line="2340"/>
        <location filename="../win.cpp" line="2344"/>
        <location filename="../win.cpp" line="2348"/>
        <location filename="../win.cpp" line="2801"/>
        <location filename="../win.cpp" line="2805"/>
        <location filename="../win.cpp" line="2809"/>
        <location filename="../win.cpp" line="2813"/>
        <location filename="../win.cpp" line="2817"/>
        <location filename="../win.cpp" line="2821"/>
        <location filename="../win.cpp" line="2825"/>
        <location filename="../win.cpp" line="2829"/>
        <location filename="../win.cpp" line="2833"/>
        <location filename="../win.cpp" line="2837"/>
        <location filename="../win.cpp" line="2841"/>
        <location filename="../win.cpp" line="2845"/>
        <location filename="../win.cpp" line="2849"/>
        <location filename="../win.cpp" line="2853"/>
        <location filename="../win.cpp" line="2857"/>
        <location filename="../win.cpp" line="2861"/>
        <location filename="../win.cpp" line="2865"/>
        <location filename="../win.cpp" line="5684"/>
        <location filename="../win.cpp" line="5707"/>
        <location filename="../win.cpp" line="5715"/>
        <location filename="../win.cpp" line="5723"/>
        <location filename="../win.cpp" line="5789"/>
        <location filename="../win.cpp" line="5814"/>
        <source>OK</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1196"/>
        <location filename="../win.cpp" line="2882"/>
        <source>Inv. voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1196"/>
        <location filename="../win.cpp" line="2891"/>
        <source>Inv. voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1196"/>
        <location filename="../win.cpp" line="2900"/>
        <source>Inv. voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1197"/>
        <location filename="../win.cpp" line="2909"/>
        <source>Inv. current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1197"/>
        <location filename="../win.cpp" line="2918"/>
        <source>Inv. current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1197"/>
        <location filename="../win.cpp" line="2927"/>
        <source>Inv. current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1916"/>
        <location filename="../win.cpp" line="3342"/>
        <source>Start Diesel Generator Signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1917"/>
        <location filename="../win.cpp" line="3369"/>
        <source>Dry contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1918"/>
        <location filename="../win.cpp" line="3378"/>
        <source>Dry contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2199"/>
        <source>Discharge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2203"/>
        <source>Discharge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2207"/>
        <source>Discharge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2211"/>
        <source>Discharge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2215"/>
        <source>Charge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2219"/>
        <source>Charge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2223"/>
        <source>Charge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2227"/>
        <source>Charge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2231"/>
        <source>Month-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2235"/>
        <source>Year-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2239"/>
        <source>Daily electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2240"/>
        <source>To view the daily charge and discharge volume, click here to jump to the histogram of daily charge and discharge volume. The horizontal axis is in day, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2243"/>
        <source>Annual electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2244"/>
        <source>To view the annual charge and discharge volume, click here to jump to the histogram of the annual charge and discharge volume, the horizontal axis is in year, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2247"/>
        <source>Month+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2251"/>
        <source>Year+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2255"/>
        <source>Monthly electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2256"/>
        <source>To view the monthly charge and discharge volume, click here to jump to the histogram of monthly charge and discharge volume. The horizontal axis is in month, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2259"/>
        <source>Total electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2260"/>
        <source>To view the total charge and discharge, click here to jump to the overview chart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2292"/>
        <source>Port</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2296"/>
        <source>Ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2300"/>
        <source>Netmask</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2304"/>
        <source>Gateway</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2308"/>
        <source>Serber ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2313"/>
        <source>This is the application and restart the system. After clicking, the system will be restarted. If there is an upgrade of the monitoring screen program, the new monitoring screen program will be used after the restart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2367"/>
        <source>CAN communication failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2370"/>
        <source>Fire alarm (High temp. alarm)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2726"/>
        <source>Power control type：CP_P-&gt;CP_N&amp;&amp;P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2729"/>
        <source>Power control type：CP_N&amp;&amp;P-&gt;CP_P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2732"/>
        <source>Grid Fre Upper limit：0.2-&gt;3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2735"/>
        <source>Grid Fre Upper limit：3-&gt;0.2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2738"/>
        <source>Voltage protection Lower limit：-10-&gt;-15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2741"/>
        <source>Voltage protection Lower limit：-15-&gt;-10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2744"/>
        <source>Operation mode：Prevent countercurrnet-&gt;Peak valley</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2753"/>
        <source>Operation mode：UPS-&gt;Prevent countercurrnet</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2750"/>
        <source>Operation mode：Manual-&gt;UPS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1997"/>
        <source>Turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2001"/>
        <source>Stand-by</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2005"/>
        <source>Turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2327"/>
        <source>DO turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2328"/>
        <source>This is the DO control closure, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2331"/>
        <source>Do turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2332"/>
        <source>This is the DO control off, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2335"/>
        <source>Local on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2336"/>
        <source>This is to start a local soft boot, only for internal debugging use.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2339"/>
        <source>Local off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2340"/>
        <source>This is to turn off the local soft boot for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2747"/>
        <source>Operation mode：Peak valley-&gt;Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2756"/>
        <source>Inv ON/Off-Grid：Off-&gt;automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2759"/>
        <source>Inv ON/Off-Grid：automatic-&gt;Off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2800"/>
        <source>Bat volage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2816"/>
        <source>Cell voltage(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2820"/>
        <source>Cell voltage(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2824"/>
        <source>Cell temp.(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2828"/>
        <source>Cell temp.(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2856"/>
        <source>Alarm level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1303"/>
        <location filename="../win.cpp" line="3219"/>
        <source>Load power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3234"/>
        <source>DC input Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3234"/>
        <location filename="../win.cpp" line="3243"/>
        <location filename="../win.cpp" line="3252"/>
        <location filename="../win.cpp" line="3261"/>
        <location filename="../win.cpp" line="3270"/>
        <location filename="../win.cpp" line="3279"/>
        <location filename="../win.cpp" line="3288"/>
        <source>On</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3235"/>
        <source>There are two states for a DC circuit breaker: On, Off.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3244"/>
        <source>The DC contactor has two states: On, Off. After the soft start of the DC side is completed, the DC contactor closes. When the DC side of the battery is disconnected and the voltage of the DC bus drops to a certain level, the DC contactor opens.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3253"/>
        <source>The output contactor has two states: On, Off. The output contactor closes after the soft start on the inv. side is completed. The output contactor opens when the converter is shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3261"/>
        <source>Output Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3271"/>
        <source>The grid contactor has two states: On, Off. When the inverter is in grid-connected mode and the grid voltage is normal, the grid contactor is closed. When the inverter is in island mode, the grid contactor is open. In the islanded state, the grid contactor remains open.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3289"/>
        <source>There are two states for the maintenance bypass circuit breaker: On, Off. This circuit breaker is only used for machine maintenance. If maintenance is required, please contact the maintenance personnel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3837"/>
        <source>End time: The system stops automatically running when the system reaches this time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3840"/>
        <source>Start time: When the system reaches this time, it starts to run automatically.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3841"/>
        <source>Select: After this function is enabled, the system automatically runs the selected function mode within the specified period.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5019"/>
        <source>Non
adjustable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5028"/>
        <source>Non
countercurrent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3279"/>
        <source>Grid Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2140"/>
        <source>Alarm icon</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="2936"/>
        <source>Inv. active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="2945"/>
        <source>Inv. reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="2954"/>
        <source>Inv. apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="2964"/>
        <source>Inv. power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1375"/>
        <source>System Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1998"/>
        <source>The converter off switch. Click to turn off the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2002"/>
        <source>The converter standby switch. Click the converter to enter the standby state.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2006"/>
        <source>The converter on switch. Click to turn on the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2140"/>
        <source>Alarm icon: It is not displayed when there is no alarm. When there is a minor alarm, a yellow icon is displayed. When there is a fault alarm, a red icon is displayed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2200"/>
        <source>Display today&apos;s power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2204"/>
        <source>Display this month&apos;s power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2208"/>
        <source>Display this year&apos;s power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2212"/>
        <source>Display total power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2216"/>
        <source>Display today&apos;s power charge amount</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2220"/>
        <source>Display this month&apos;s power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2224"/>
        <source>Display this year&apos;s power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2228"/>
        <source>Display total power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2232"/>
        <source>To view the data of the previous month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2236"/>
        <source>To view the data of the previous year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2248"/>
        <source>To view the data of the next month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2252"/>
        <source>To view the data of the next year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2264"/>
        <source>Export History Records, click here to export the history records to a U disk. The exported file will be named Record.csv, and it needs to be opened with Excel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2268"/>
        <source>Export operation log. Click here to export operation log to U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2272"/>
        <source>Export the battery statistics. Click here to export the battery statistics to the U disk.
The accuracy is 0.1, which means that the obtained data multiplied by 0.1 gives the actual value.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2276"/>
        <source>Eject U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2344"/>
        <source>Battery power-on: This function allows the BMS to send a command to close the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2348"/>
        <source>Battery power-off: This function allows the BMS to send a command to open the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2362"/>
        <source>0 represents an alarm event, and this item will turn red. 1 represents a status event.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2364"/>
        <source>Event start time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2366"/>
        <source>Event end time: &apos;... &apos;indicates that there is no end time,&apos;-&apos; indicates that the event is in progress.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2368"/>
        <source>event description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2369"/>
        <source>event description.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2372"/>
        <source>Converter Standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2373"/>
        <source>The grid contactor connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2374"/>
        <source>The grid breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2375"/>
        <source>The output breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2376"/>
        <source>Buck not softened</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2377"/>
        <source>Contactor off buck</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2379"/>
        <source>The grid breaker disconnected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2687"/>
        <source>System settings operation records.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2801"/>
        <source>Total voltage of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2805"/>
        <source>Total current of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2809"/>
        <source>Battery SOH uploaded from BMS, the percentage of available capacity after full charge compared to the rated capacity.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2813"/>
        <source>Battery SOC uploaded by BMS refers to the current remaining battery capacity percentage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2817"/>
        <source>The highest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2821"/>
        <source>The lowest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2825"/>
        <source>The highest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2829"/>
        <source>The lowest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2833"/>
        <source>The limit of charging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2837"/>
        <source>The limit of discharging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2841"/>
        <source>The allowable charging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2845"/>
        <source>The allowable discharging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2849"/>
        <source>The allowable charging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2853"/>
        <source>The allowable discharging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2860"/>
        <source>Charging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2861"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to charge, Disable indicates the battery is not allowed to charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2864"/>
        <source>Discharging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2865"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to discharge, Disable indicates the battery is not allowed to discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2928"/>
        <source>Inv. side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3262"/>
        <source>The output circuit breaker has two states: On, Off. It can only be manually opened and closed. If there is an overcurrent in the output circuit breaker, it will trip.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3280"/>
        <source>The power grid circuit breaker has two states: On, Off; The power grid circuit breaker can only be manually disconnected. If the power grid circuit breaker overflows, the power grid circuit breaker may trip.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3297"/>
        <source>Disabled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3298"/>
        <source>The converter has two states: enabled,disabled. The converter is enabled when the self-check is successful. Otherwise, the converter is disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3307"/>
        <source>There are three states for DC soft start: Not starting, Soft starting, and Complete. Soft start refers to the process in which the converter charges the busbar with the battery during startup, causing the busbar voltage to rise close to the battery voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3316"/>
        <source>Converter states include: OFF, AC Soft Start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Derating grid-on, Standby, Grid-OFF Charge, Constant Voltage Discharge and Constant Voltage Charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3325"/>
        <source>There are three types of reactive power regulation: Disable,PF regulation, and  regulation.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3334"/>
        <source>LVRT states : enabled , disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3343"/>
        <source>Signal to start the diesel generator, start the diesel generator when enabled, stop the diesel generator when disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3352"/>
        <source>Dry contact 2 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3361"/>
        <source>Dry contact 3 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3370"/>
        <source>Dry contact EPO：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3379"/>
        <source>Dry contact Shutdown：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3387"/>
        <source>Access signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3388"/>
        <source>Access signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3397"/>
        <source>Full power signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3406"/>
        <source>Smoke alarm signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3414"/>
        <source>Fire fighting signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3415"/>
        <source>Fire fighting signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3430"/>
        <source>automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3442"/>
        <source>AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. When the advanced setting for power control mode is set to Constant Power mode (CP_N&amp;P), a positive value indicates discharging, and a negative value indicates charging.
For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3512"/>
        <source>M_01</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3537"/>
        <source>Grid-on DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3538"/>
        <source>Grid-on DOD, allowable depth of discharge in grid-on mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3546"/>
        <source>Grid-off DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3547"/>
        <source>Grid-off DOD, allowable depth of discharge in grid-off mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3555"/>
        <source>Charge Volt upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3556"/>
        <source>Charging voltage upper limit: When the battery total voltage reaches this value during charging, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3565"/>
        <source>Charging voltage upper limit hysteresis: When the battery is charging, if the battery total voltage reaches the charging voltage upper limit, the converter will shut down. When the battery total voltage drops below the charging voltage upper limit minus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3573"/>
        <source>Discharge Volt lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3574"/>
        <source>Discharge voltage lower limit: When the battery total voltage reaches this value during discharge, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3583"/>
        <source>Discharge voltage lower limit hysteresis: When the battery is discharging, if the battery total voltage drops below the discharge voltage lower limit, the converter will shut down. When the battery total voltage exceeds the discharge voltage lower limit plus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3591"/>
        <source>Charge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3592"/>
        <source>Charging current limit: The maximum allowable current on the battery side to prevent overcurrent during charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3600"/>
        <source>Discharge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3601"/>
        <source>Discharging current limit: The maximum allowable current on the battery side to prevent overcurrent during Discharging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3628"/>
        <source>When the specified SOC is reached, the diesel generator shuts down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3636"/>
        <source>Genertor turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3637"/>
        <source>When the specified SOC is reached, the diesel generator starts.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3682"/>
        <source>Grid Capacity: The maximum capacity of the converter&apos;s AC side input, which takes effect in the converter power supply mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3694"/>
        <source>Start SOC: In UPS mode, when the battery SOC reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3703"/>
        <source>Stop SOC: In UPS mode, when the battery SOC reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3712"/>
        <source>Start cell voltage: In UPS mode, when the lowest voltage of a battery cell reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3721"/>
        <source>Stop cell voltage: In UPS mode, when the highest voltage of a battery cell reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3730"/>
        <source>Start total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3739"/>
        <source>Stop total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3748"/>
        <source>Backup charging power: In UPS mode, the backup charging power of the converter when the battery starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3757"/>
        <source>Monthly cycling date: On the same day of each month, a deep discharge and recharge will be performed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3771"/>
        <source>The number of battery cells connected in series in the battery stack (based on a 2V unit).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3786"/>
        <source>Charging Current Limit: The maximum allowable current on the battery side to prevent overcurrent during charging. (Upper limit: 0.25C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3791"/>
        <source>Discharge Current Limit: The maximum allowable current on the battery side to prevent overcurrent during discharge. (Upper limit: 0.5C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3796"/>
        <source>Generator Shutdown Voltage: When the specified voltage is reached, the diesel generator will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3801"/>
        <source>Generator Start Voltage: When the specified voltage is reached, the diesel generator will start up.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3805"/>
        <source>Grid-off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3806"/>
        <source>Grid-off discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3810"/>
        <source>Grid-on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3811"/>
        <source>Grid-on discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3816"/>
        <source>Uniform charging to flushing current: Upper limit of 0.025C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3821"/>
        <source>Float turn to uniform charging current: Upper limit of 0.15C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3838"/>
        <source>This working state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3839"/>
        <source>Working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4629"/>
        <source>Battery Types: Lithium, Lead-Acid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4638"/>
        <source>Battery Communication Modes: None, RS485, CAN, Ethernet. (Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as &quot;CAN&quot; or &quot;Ethernet&quot; simultaneously.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4647"/>
        <source>Constant Voltage (CV) mode: The converter will operate in constant voltage mode on the DC side.                                              Constant Current (CC) mode: The converter will operate in constant current mode on the DC side.                                              Constant Power AC (CP_AC) mode: The power level can be set at &quot;constant power.&quot; The value represents the power level, positive for discharge and negative for charge. For example, setting it to -5 means that the AC side will charge the battery with a power of 5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Conversely, setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.                                              Reserved.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4659"/>
        <source>EMS communication methods: RS485, CAN, Ethernet.                                         The setting communication methods are readable and writable in remote mode, and only readable in local mode. The unselected communication methods are only readable in both remote and local mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4669"/>
        <source>Output Power Limit: Restricts the upper limit of the set value for the power on the AC side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4678"/>
        <source>Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:MEGA, LISHEN, PENGHUI, GAOTE, XIENENG, LANLI, SHENLAN, PAINENG, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD, GROUP_STANDARD, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, ECUBE, FARO, BGS, JDITEC, HUASU, LIGAO.                                             
Select AUTO to automatically detect the battery manufacturer protocol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="594"/>
        <location filename="../win.cpp" line="4688"/>
        <source>Anti-backflow power tolerance</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4689"/>
        <source>Anti-backflow power tolerance.The default power tolerance is 10 kW. When the output power increases to &quot;output power limit + power tolerance&quot;, the output power will be reduced to &quot;output power limit - power tolerance&quot;.
(Note: This setting only takes effect in the system anti-backflow mode and is used to control the power tolerance at the grid entrance).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="330"/>
        <location filename="../win.cpp" line="4699"/>
        <source>Serial Communication Address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4700"/>
        <source>Serial Communication Address: The default value is 1, adjustable range is between 1 and 255, used for matching address during serial communication.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4709"/>
        <source>Serial Port 2 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 2 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4718"/>
        <source>Serial Port 3 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 3 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4728"/>
        <source>Serial Port 4 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 4 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4737"/>
        <source>Serial Port 5 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 5 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4745"/>
        <source>serial port 6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4746"/>
        <source>Serial Port 6 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 6 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4755"/>
        <source>CAN1 Port: The baud rate for internal communication is 500 kbps by default and cannot be modified. </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4764"/>
        <source>CAN2 Port: Optional baud rates for the CAN2 port include 100, 125, 250, 500, and 800 kbps, with a default baud rate of 500 kbps.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4773"/>
        <source>Protocol version: View the current protocol version. The default protocol version number is V1.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4782"/>
        <source>User password: Available for resetting the user password. The default user password is 123456. (Note: The user password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="442"/>
        <location filename="../win.cpp" line="4790"/>
        <source>Admin password</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4791"/>
        <source>Admin password: Available for resetting the admin password. The default admin password is 888888. (Note: The admin password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4865"/>
        <source>Power change rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4866"/>
        <source>Power change rate: the rate at which power changes within a second .</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4875"/>
        <source>Upper limit of power grid frequency variation: The maximum range of frequency variation allowed on the AC side, which can be selected as 0.2, 0.5, 1, 5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4884"/>
        <source>Lower limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as-0.5, -1, -2, -5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4893"/>
        <source>Upper limit of voltage protection range: The maximum range of voltage variation allowed on the AC side, which can be selected as 10, 15, 20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4902"/>
        <source>Lower limit of voltage protection range: The minimum range of voltage variation allowed on the AC side, which can be selected as -10, -15, -20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4911"/>
        <source>High voltage ride through(HVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4920"/>
        <source>Low voltage ride through(LVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4929"/>
        <source>Prevent islanding effect. When islanding effect is detected (in a photovoltaic grid-on system, when a power outage occurs in the main grid, and the PV grid-connected converter generates power that matches the local load on the low-voltage side of the grid, it can easily sustain power generation independently, resulting in an &apos;island&apos; phenomenon, which endangers the safety of maintenance personnel), the converter automatically shuts down. The options for this feature can be set as &apos;Enable&apos; or &apos;prohibited&apos; .(Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4939"/>
        <source>Insulation detection enable, the insulation resistance should be greater than 33KΩ for normal start-up and operation. If it is less than 33KΩ, it should not start, and an alarm should be triggered. By default, it is disabled, but can be set as &apos;Enable&apos; or &apos;prohibited&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4948"/>
        <source>Primary frequency control enable: When the grid frequency deviates from the rated value, the active power is controlled to increase or decrease in order to maintain the grid frequency at the rated value. It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4957"/>
        <source>Rotational inertia enable: It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4966"/>
        <source>Constant voltage parallel operation enable: It can be selected as enabled or disabled.  (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4975"/>
        <source>Converter Model: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4984"/>
        <source>The rated capacity of the converter shall be based on the factory value and cannot be changed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4993"/>
        <source>Output Frequency Level: Default 50Hz, typically 50Hz or 60Hz.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5002"/>
        <source>Output Voltage Level: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5011"/>
        <source>Transformer Voltage Ratio: To be determined by the factory nameplate, not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5020"/>
        <source>Reactive Power Output Mode: Default non-adjustable, options include Power Factor, Reactive Power, non-adjustable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1195"/>
        <location filename="../win.cpp" line="5028"/>
        <source>Converter Anti-Reverse Flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5029"/>
        <source>Converter Anti-Reverse Flow: Enable, Disable; Enabling prevents converter current from flowing into the grid, while Disabling allows converter current to flow into the grid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5038"/>
        <source>Frequency Deviation Deadzone: A frequency difference settings to prevent unnecessary frequency regulation actions during minor grid frequency fluctuations. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5047"/>
        <source>Active Frequency Regulation Coefficient: The active frequency regulation coefficient can be configured. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5091"/>
        <source>Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5120"/>
        <source>When the dry contact is enabled, the device will perform the selected action when there is a change in the signal.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5121"/>
        <source>Input Dry Contact:                       
Enabled: Triggers the Action when the dry contact detects a state other than the specified NO/NC.                      
Disabled: No action is taken when the dry contact detects a state other than the specified NO/NC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5130"/>
        <source>DI 1 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5138"/>
        <source>DI 2 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5146"/>
        <source>DI 3 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5154"/>
        <source>DI 4 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5162"/>
        <source>DI 5 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5170"/>
        <source>DI 6 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5281"/>
        <source>DOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5290"/>
        <source>The action performed when the charge ban is triggered;Optional function: NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5299"/>
        <source>The action to be performed when a ban is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5307"/>
        <source>level 1 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5316"/>
        <source>level 2 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5325"/>
        <source>level 3 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5334"/>
        <source>level 1 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5335"/>
        <source>The charging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5343"/>
        <source>level 2 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5344"/>
        <source>The charging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5361"/>
        <source>level 1 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5362"/>
        <source>The discharging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5371"/>
        <source>The discharging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5787"/>
        <source>Upgrade prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5788"/>
        <source>1. Make sure to press the EPO button before upgrading.                              
2. Before upgrading the DCDC, switch off the ship-type switch of the DCDC module.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5810"/>
        <source>Working mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5811"/>
        <source>When selecting the manual mode, the converter’s operating status, charging or discharging power (active power), reactive power, power factor etc,can be controlled through HMI or EMS.                              When selecting the UPS mode, When the grid side is abnormal, the system will switch from zero power to grid-off discharge mode to provide energy to critical loads. Please go to the &quot;Battery Settings&quot; page to configure this mode. Note: This mode is only applicable to lithium battery mode and requires normal communication between the converter and BMS.                              Peak shaving and valley filling mode is used for peak-valley price arbitrage. The converter can operate according to the local peak-valley electricity price periods. Please set the operating time period, charging or discharging mode, charging or discharging power, and other information on the &quot;Mixed mode&quot; page.
Grid expansion.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5814"/>
        <source>Click to view grid expansion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3441"/>
        <source>Constant power(AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3447"/>
        <source>Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3681"/>
        <source>Grid_capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3693"/>
        <source>Turn_on_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3702"/>
        <source>Turn_off_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3711"/>
        <source>Turn_on_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3720"/>
        <source>Turn_off_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3729"/>
        <source>Turn_on_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3738"/>
        <source>Turn_off_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3747"/>
        <source>UPS_charge_power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3756"/>
        <source>Monthly_cycle_time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3766"/>
        <source>Capacity, the capacity of the lead-acid battery.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3770"/>
        <source>Cell_number_2V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3776"/>
        <source>This is the floating charge voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3781"/>
        <source>This is the filling voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3831"/>
        <source>Start_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3832"/>
        <source>End_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3834"/>
        <source>Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3835"/>
        <source>9:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3836"/>
        <source>10:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4578"/>
        <source>This is the monitoring version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4831"/>
        <source>Energy meter model: The energy meter model is selected according to the type of energy meter that is connected. According to the characteristics and specifications of the connected watt-hour meter, select the corresponding watt-hour meter model, which can be selected NONE, DTSD1352, AMC96-E4/KC or ADL3000-E-B.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9589"/>
        <location filename="../win.cpp" line="3795"/>
        <source>Generator turn off voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9653"/>
        <location filename="../win.cpp" line="3800"/>
        <source>Generator turn on voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="346"/>
        <location filename="../win.cpp" line="4586"/>
        <source>Protocol Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4587"/>
        <source>This is the protocol version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4596"/>
        <source>This is the converter software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4605"/>
        <source>This is the CPLD software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4613"/>
        <source>SN</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4614"/>
        <source>This is SN, the serial number of the product.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8500"/>
        <location filename="../win.cpp" line="4628"/>
        <source>Lithium</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4637"/>
        <source>BMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4658"/>
        <source>EMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4677"/>
        <source>Auto</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="554"/>
        <location filename="../win.cpp" line="4677"/>
        <source>BAT protocol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3610"/>
        <source>Set the charging power limit to allow the maximum power of charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3619"/>
        <source>The discharge power limit is set to allow the maximum power of the discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3564"/>
        <source>Charge Vol upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3582"/>
        <source>Discharge Vol lower Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4799"/>
        <source>English</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4800"/>
        <source>Set the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4813"/>
        <source>upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4821"/>
        <source>Allow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4822"/>
        <source>Set whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4830"/>
        <source>NONE</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4839"/>
        <source>20</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4839"/>
        <source>Bms Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4840"/>
        <source>BMS communication fault determination time: The BMS communication fault determination time refers to the BMS communication fault when the BMS communication is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4848"/>
        <source>EMS Com. Fault Model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4849"/>
        <source>EMS communication fault determination time: The EMS communication fault determination time refers to the time when the communication between the EMS is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1051"/>
        <location filename="../win.cpp" line="4892"/>
        <source>Vol protection upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1099"/>
        <location filename="../win.cpp" line="4901"/>
        <source>Vol protection lower limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4910"/>
        <location filename="../win.cpp" line="4919"/>
        <location filename="../win.cpp" line="4928"/>
        <location filename="../win.cpp" line="4938"/>
        <location filename="../win.cpp" line="4947"/>
        <location filename="../win.cpp" line="4956"/>
        <location filename="../win.cpp" line="4965"/>
        <source>prohibit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4992"/>
        <source>Output Fre grade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5001"/>
        <source>Output vol level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5056"/>
        <source>Grid restoration time: reserved function, setting invalid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5074"/>
        <source>Number of modules for PCS, default 1(invalid setting).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5082"/>
        <source>restore</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5083"/>
        <source>Restore the factory default Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5091"/>
        <source>Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5092"/>
        <source>Backup setting parameters: Backup setting parameters refers to backing up the parameters set on the current device so that the backup parameter Settings can be restored when needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5100"/>
        <source>Restore Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5100"/>
        <source>Restore
Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5101"/>
        <source>Restore backup setting parameters: Restore backup setting parameters means to restore the device to the last backup setting parameters and restart the device.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5109"/>
        <source>Clear</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5110"/>
        <source>Clear previous recorded data and operation data of the system.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5119"/>
        <source>Normally closed circuit (NC) or normally open circuit (NO) according to field Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5178"/>
        <source>DI_1_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5186"/>
        <source>DI_2_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5194"/>
        <source>DI_3_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5202"/>
        <source>DI_4_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5210"/>
        <source>DI_5_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5218"/>
        <source>DI_6_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5226"/>
        <source>DI_1_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1591"/>
        <location filename="../win.ui" line="1635"/>
        <location filename="../win.ui" line="1679"/>
        <location filename="../win.cpp" line="5234"/>
        <location filename="../win.cpp" line="5242"/>
        <location filename="../win.cpp" line="5250"/>
        <source>Prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5234"/>
        <source>DI_2_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5242"/>
        <source>DI_3_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5250"/>
        <source>DI_4_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5258"/>
        <source>DI_5_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5266"/>
        <source>DI_6_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5280"/>
        <location filename="../win.cpp" line="5289"/>
        <location filename="../win.cpp" line="5298"/>
        <location filename="../win.cpp" line="5316"/>
        <source>Standby</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5307"/>
        <source>NO action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5308"/>
        <source>Action to be performed when level 1 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5317"/>
        <source>Action to be performed when level 2 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5326"/>
        <source>Action that is performed when level 3 alarm is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5370"/>
        <source>level 2 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5389"/>
        <source>It is used for internal debugging only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5420"/>
        <source>Debug variable 1 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5428"/>
        <source>Debug variable 2 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5436"/>
        <source>Debug variable 3 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5444"/>
        <source>Debug memery var 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5452"/>
        <source>Debug memery var 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5460"/>
        <source>Debug memery var 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5468"/>
        <source>Input Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5476"/>
        <source>Input Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5484"/>
        <source>1.5 Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5492"/>
        <source>Bus Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5500"/>
        <source>Grid A AB Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5508"/>
        <source>Grid B BC Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5516"/>
        <source>Grid C CA Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5524"/>
        <source>Output A Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5532"/>
        <source>Output B Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5540"/>
        <source>Output C Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5548"/>
        <source>INV A Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5556"/>
        <source>INV B Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5564"/>
        <source>INV C Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5572"/>
        <source>INV A ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5580"/>
        <source>INV B ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5588"/>
        <source>INV_C_ind_Cur_revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5684"/>
        <source>static</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5684"/>
        <source>If this parameter is selected, static IP addresses are used.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5707"/>
        <source>This is an automatic IP acquisition, currently not supported.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5707"/>
        <source>dhcp</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5715"/>
        <source>Call in test data (for internal testing personnel only).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5723"/>
        <source>Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5723"/>
        <source>Click here to modify the time displayed on the HMI.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3503"/>
        <source>Local</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3521"/>
        <source>Parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4636"/>
        <location filename="../win.cpp" line="3288"/>
        <source>Maintenance Bypass Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3306"/>
        <source>Not starting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3315"/>
        <location filename="../win.cpp" line="5226"/>
        <location filename="../win.cpp" line="5258"/>
        <location filename="../win.cpp" line="5266"/>
        <location filename="../win.cpp" line="5325"/>
        <source>Shut down</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3324"/>
        <source>Reactive Power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1569"/>
        <location filename="../win.ui" line="1613"/>
        <location filename="../win.ui" line="1657"/>
        <location filename="../win.cpp" line="3342"/>
        <location filename="../win.cpp" line="5130"/>
        <location filename="../win.cpp" line="5146"/>
        <location filename="../win.cpp" line="5154"/>
        <location filename="../win.cpp" line="5162"/>
        <location filename="../win.cpp" line="5170"/>
        <source>Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3926"/>
        <source>PCS voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3936"/>
        <source>PCS voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3946"/>
        <source>PCS voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3956"/>
        <source>PCS current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3966"/>
        <source>PCS current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3976"/>
        <source>PCS current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3986"/>
        <source>PCS Active P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3991"/>
        <source>PCS Reactive P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3996"/>
        <source>PCS Parent P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4001"/>
        <source>PCS Pf</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3931"/>
        <location filename="../win.cpp" line="1200"/>
        <location filename="../win.cpp" line="2973"/>
        <source>Battery voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3941"/>
        <location filename="../win.cpp" line="1200"/>
        <location filename="../win.cpp" line="2982"/>
        <source>Battery current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3951"/>
        <location filename="../win.cpp" line="1200"/>
        <location filename="../win.cpp" line="2991"/>
        <source>Battery power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3961"/>
        <location filename="../win.cpp" line="1201"/>
        <location filename="../win.cpp" line="3000"/>
        <source>Bus voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3971"/>
        <location filename="../win.cpp" line="1201"/>
        <location filename="../win.cpp" line="3009"/>
        <source>IGBT temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3981"/>
        <location filename="../win.cpp" line="1202"/>
        <location filename="../win.cpp" line="3018"/>
        <source>Environment temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1254"/>
        <location filename="../win.cpp" line="3033"/>
        <source>Grid voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1254"/>
        <location filename="../win.cpp" line="3042"/>
        <source>Grid voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1254"/>
        <location filename="../win.cpp" line="3051"/>
        <source>Grid voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1255"/>
        <location filename="../win.cpp" line="3060"/>
        <source>Grid current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1255"/>
        <location filename="../win.cpp" line="3069"/>
        <source>Grid current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1255"/>
        <location filename="../win.cpp" line="3078"/>
        <source>Grid current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1256"/>
        <location filename="../win.cpp" line="3087"/>
        <source>Grid active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1256"/>
        <location filename="../win.cpp" line="3096"/>
        <source>Grid reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1257"/>
        <location filename="../win.cpp" line="3105"/>
        <source>Grid apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1257"/>
        <location filename="../win.cpp" line="3114"/>
        <source>Grid frequency</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1257"/>
        <location filename="../win.cpp" line="3123"/>
        <source>Grid power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1300"/>
        <location filename="../win.cpp" line="3138"/>
        <source>Load voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1300"/>
        <location filename="../win.cpp" line="3147"/>
        <source>Load voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1300"/>
        <location filename="../win.cpp" line="3156"/>
        <source>Load voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1301"/>
        <location filename="../win.cpp" line="3165"/>
        <source>Load current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1301"/>
        <location filename="../win.cpp" line="3174"/>
        <source>Load current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1301"/>
        <location filename="../win.cpp" line="3183"/>
        <source>Load current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1302"/>
        <location filename="../win.cpp" line="3192"/>
        <source>Load active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1302"/>
        <location filename="../win.cpp" line="3201"/>
        <source>Load reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1303"/>
        <location filename="../win.cpp" line="3210"/>
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
        <location filename="../win.cpp" line="3396"/>
        <source>Full power signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1919"/>
        <location filename="../win.cpp" line="3405"/>
        <source>Smoke alarm signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1919"/>
        <source>Hight temp. signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2289"/>
        <source>This is the interface number, which defaults to eth0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2293"/>
        <source>This is the port number, which defaults to 502 and can be changed as needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2297"/>
        <source>This is the IP address. The default is 192.168.1.100.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2301"/>
        <source>This is the subnet mask, 255.255.255.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2305"/>
        <source>This is the gateway. The default is 192.168.1.1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2309"/>
        <source>This is the server IP address. The default is 192.168.1.200.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1074"/>
        <location filename="../win.cpp" line="2361"/>
        <source>Level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1074"/>
        <location filename="../win.cpp" line="2363"/>
        <source>Start Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1074"/>
        <location filename="../win.cpp" line="2365"/>
        <source>End Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8459"/>
        <location filename="../win.cpp" line="1074"/>
        <source>Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1112"/>
        <location filename="../win.cpp" line="2684"/>
        <source>ModificationTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1112"/>
        <location filename="../win.cpp" line="2686"/>
        <source>RecordEvent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2371"/>
        <source>Power Meter Comm fualttLead-acid abnormal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2685"/>
        <source>Time when the system Settings are modified.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5265"/>
        <location filename="../win.ui" line="5289"/>
        <location filename="../win.ui" line="5313"/>
        <location filename="../win.ui" line="5337"/>
        <location filename="../win.ui" line="5361"/>
        <location filename="../win.ui" line="5385"/>
        <location filename="../win.ui" line="5409"/>
        <location filename="../win.ui" line="5433"/>
        <location filename="../win.ui" line="5995"/>
        <location filename="../win.ui" line="6019"/>
        <location filename="../win.ui" line="6043"/>
        <location filename="../win.ui" line="6067"/>
        <location filename="../win.ui" line="6091"/>
        <location filename="../win.ui" line="6115"/>
        <location filename="../win.ui" line="9366"/>
        <location filename="../win.ui" line="9427"/>
        <location filename="../win.ui" line="9497"/>
        <location filename="../win.ui" line="9561"/>
        <location filename="../win.ui" line="9625"/>
        <location filename="../win.cpp" line="2360"/>
        <location filename="../win.cpp" line="3441"/>
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
        <source>MainWindow</source>
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
        <source>MEGA</source>
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
