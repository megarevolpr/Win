<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>FaultTableInterface</name>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="14"/>
        <source>Fault description</source>
        <translation>故障说明</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="31"/>
        <source>Please enter search keywords</source>
        <translation>请输入搜索关键词</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="44"/>
        <source>Search</source>
        <translation>搜索</translation>
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
        <translation>电池充放电截止电压在并网及离网时的详细保护逻辑说明：
并网：
    电池放电放到放电截止电压-5V，（例如：截止电压是500V，那么495V就会截止放电）会报“放电不允许”告警，DCAC逆变输出功率降为0。
    当电池电压大于放电截止电压+放电回差电压或改为充电时，“放电不允许”告警消除。
    电池充电到充电电压上限时，会报“充电不允许”告警，DCAC若处于充电状态，充电功率降为0，DCAC若处于放电状态，则不受影响。
    当电池电压低于充电电压上限-充电回差电压或处于放电时，“充电不允许”告警消除。
离网：
    电池放电放到截止电压-5V（例如：截止电压是500V，那么495V就会截止放电）会报“放电不允许”告警，DCAC逆变停机。当电池电压大于放电截止电压+放电回差电压时，“放电不允许”告警消除，无关机命令下，恢复启动运行。
    电池充电到充电电压上限时，会报“充电不允许”告警，DCAC若处于充电状态，DCAC处于离网放电状态，则不受影响。
    当电池电压低于充电电压上限-充电回差电压，“充电不允许”告警消除。</translation>
    </message>
    <message>
        <source>Change
Language</source>
        <translation type="vanished">切换语言</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="57"/>
        <source>DCAC Fault Description</source>
        <translation>DCAC故障说明</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="71"/>
        <source>DCDC Module Fault Description</source>
        <translation>DCDC模块故障说明</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="81"/>
        <source>Battery Protection Logic Explanation</source>
        <translation>电池保护逻辑说明</translation>
    </message>
    <message>
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
        <translation type="vanished">电池充放电截止电压在并网及离网时的详细保护逻辑说明：
并网：
    电池放电放到放电截止电压-5V，（例如：截止电压是500V，那么495V就会截止放电）会报“放电不允许”告警，DCAC逆变输出功率降为0。
    当电池电压大于放电截止电压+放电回差电压或改为充电时，“放电不允许”告警消除。
    电池充电到充电电压上限时，会报“充电不允许”告警，DCAC若处于充电状态，充电功率降为0，DCAC若处于放电状态，则不受影响。
    当电池电压低于充电电压上限-充电回差电压或处于放电时，“充电不允许”告警消除。
离网：
    电池放电放到截止电压-5V（例如：截止电压是500V，那么495V就会截止放电）会报“放电不允许”告警，DCAC逆变停机。当电池电压大于放电截止电压+放电回差电压时，“放电不允许”告警消除，无关机命令下，恢复启动运行。
    电池充电到充电电压上限时，会报“充电不允许”告警，DCAC若处于充电状态，DCAC处于离网放电状态，则不受影响。
    当电池电压低于充电电压上限-充电回差电压，“充电不允许”告警消除。</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Alarm name</source>
        <translation>告警名称</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Alarm leve</source>
        <translation>告警等级</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Trigger condition</source>
        <translation>触发条件</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="53"/>
        <source>Response action</source>
        <translation>响应动作</translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="53"/>
        <source>Whether to reset
automatically and reset time</source>
        <translation>是否自动复位及复位时间</translation>
    </message>
</context>
<context>
    <name>GridExpansion</name>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="14"/>
        <source>Grid expansion</source>
        <translation>电网扩容</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="37"/>
        <source>Description</source>
        <translation>说明</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="54"/>
        <source>Logic Explanation:
   When selecting grid expansion mode, the converter will limit the input power of the grid.
Charging and discharging power calculation in grid expansion mode:
   Charging Power: When the converter load power is less than the set grid capacity and the current battery SOC is less than the charging SOC, the converter will charge the battery with the value of (Charging Power = Grid Capacity - Load Power). When the battery SOC reaches the charging stop SOC or the battery is prohibited from charging, the charging process will stop. When the battery SOC reaches 90% and the current charging power exceeds 80% of the maximum machine output power, the charging power will be set as (Charging Power = Maximum Machine Output Power / 2).
   Discharging Power: When the converter load power is greater than the set grid capacity, the converter will discharge power to compensate for the insufficient grid power, with the value of (Discharging Power = Load Power - Grid Capacity). When the battery&apos;s SOC is less than the discharging stop SOC or the battery is prohibited from discharging, the converter will maintain zero power operation. When the battery continues to discharge to reach the Depth of Discharge (DOD), DOD protection will be applied.
   Note: The charging and discharging power will not exceed the allowed charging power and discharging power stated in the battery data sheet. Constant power setting is invalid in grid expansion mode.</source>
        <translation>逻辑说明
    选择电网扩容模式，变流器会限制电网的输入功率。
    在电网扩容模式下的充电、放电功率计算
    充电功率：在变流器负载功率小于设置的电网容量时，并且当前电池SOC小于充电SOC时。变流器会以（充电功率=电网容量-负载功率）的值给电池充电。当电池SOC充电到达充电停止SOC或电池禁充时，会停止充电。当电池SOC充到90%，并且当前充电功率大于机器输出功率最大值的80%时，其（充电功率=机器输出功率最大值/2）。
    放电功率：在变流器负载功率大于设置的电网容量时，变流器会以（放电功率=负载功率-电网容量）的值往外放电，以弥补电网的不足。当电池的SOC小于放电停止SOC或电池禁放时，变流器维持0功率运行。当电池0功率继续放电到达DOD时，会进行DOD保护。
    注：充放电功率不会超过电池数据页的允许充电允许放电功率，电网扩容模式下设置恒功率无效。</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="87"/>
        <source>Generator Charge SOC</source>
        <translation>柴发充电SOC</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="95"/>
        <location filename="../GridExpansion/gridexpansion.ui" line="111"/>
        <location filename="../GridExpansion/gridexpansion.ui" line="127"/>
        <location filename="../GridExpansion/gridexpansion.ui" line="143"/>
        <source>%</source>
        <translation>%</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="103"/>
        <source>Grid Charge SOC</source>
        <translation>电网充电SOC</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="119"/>
        <source>Charge Stop SOC</source>
        <translation>充电停止SOC</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="135"/>
        <source>Discharge Stop SOC</source>
        <translation>放电停止SOC</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="151"/>
        <source>Grid capacity</source>
        <translation>电网容量</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="159"/>
        <source>kW</source>
        <translation>kW</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="173"/>
        <source>Logic Diagram</source>
        <translation>逻辑图</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="246"/>
        <source>Reload</source>
        <translation>重新加载</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="277"/>
        <source>Previous
Page</source>
        <translation>上一页</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="40"/>
        <source>Name</source>
        <translation>名称</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="40"/>
        <source>Value</source>
        <translation>值</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="40"/>
        <source>Unit</source>
        <translation>单位</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="48"/>
        <source>0</source>
        <translation>0</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="51"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation>柴发充电SOC</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="52"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation>柴发充电SOC：电网扩容模式下，当有柴发接入时，电池SOC低于此soc会充电。</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="55"/>
        <source>Charging SOC of Grid</source>
        <translation>电网充电SOC</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="56"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation>电网充电SOC：电网扩容模式下，柴发没有接入时，电池SOC低于此soc会充电。</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="59"/>
        <source>Charging Stop SOC</source>
        <translation>充电停止SOC</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="60"/>
        <source>Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC.</source>
        <translation>充电停止SOC：电网扩容模式下，电池处于充电状态时，电池SOC大于此SOC会停止充电。</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="63"/>
        <source>Discharging Stop SOC</source>
        <translation>放电停止SOC</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="64"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation>放电停止SOC：电网扩容模式下，电池SOC小于此SOC会停止放电。</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="67"/>
        <source>Grid Capacity</source>
        <translation>电网容量</translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="68"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation>电网容量：电网扩容模式下运行接入最大的电网功率。</translation>
    </message>
</context>
<context>
    <name>MEGAWin</name>
    <message>
        <source>MEGAWin</source>
        <translation type="vanished">MEGAWin</translation>
    </message>
    <message>
        <location filename="../win.ui" line="187"/>
        <source>Basic settings</source>
        <translation>基础设置</translation>
    </message>
    <message>
        <location filename="../win.ui" line="222"/>
        <source>Function Setting</source>
        <translation>功能设置</translation>
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
        <translation></translation>
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
        <translation></translation>
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
        <translation></translation>
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
        <translation></translation>
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
        <translation></translation>
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
        <translation></translation>
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
        <translation></translation>
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
        <translation></translation>
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
        <translation></translation>
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
        <translation></translation>
    </message>
    <message>
        <location filename="../win.ui" line="443"/>
        <source>User PassPort</source>
        <translation>用户密码</translation>
    </message>
    <message>
        <location filename="../win.ui" line="895"/>
        <location filename="../win.ui" line="1998"/>
        <location filename="../win.ui" line="9065"/>
        <source>11</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../win.ui" line="900"/>
        <location filename="../win.ui" line="2003"/>
        <location filename="../win.ui" line="9070"/>
        <source>12</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../win.ui" line="363"/>
        <location filename="../win.cpp" line="4626"/>
        <source>Battery type</source>
        <translation>电池类型</translation>
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
        <translation>-</translation>
    </message>
    <message>
        <source>Host Address</source>
        <translation type="vanished">主机地址</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4770"/>
        <source>ProtocolVersion</source>
        <translation>协议版本</translation>
    </message>
    <message>
        <location filename="../win.ui" line="411"/>
        <source>BMS Comm. type</source>
        <translation>电池通讯方式</translation>
    </message>
    <message>
        <source>serial port 1</source>
        <translation type="vanished">串口1</translation>
    </message>
    <message>
        <location filename="../win.ui" line="435"/>
        <location filename="../win.ui" line="483"/>
        <location filename="../win.ui" line="531"/>
        <location filename="../win.ui" line="579"/>
        <location filename="../win.ui" line="627"/>
        <source>bps</source>
        <translation>bps</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4779"/>
        <source>UserPassPort</source>
        <translation>用户密码</translation>
    </message>
    <message>
        <location filename="../win.ui" line="459"/>
        <location filename="../win.cpp" line="4644"/>
        <source>Power control type</source>
        <translation>功率控制类型</translation>
    </message>
    <message>
        <location filename="../win.ui" line="427"/>
        <location filename="../win.cpp" line="4706"/>
        <source>serial port 2</source>
        <translation>串口2</translation>
    </message>
    <message>
        <source>RootPassport</source>
        <translation type="vanished">超级权限</translation>
    </message>
    <message>
        <location filename="../win.ui" line="507"/>
        <source>EMS Comm. type</source>
        <translation>EMS通讯方式</translation>
    </message>
    <message>
        <location filename="../win.ui" line="475"/>
        <location filename="../win.cpp" line="4715"/>
        <source>serial port 3</source>
        <translation>串口3</translation>
    </message>
    <message>
        <location filename="../win.ui" line="539"/>
        <location filename="../win.cpp" line="4797"/>
        <source>Language</source>
        <translation>语言</translation>
    </message>
    <message>
        <location filename="../win.ui" line="555"/>
        <location filename="../win.cpp" line="4666"/>
        <source>Output power limit</source>
        <translation>输出功率上限</translation>
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
        <translation>kW</translation>
    </message>
    <message>
        <location filename="../win.ui" line="523"/>
        <location filename="../win.cpp" line="4725"/>
        <source>serial port 4</source>
        <translation>串口4</translation>
    </message>
    <message>
        <location filename="../win.ui" line="587"/>
        <source>System upgrade</source>
        <translation>系统升级</translation>
    </message>
    <message>
        <source>BAT manufacturers</source>
        <translation type="vanished">电池厂家</translation>
    </message>
    <message>
        <location filename="../win.ui" line="571"/>
        <location filename="../win.cpp" line="4734"/>
        <source>serial port 5</source>
        <translation>串口5</translation>
    </message>
    <message>
        <location filename="../win.ui" line="635"/>
        <location filename="../win.cpp" line="4819"/>
        <source>Sounds</source>
        <translation>声音</translation>
    </message>
    <message>
        <source>Power Delta</source>
        <translation type="vanished">功率回差</translation>
    </message>
    <message>
        <location filename="../win.ui" line="659"/>
        <location filename="../win.cpp" line="4752"/>
        <source>Can port 1</source>
        <translation>CAN 1</translation>
    </message>
    <message>
        <location filename="../win.ui" line="667"/>
        <location filename="../win.ui" line="720"/>
        <source>kbps</source>
        <translation>kbps</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9386"/>
        <location filename="../win.cpp" line="3607"/>
        <source>Charge power limit</source>
        <translation>充电功率限制</translation>
    </message>
    <message>
        <location filename="../win.ui" line="712"/>
        <location filename="../win.cpp" line="4761"/>
        <source>Can port 2</source>
        <translation>CAN 2</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9402"/>
        <location filename="../win.cpp" line="3616"/>
        <source>Discharge power limit</source>
        <translation>放电功率限制</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9226"/>
        <source>Charge Vol. upper Limit delta</source>
        <translation>充电电压上限回差</translation>
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
        <translation>V</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9290"/>
        <source>Discharge Vol. lower Limit delta</source>
        <translation>充电电压下限回差</translation>
    </message>
    <message>
        <location filename="../win.ui" line="802"/>
        <source>System parameter</source>
        <translation>系统参数</translation>
    </message>
    <message>
        <source>Change rate of power</source>
        <translation type="vanished">功率变化率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="958"/>
        <source>kW/s</source>
        <translation>kW/s</translation>
    </message>
    <message>
        <location filename="../win.ui" line="966"/>
        <location filename="../win.cpp" line="4972"/>
        <source>Machine type</source>
        <translation>机器型号</translation>
    </message>
    <message>
        <location filename="../win.ui" line="987"/>
        <location filename="../win.cpp" line="5082"/>
        <source>Module Number</source>
        <translation>模块数量</translation>
    </message>
    <message>
        <source>Grid frequency upper limit</source>
        <translation type="vanished">电网频率变化范围上限</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1021"/>
        <location filename="../win.ui" line="1069"/>
        <location filename="../win.ui" line="1085"/>
        <location filename="../win.ui" line="1325"/>
        <source>Hz</source>
        <translation>Hz</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1029"/>
        <location filename="../win.cpp" line="4981"/>
        <source>Machine capacity</source>
        <translation>机器容量</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1045"/>
        <location filename="../win.cpp" line="5091"/>
        <source>Restore factory</source>
        <translation>恢复出厂</translation>
    </message>
    <message>
        <source>Grid frequency lower limit</source>
        <translation type="vanished">电网频率变化范围下限</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1077"/>
        <source>Output Fre. grade</source>
        <translation>输出频率等级</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1189"/>
        <location filename="../win.cpp" line="5118"/>
        <source>Clear Data</source>
        <translation>清除数据</translation>
    </message>
    <message>
        <source>Vol protection\n upper limit</source>
        <translation type="vanished">电压保护范围上限</translation>
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
        <translation>%</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1125"/>
        <source>Output vol. level</source>
        <translation>输出电压等级</translation>
    </message>
    <message>
        <source>Vol protection\n lower limit</source>
        <translation type="vanished">电压保护范围下限</translation>
    </message>
    <message>
        <source>Converter side vol. level</source>
        <translation type="vanished">逆变电压等级</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1205"/>
        <location filename="../win.cpp" line="4908"/>
        <source>HVRT enable</source>
        <translation>高压穿越使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1221"/>
        <location filename="../win.cpp" line="5017"/>
        <source>Output reactive power mode</source>
        <translation>输出无功方式</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1237"/>
        <location filename="../win.cpp" line="4917"/>
        <source>LVRT enable</source>
        <translation>低压穿越使能</translation>
    </message>
    <message>
        <source>Grid connected mode of Inv</source>
        <translation type="vanished">逆变器并网方式</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1269"/>
        <location filename="../win.cpp" line="4926"/>
        <source>AFD enable</source>
        <translation>孤岛使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1317"/>
        <location filename="../win.cpp" line="5046"/>
        <source>Primary FM dead zone</source>
        <translation>一次调频死区</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1301"/>
        <location filename="../win.cpp" line="4936"/>
        <source>Insulation detection enable</source>
        <translation>绝缘监测使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1354"/>
        <location filename="../win.cpp" line="5055"/>
        <source>PFM coeff</source>
        <translation>有功调频系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1362"/>
        <source>kW/Hz</source>
        <translation>kW/Hz</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1338"/>
        <location filename="../win.cpp" line="4945"/>
        <source>PrimaryFreq enable</source>
        <translation>一次调频使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1386"/>
        <location filename="../win.cpp" line="5064"/>
        <source>Grid recover time</source>
        <translation>电网恢复并网时间</translation>
    </message>
    <message>
        <location filename="../win.ui" line="736"/>
        <location filename="../win.ui" line="784"/>
        <location filename="../win.ui" line="1394"/>
        <source>s</source>
        <translation>s</translation>
    </message>
    <message>
        <location filename="../win.ui" line="675"/>
        <location filename="../win.cpp" line="4828"/>
        <source>Energy Meter Model</source>
        <translation>电能表型号</translation>
    </message>
    <message>
        <location filename="../win.ui" line="728"/>
        <source>BMS Com. Fault Time</source>
        <translation>BMS通信故障判定时间</translation>
    </message>
    <message>
        <location filename="../win.ui" line="776"/>
        <source>EMS Com. Fault Time</source>
        <translation>EMS通信故障判定时间</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1093"/>
        <source>Backup setup parameters</source>
        <translation>备份设置参数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1141"/>
        <source>Restore backup setup parameters</source>
        <translation>恢复备份设置参数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1370"/>
        <location filename="../win.cpp" line="4954"/>
        <source>Inertia enable</source>
        <translation>转动惯量使能</translation>
    </message>
    <message>
        <source>DynamicCap</source>
        <translation type="vanished">电网扩容使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1402"/>
        <location filename="../win.cpp" line="4963"/>
        <source>CV parallel</source>
        <translation>恒压并机使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1438"/>
        <source>External device</source>
        <translation>外设</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1478"/>
        <source>DI_1</source>
        <translation>DI_1</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1483"/>
        <source>DI_2</source>
        <translation>DI_2</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1488"/>
        <source>DI_3</source>
        <translation>DI_3</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1493"/>
        <source>DI_4</source>
        <translation>DI_4</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1498"/>
        <source>DI_5</source>
        <translation>DI_5</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1503"/>
        <source>DI_6</source>
        <translation>DI_6</translation>
    </message>
    <message>
        <source>DO_1</source>
        <translation type="vanished">DO_1</translation>
    </message>
    <message>
        <source>DO_2</source>
        <translation type="vanished">DO_2</translation>
    </message>
    <message>
        <source>DO_3</source>
        <translation type="vanished">DO_3</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1523"/>
        <source>Enable/Disable</source>
        <translation>使能/禁止</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1528"/>
        <source>NC/NO</source>
        <translation>NC/NO</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1533"/>
        <location filename="../win.ui" line="1819"/>
        <source>Action</source>
        <translation>动作</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1538"/>
        <source>Function description</source>
        <translation>功能描述</translation>
    </message>
    <message>
        <source>Shut Down NO</source>
        <translation type="vanished">NO关机</translation>
    </message>
    <message>
        <source>Shut Down NC</source>
        <translation type="vanished">NC关机</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1575"/>
        <source>Access Control</source>
        <translation>门禁</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1583"/>
        <source>Full Power</source>
        <translation>满功率信号</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1591"/>
        <source>Smoke</source>
        <translation>烟雾</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1599"/>
        <source>Temperature</source>
        <translation>温度</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1618"/>
        <location filename="../win.ui" line="1662"/>
        <location filename="../win.ui" line="1706"/>
        <source>N_O</source>
        <translation>N_O</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1640"/>
        <source>Generator</source>
        <translation>发电机</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1684"/>
        <location filename="../win.ui" line="1728"/>
        <source>Reserve</source>
        <translation>保留</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1749"/>
        <source>BMS protection</source>
        <translation>BMS保护</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1789"/>
        <source>DOD</source>
        <translation>DOD</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1794"/>
        <location filename="../win.cpp" line="5298"/>
        <source>Prohibit charging</source>
        <translation>禁充</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1799"/>
        <location filename="../win.cpp" line="5307"/>
        <source>Prohibit discharging</source>
        <translation>禁放</translation>
    </message>
    <message>
        <source>BMS warning</source>
        <translation type="vanished">BMS提示     </translation>
    </message>
    <message>
        <source>BMS alarm</source>
        <translation type="vanished">BMS告警     </translation>
    </message>
    <message>
        <source>BMS fualt</source>
        <translation type="vanished">BMS故障     </translation>
    </message>
    <message>
        <source>Charge power</source>
        <translation type="vanished">充电功率</translation>
    </message>
    <message>
        <source>Discharge power</source>
        <translation type="vanished">放电功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1908"/>
        <source>Debug</source>
        <translation>调试</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2038"/>
        <location filename="../win.cpp" line="5405"/>
        <source>Debug variable 1</source>
        <translation>调试变量1</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2046"/>
        <source>1.5V Voltage revise</source>
        <translation>1.5V电压系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2054"/>
        <source>INV A inductance Cur. revise</source>
        <translation>逆变A相电感电流系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2059"/>
        <location filename="../win.cpp" line="5413"/>
        <source>Debug variable 2</source>
        <translation>调试变量2</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2067"/>
        <source> Bus Vol. revise</source>
        <translation> 母线电压系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2075"/>
        <source>INV B inductance Cur. revise</source>
        <translation>逆变B相电感电流系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2080"/>
        <location filename="../win.cpp" line="5421"/>
        <source>Debug variable 3</source>
        <translation>调试变量3</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2088"/>
        <source>Grid A/AB Vol. revise</source>
        <translation>电网A相电压系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2093"/>
        <source>INV C inductance Cur. revise</source>
        <translation>逆变C相电感电流系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2098"/>
        <source>Debug variable 1 address</source>
        <translation>调试地址变量1</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2106"/>
        <source>Grid B/BC Vol. revise</source>
        <translation>电网B相电压系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2111"/>
        <location filename="../win.cpp" line="5605"/>
        <source>INV On off flag</source>
        <translation>开关机状态字</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2116"/>
        <source>Debug variable 2 address</source>
        <translation>调试地址变量2</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2124"/>
        <source>Grid C/CA Vol. revise</source>
        <translation>电网C相电压系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2129"/>
        <location filename="../win.cpp" line="5613"/>
        <source>Logic state</source>
        <translation>逻辑状态字</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2134"/>
        <source>Debug variable 3 address</source>
        <translation>调试地址变量3</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2142"/>
        <source>Output A Cur. revise</source>
        <translation>输出A相电流系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2147"/>
        <location filename="../win.cpp" line="5621"/>
        <source>INV flag</source>
        <translation>逆变状态字</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2152"/>
        <source>Debug memery var. 1</source>
        <translation>调试内存变量1</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2160"/>
        <source>Output B Cur. revise</source>
        <translation>输出B相电流系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2165"/>
        <location filename="../win.cpp" line="5629"/>
        <source>Grid flag</source>
        <translation>电网状态字</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2170"/>
        <source>Debug memery var. 2</source>
        <translation>调试内存变量2</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2178"/>
        <source>Output C Cur. revise</source>
        <translation>输出C相电流系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2183"/>
        <location filename="../win.cpp" line="5637"/>
        <source>Grid protect flag</source>
        <translation>电网保护状态字</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2188"/>
        <source>Debug memery var. 3</source>
        <translation>调试内存变量3</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2196"/>
        <source>INV A Vol. revise</source>
        <translation>逆变A相电压系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2201"/>
        <location filename="../win.cpp" line="5645"/>
        <source>Bat flag</source>
        <translation>电池状态字</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2206"/>
        <source>Input Vol. revise</source>
        <translation>输入电压系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2214"/>
        <source>INV B Vol. revise</source>
        <translation>逆变B相电压系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2219"/>
        <location filename="../win.cpp" line="5653"/>
        <source>DC bus flag</source>
        <translation>母线状态字</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2227"/>
        <source>Input. Cur. revise</source>
        <translation>输入电流系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2235"/>
        <source>INV C Vol. revise</source>
        <translation>逆变C相电压系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2240"/>
        <location filename="../win.cpp" line="5661"/>
        <source>INT main flag</source>
        <translation>中断状态字</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2248"/>
        <location filename="../win.cpp" line="5669"/>
        <source>parallel signal</source>
        <translation>并机状态字</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2266"/>
        <source>MonitorDebug</source>
        <translation>监控调试</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2317"/>
        <source>DO control:</source>
        <translation>DO 控制:</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2329"/>
        <source>DO_TurnON_btn</source>
        <translation>DO_闭合</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2342"/>
        <source>DO_TurnOFF_btn</source>
        <translation>DO_断开</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2378"/>
        <source>Soft start</source>
        <translation>软启动</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2403"/>
        <source>Local_on</source>
        <translation>本地启动</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2390"/>
        <source>Local_off</source>
        <translation>本地关闭</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2462"/>
        <location filename="../win.cpp" line="5740"/>
        <source>test data</source>
        <translation>测试数据</translation>
    </message>
    <message>
        <source>Please click to enter and query the detailed information of the alarm message you have encountered.</source>
        <translation type="vanished">请点击进入，查询您所遇到的告警信息的详细信息。</translation>
    </message>
    <message>
        <source>alarm
message</source>
        <translation type="vanished">告警信息</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9560"/>
        <location filename="../win.cpp" line="2299"/>
        <source>Battery power on</source>
        <translation>电池上电</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9579"/>
        <location filename="../win.cpp" line="2303"/>
        <source>Battery power off</source>
        <translation>电池下电</translation>
    </message>
    <message>
        <source> SN:</source>
        <translation type="vanished">    SN:</translation>
    </message>
    <message>
        <source>PCS-TS</source>
        <translation type="vanished">PCS-TS</translation>
    </message>
    <message>
        <source>100kW</source>
        <translation type="vanished">100kW</translation>
    </message>
    <message>
        <source>50Hz</source>
        <translation type="vanished">50Hz</translation>
    </message>
    <message>
        <source>PCS Data</source>
        <translation type="vanished">PCS 数据</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4629"/>
        <source>Converter</source>
        <translation>变流器</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4669"/>
        <source>Grid</source>
        <translation>电网</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4709"/>
        <source>Load</source>
        <translation>负载</translation>
    </message>
    <message>
        <source>PCS State</source>
        <translation type="vanished">PCS 状态</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4929"/>
        <location filename="../win.cpp" line="1868"/>
        <location filename="../win.cpp" line="1871"/>
        <source>DC input breaker</source>
        <translation>直流输入断路器</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4934"/>
        <location filename="../win.cpp" line="1876"/>
        <location filename="../win.cpp" line="3294"/>
        <source>converter available</source>
        <translation>变流器使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4939"/>
        <source>DO1</source>
        <translation>柴发信号</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4944"/>
        <location filename="../win.cpp" line="1868"/>
        <location filename="../win.cpp" line="1871"/>
        <location filename="../win.cpp" line="3240"/>
        <source>DC contactor</source>
        <translation>直流接触器</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4949"/>
        <location filename="../win.cpp" line="1876"/>
        <location filename="../win.cpp" line="3303"/>
        <source>DC Soft start</source>
        <translation>直流软启动</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4954"/>
        <location filename="../win.cpp" line="1879"/>
        <location filename="../win.cpp" line="3348"/>
        <source>DO2</source>
        <translation>DO2</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4959"/>
        <location filename="../win.cpp" line="1869"/>
        <location filename="../win.cpp" line="1872"/>
        <location filename="../win.cpp" line="3249"/>
        <source>Output contactor</source>
        <translation>输出接触器</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4964"/>
        <location filename="../win.cpp" line="1877"/>
        <location filename="../win.cpp" line="3312"/>
        <source>converter status</source>
        <translation>变流器状态</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4969"/>
        <location filename="../win.cpp" line="1880"/>
        <location filename="../win.cpp" line="3357"/>
        <source>DO3</source>
        <translation>DO3</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4974"/>
        <location filename="../win.cpp" line="1869"/>
        <location filename="../win.cpp" line="1872"/>
        <source>Output breaker</source>
        <translation>输出断路器</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4979"/>
        <location filename="../win.cpp" line="1877"/>
        <source>Reactive power Regulation</source>
        <translation>无功调节方式</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4984"/>
        <source>DI1</source>
        <translation>EPO节点 信号1</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4989"/>
        <location filename="../win.cpp" line="1873"/>
        <location filename="../win.cpp" line="3267"/>
        <source>Grid contactor</source>
        <translation>电网接触器</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4994"/>
        <location filename="../win.cpp" line="1877"/>
        <location filename="../win.cpp" line="3330"/>
        <source>LVRT</source>
        <translation>LVRT</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4999"/>
        <source>DI2</source>
        <translation>EPO节点 信号2</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5004"/>
        <location filename="../win.cpp" line="1869"/>
        <location filename="../win.cpp" line="1873"/>
        <source>Grid breaker</source>
        <translation>电网断路器</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5014"/>
        <source>DI3</source>
        <translation>门禁信号</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5024"/>
        <source>DI4</source>
        <translation>满功率信号</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5029"/>
        <source>DI5</source>
        <translation>水浸信号</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5034"/>
        <source>DI6</source>
        <translation>高温信号</translation>
    </message>
    <message>
        <source>PCS Alarm</source>
        <translation type="vanished">PCS告警</translation>
    </message>
    <message>
        <source>Please enter search keywords</source>
        <translation type="vanished">请输入搜索关键词</translation>
    </message>
    <message>
        <source>Search</source>
        <translation type="vanished">搜索</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5209"/>
        <source>Battery Data</source>
        <translation>电池数据</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6859"/>
        <source>prompt:</source>
        <translation>提示：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6887"/>
        <source>Normal</source>
        <translation>正常</translation>
    </message>
    <message>
        <source>Warning1</source>
        <translation type="vanished">一级告警</translation>
    </message>
    <message>
        <source>Warning2</source>
        <translation type="vanished">二级告警</translation>
    </message>
    <message>
        <source>Warning3</source>
        <translation type="vanished">三级告警</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7119"/>
        <source>Alarm level:</source>
        <translation>告警等级：</translation>
    </message>
    <message>
        <source>Charge 
enable</source>
        <translation type="vanished">充电使能</translation>
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
        <translation>禁止</translation>
    </message>
    <message>
        <source>Discharge 
enable</source>
        <translation type="vanished">放电使能</translation>
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
        <translation>名称</translation>
    </message>
    <message>
        <source>Charging current limite</source>
        <translation type="vanished">充电电流上限</translation>
    </message>
    <message>
        <source>Discharging current limite</source>
        <translation type="vanished">放电电流上限</translation>
    </message>
    <message>
        <source>Allow charge power</source>
        <translation type="vanished">可充电功率</translation>
    </message>
    <message>
        <source>Allow discharge power</source>
        <translation type="vanished">可放电功率</translation>
    </message>
    <message>
        <source>Allow charge energy</source>
        <translation type="vanished">允许充电量</translation>
    </message>
    <message>
        <source>Allow discharge energy</source>
        <translation type="vanished">允许放电量</translation>
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
        <translation>值</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4846"/>
        <source>120</source>
        <translation>120</translation>
    </message>
    <message>
        <source>135</source>
        <translation type="vanished">135</translation>
    </message>
    <message>
        <source>45</source>
        <translation type="vanished">45</translation>
    </message>
    <message>
        <source>95</source>
        <translation type="vanished">95</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5890"/>
        <location filename="../win.ui" line="6616"/>
        <location filename="../win.ui" line="9715"/>
        <location filename="../win.ui" line="9730"/>
        <location filename="../win.cpp" line="1048"/>
        <source>Unit</source>
        <translation>单位</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5947"/>
        <location filename="../win.ui" line="6643"/>
        <location filename="../win.ui" line="6670"/>
        <location filename="../win.ui" line="8813"/>
        <location filename="../win.ui" line="9330"/>
        <location filename="../win.ui" line="9362"/>
        <source>A</source>
        <translation>A</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6751"/>
        <location filename="../win.ui" line="6778"/>
        <source>kWh</source>
        <translation>kWh</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5414"/>
        <source>Bat voltage</source>
        <translation>电池电压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="41"/>
        <source>PCS</source>
        <translation>PCS</translation>
    </message>
    <message>
        <location filename="../win.ui" line="158"/>
        <location filename="../win.ui" line="2656"/>
        <source>Change
Language</source>
        <translation>切换语言</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1173"/>
        <location filename="../win.cpp" line="5008"/>
        <source>Transformer Turns Ratio</source>
        <translation>变压器变比</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1508"/>
        <source>DO_1   </source>
        <translation>DO_1   </translation>
    </message>
    <message>
        <location filename="../win.ui" line="1513"/>
        <source>DO_2    </source>
        <translation>DO_2    </translation>
    </message>
    <message>
        <location filename="../win.ui" line="1518"/>
        <source>DO_3    </source>
        <translation>DO_3    </translation>
    </message>
    <message>
        <source>TS</source>
        <translation type="vanished">TS</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4104"/>
        <source>Converter Data</source>
        <translation>变流器数据</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4743"/>
        <location filename="../win.cpp" line="5724"/>
        <source>Converter State</source>
        <translation>变流器状态</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5059"/>
        <source>Converter Alarm</source>
        <translation>变流器告警</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5444"/>
        <location filename="../win.cpp" line="2801"/>
        <source>Bat current</source>
        <translation>电池电流</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5474"/>
        <location filename="../win.cpp" line="2805"/>
        <source>SOC</source>
        <translation>SOC</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5504"/>
        <location filename="../win.cpp" line="2809"/>
        <source>SOH</source>
        <translation>SOH</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5534"/>
        <source>Cell voltage (max)</source>
        <translation>单体最高电压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5564"/>
        <source>Cell voltage (min)</source>
        <translation>单体最低电压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5594"/>
        <source>Cell temp. (max)</source>
        <translation>单体最高温度</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5624"/>
        <source>Cell temp. (min)</source>
        <translation>单体最低温度</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3489"/>
        <source>600</source>
        <translation>600</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3480"/>
        <source>100</source>
        <translation>100</translation>
    </message>
    <message>
        <source>70</source>
        <translation type="vanished">70</translation>
    </message>
    <message>
        <source>3300</source>
        <translation type="vanished">3300</translation>
    </message>
    <message>
        <source>3250</source>
        <translation type="vanished">3250</translation>
    </message>
    <message>
        <source>28</source>
        <translation type="vanished">28</translation>
    </message>
    <message>
        <source>27</source>
        <translation type="vanished">27</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6028"/>
        <location filename="../win.ui" line="6055"/>
        <location filename="../win.ui" line="9218"/>
        <location filename="../win.ui" line="9250"/>
        <source>mV</source>
        <translation>mV</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6082"/>
        <location filename="../win.ui" line="6109"/>
        <source>℃</source>
        <translation>℃</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6180"/>
        <location filename="../win.cpp" line="2829"/>
        <source>Charging current limit</source>
        <translation>充电电流限制</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6207"/>
        <location filename="../win.cpp" line="2833"/>
        <source>Discharging current limit</source>
        <translation>放电电流限制</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6234"/>
        <location filename="../win.cpp" line="2837"/>
        <source>Allowable charging power</source>
        <translation>可充电功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6262"/>
        <location filename="../win.cpp" line="2841"/>
        <source>Allowable discharging power</source>
        <translation>可放电功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6289"/>
        <location filename="../win.cpp" line="2845"/>
        <source>Allowable charging energy</source>
        <translation>可充电量</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6316"/>
        <location filename="../win.cpp" line="2849"/>
        <source>Allowable discharging energy</source>
        <translation>可放电量</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6943"/>
        <source>Level1 </source>
        <translation>一级告警</translation>
    </message>
    <message>
        <location filename="../win.ui" line="6999"/>
        <source>Level2</source>
        <translation>二级告警</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7055"/>
        <source>Level3</source>
        <translation>三级告警</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7175"/>
        <source>Charging
enable</source>
        <translation>充电使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7234"/>
        <source>Discharging
enable</source>
        <translation>放电使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7308"/>
        <source>Data report</source>
        <translation>数据报表</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7370"/>
        <source>Discharge:</source>
        <translation>放电：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7398"/>
        <source>1.1
kW.h</source>
        <translation>1.1
kW.h</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7418"/>
        <location filename="../win.ui" line="7628"/>
        <source>Day</source>
        <translation>日电量</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7455"/>
        <location filename="../win.ui" line="7503"/>
        <source>339
kW.h</source>
        <translation>339
kW.h</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7469"/>
        <location filename="../win.ui" line="7676"/>
        <source>Month</source>
        <translation>月电量</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7517"/>
        <location filename="../win.ui" line="7724"/>
        <source>Year</source>
        <translation>年电量</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7551"/>
        <source>585.1
kW.h</source>
        <translation>585.1
kW.h</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7565"/>
        <location filename="../win.ui" line="7772"/>
        <source>Total</source>
        <translation>总电量</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7586"/>
        <source>Charge:</source>
        <translation>充电：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7614"/>
        <source>2.4
kW.h</source>
        <translation>2.4
kW.h</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7662"/>
        <location filename="../win.ui" line="7710"/>
        <source>2.6
kW.h</source>
        <translation>2.6
kW.h</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7758"/>
        <source>184.2
kW.h</source>
        <translation>184.2
kW.h</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7863"/>
        <source>M  -</source>
        <translation>月 -</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7882"/>
        <source>Y  -</source>
        <translation>年 -</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7918"/>
        <source>M  +</source>
        <translation>月 +</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7937"/>
        <source>Y  +</source>
        <translation>年 +</translation>
    </message>
    <message>
        <location filename="../win.ui" line="7966"/>
        <source>Export Data</source>
        <translation>导出数据</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8027"/>
        <source>Note:</source>
        <translation>提示：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8044"/>
        <source>Out put file:</source>
        <translation>输出文件：</translation>
    </message>
    <message>
        <source>HistoryRecord.csv</source>
        <translation type="vanished">HistoryRecord.csv</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8080"/>
        <source>Log.csv</source>
        <translation>Log.csv</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8098"/>
        <source>Report.csv</source>
        <translation>Report.csv</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8143"/>
        <source>Data To Export</source>
        <translation>导出数据</translation>
    </message>
    <message>
        <source>static:</source>
        <translation type="vanished">状态：</translation>
    </message>
    <message>
        <source>HistoricalFailure</source>
        <translation type="vanished">历史记录</translation>
    </message>
    <message>
        <source>OperationLog</source>
        <translation type="vanished">操作日志</translation>
    </message>
    <message>
        <source>Coulombmeter report</source>
        <translation type="vanished">电量统计表</translation>
    </message>
    <message>
        <source>Eject Udisk</source>
        <translation type="vanished">退出U盘</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8398"/>
        <source>History Record</source>
        <translation>历史记录</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8282"/>
        <location filename="../win.ui" line="8417"/>
        <location filename="../win.cpp" line="2223"/>
        <source>Operation Log</source>
        <translation>操作日志</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8447"/>
        <source>Parameter setting</source>
        <translation>参数设置</translation>
    </message>
    <message>
        <source>Grid connected mode of PCS</source>
        <translation type="vanished">PCS并网方式</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8581"/>
        <location filename="../win.cpp" line="3500"/>
        <source>Control mode</source>
        <translation>控制模式</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8605"/>
        <source>Constant power (AC)</source>
        <translation>恒功率(AC)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8629"/>
        <location filename="../win.cpp" line="3510"/>
        <source>Machine number</source>
        <translation>设备号</translation>
    </message>
    <message>
        <source>Charging and discharging</source>
        <translation type="vanished">充放电</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8677"/>
        <source>Parallel </source>
        <translation>并机</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8653"/>
        <source>Work mode</source>
        <translation>工作模式</translation>
    </message>
    <message>
        <source>Unbalance power enable</source>
        <translation type="vanished">功率不平衡使能</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8701"/>
        <location filename="../win.cpp" line="3462"/>
        <source>Output power factor</source>
        <translation>输出功率因素</translation>
    </message>
    <message>
        <source>Phase A power</source>
        <translation type="vanished">A相功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8749"/>
        <location filename="../win.cpp" line="3471"/>
        <source>Output reactive power</source>
        <translation>输出无功功率</translation>
    </message>
    <message>
        <source>Phase B power</source>
        <translation type="vanished">B相功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8797"/>
        <location filename="../win.cpp" line="3480"/>
        <source>Constant current</source>
        <translation>恒流</translation>
    </message>
    <message>
        <source>Phase C power</source>
        <translation type="vanished">C相功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8845"/>
        <location filename="../win.cpp" line="3489"/>
        <source>Constant voltage</source>
        <translation>恒压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8955"/>
        <source>  Title</source>
        <translation>  标题</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8975"/>
        <source>Return</source>
        <translation>返回</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8984"/>
        <source>Battery setup</source>
        <translation>电池设置</translation>
    </message>
    <message>
        <source>A1: 
Generator turn on SOC
B1: 
Generator turn off SOC
A1 Setting range: [10%, 50%]
B1 Setting range: [50%, 100%]
Set rule:
B1 - A1 ≥ 30 %
</source>
        <translation type="vanished">A1: 
发电机关闭 SOC值
B1: 
柴发关闭 SOC
A1 设定范围: [10%, 50%]
B1 设定范围: [50%, 100%]
设置规则:
B1 - A1 ≥ 30 %
</translation>
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
        <translation></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9735"/>
        <location filename="../win.cpp" line="3763"/>
        <source>Capacity</source>
        <translation>容量</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9751"/>
        <source>Grid off EOD</source>
        <translation>离网EOD</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9767"/>
        <source>Cell number(2V)</source>
        <translation>电池节数(2V)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9783"/>
        <source>Grid on EOD</source>
        <translation>并网EOD</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9799"/>
        <location filename="../win.cpp" line="3773"/>
        <source>Battery float voltage</source>
        <translation>电池浮充电压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9815"/>
        <source>Shutdown voltage point</source>
        <translation>关机电压点</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9860"/>
        <location filename="../win.cpp" line="3778"/>
        <source>Battery filling voltage</source>
        <translation>电池均充电压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9876"/>
        <source>Mending center point</source>
        <translation>温补中心点</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9930"/>
        <location filename="../win.cpp" line="3783"/>
        <source>Charge limiting value</source>
        <translation>充电限流值</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9938"/>
        <location filename="../win.ui" line="10002"/>
        <location filename="../win.ui" line="10163"/>
        <location filename="../win.ui" line="10179"/>
        <source>C</source>
        <translation>C</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9946"/>
        <source>Temperature filling coefficient</source>
        <translation>温补系数</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9994"/>
        <location filename="../win.cpp" line="3788"/>
        <source>Discharge limiting value</source>
        <translation>放电限流值</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10010"/>
        <source>Mending allowable setting</source>
        <translation>温补允许设置</translation>
    </message>
    <message>
        <source>Generator turn off SOC(B1)</source>
        <translation type="vanished">发电机关闭SOC(B1)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10074"/>
        <source>Temperature alarm upper limit</source>
        <translation>温度告警上限</translation>
    </message>
    <message>
        <source>Generator turn on SOC(A1)</source>
        <translation type="vanished">发电机开启SOC(A1)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10138"/>
        <location filename="../win.cpp" line="3813"/>
        <source>Uniform charging and flushing current</source>
        <translation>均充转浮充电流</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10171"/>
        <location filename="../win.cpp" line="3818"/>
        <source>Float turn uniform charging current</source>
        <translation>浮充转均充电流</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9130"/>
        <source>DOD_OnGrid:</source>
        <translation>并网DOD：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1551"/>
        <source>Dry Contact EPO</source>
        <translation>干接点EPO</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1567"/>
        <source>Dry Contact Shutdown</source>
        <translation>干接点关机</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1804"/>
        <source>Level 1 Alarm</source>
        <translation>一级告警    </translation>
    </message>
    <message>
        <location filename="../win.ui" line="1809"/>
        <source>Level 2 Alarm</source>
        <translation>二级告警    </translation>
    </message>
    <message>
        <location filename="../win.ui" line="1814"/>
        <source>Level 3 Alarm</source>
        <translation>三级告警    </translation>
    </message>
    <message>
        <source>100kW-TS</source>
        <translation type="vanished">100kW-TS</translation>
    </message>
    <message>
        <source>Please click to enter and query the detailed information
of the alarm message you have encountered.</source>
        <translation type="vanished">请点击进入，查询您所遇到的告警信息的详细信息。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8062"/>
        <source>Record.csv</source>
        <translation>Record.csv</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8183"/>
        <source>status:</source>
        <translation>状态：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8216"/>
        <source>u disk disconnect!</source>
        <translation>U盘未插入！</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8251"/>
        <location filename="../win.cpp" line="2219"/>
        <source>Historical Failure</source>
        <translation>导出历史记录</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8316"/>
        <location filename="../win.cpp" line="2227"/>
        <source>Electricity Statistical Table</source>
        <translation>电量统计表</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8347"/>
        <location filename="../win.cpp" line="2231"/>
        <source>Eject U disk</source>
        <translation>退出U盘</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8557"/>
        <source>Grid conected mode of the converter</source>
        <translation>变流器并网方式</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9146"/>
        <source>Turn on SOC</source>
        <translation>启动SOC</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9162"/>
        <source>DOD_OffGrid:</source>
        <translation>离网DOD：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9178"/>
        <source>Turn off SOC</source>
        <translation>停止SOC</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9194"/>
        <source>Charge Vol. upper Limit</source>
        <translation>充电电压上限</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9210"/>
        <source>Turn on cell vol.</source>
        <translation>启动单体电压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9258"/>
        <source>Discharge Vol. lower Limit</source>
        <translation>放电电压下限</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9242"/>
        <source>Turn off cell vol.</source>
        <translation>停止单体电压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9322"/>
        <source>Charge Cur. Limit</source>
        <translation>充电电流限制</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9274"/>
        <source>Turn on total vol.</source>
        <translation>启动总压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9418"/>
        <location filename="../win.cpp" line="3625"/>
        <source>Generator turn off SOC</source>
        <translation>发电机关闭SOC</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9306"/>
        <source>Turn off total vol.</source>
        <translation>停止总压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9434"/>
        <source>Generator turn on SOC</source>
        <translation>发电机开启SOC</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9338"/>
        <source>UPS charge power</source>
        <translation>后备充电功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9450"/>
        <source>Generator charge SOC</source>
        <translation>柴发充电SOC</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9370"/>
        <source>Monthly cycle time</source>
        <translation>月循环日期</translation>
    </message>
    <message>
        <location filename="../win.ui" line="2698"/>
        <source>100kW - TS</source>
        <translation>100kW - TS</translation>
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
        <translation>0A</translation>
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
        <translation>0V</translation>
    </message>
    <message>
        <location filename="../win.ui" line="3328"/>
        <source>40%</source>
        <translation>40%</translation>
    </message>
    <message>
        <location filename="../win.ui" line="3312"/>
        <source>SOC:</source>
        <translation>剩余电量：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1008"/>
        <location filename="../win.cpp" line="4872"/>
        <source>ULFV</source>
        <translation>电网频率变化范围上限</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1061"/>
        <location filename="../win.cpp" line="4881"/>
        <source>LLFV</source>
        <translation>电网频率变化范围下限</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1285"/>
        <location filename="../win.cpp" line="5036"/>
        <source>System Anti-Reverse Flow</source>
        <translation>系统防逆流</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1824"/>
        <source>Charge power(kW)</source>
        <translation>充电功率(kW)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1829"/>
        <source>Discharge power(kW)</source>
        <translation>放电功率(kW)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5097"/>
        <source>Please click on &apos;Alarm Information&apos; to enter the query interface
and view the details of the alarm information you have encountered.</source>
        <translation>请点击&apos;告警信息&apos;，进入查询界面，查看您所遇到的告警信息的详情。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5158"/>
        <source>Alarm
Information</source>
        <translation>告警信息</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9075"/>
        <source>13</source>
        <translation>13</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9080"/>
        <source>14</source>
        <translation>14</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9085"/>
        <source>15</source>
        <translation>15</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9090"/>
        <source>16</source>
        <translation>16</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9095"/>
        <source>17</source>
        <translation>17</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9354"/>
        <source>Discharge Cur. Limit</source>
        <translation>放电电流限制</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9466"/>
        <location filename="../win.cpp" line="3652"/>
        <source>Grid charge SOC</source>
        <translation>电网充电SOC</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9482"/>
        <location filename="../win.cpp" line="3661"/>
        <source>Charge Stop SOC</source>
        <translation>充电停止SOC</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9498"/>
        <location filename="../win.cpp" line="3670"/>
        <source>Discharge Stop SOC</source>
        <translation>放电停止SOC</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9514"/>
        <source>Grid capacity</source>
        <translation>电网容量</translation>
    </message>
    <message>
        <source>BMS power on</source>
        <translation type="vanished">电池上电</translation>
    </message>
    <message>
        <source>BMS power off</source>
        <translation type="vanished">电池下电</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9591"/>
        <source>Lead</source>
        <translation>铅酸</translation>
    </message>
    <message>
        <location filename="../win.ui" line="9631"/>
        <source>A1: Generator turn on voltage
B1: Generator turn off voltage
A1 Setting range: [250, 900]
B1 Setting range: [250, 900]
Set rule:B1 - A1 ≥ 10V</source>
        <translation>A1:发电机开启电压
B1:发电机关闭电压
A1 设定范围： [250,900]
B1 设定范围： [250,900]
设定规则：B1 - A1 ≥ 10V</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10197"/>
        <source>Automatic operation</source>
        <translation>自动运行</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10211"/>
        <source>SystemInformation</source>
        <translation>系统信息</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10219"/>
        <source>Version</source>
        <translation>版本号</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10229"/>
        <location filename="../win.ui" line="10234"/>
        <location filename="../win.ui" line="10239"/>
        <location filename="../win.ui" line="10244"/>
        <location filename="../win.ui" line="10249"/>
        <source>新建行</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10254"/>
        <location filename="../win.ui" line="10259"/>
        <source>新建列</source>
        <translation></translation>
    </message>
    <message>
        <source>Manufacturer name</source>
        <translation type="vanished">厂家名称</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10264"/>
        <location filename="../win.cpp" line="4575"/>
        <source>Monitoring software version</source>
        <translation>     监控版本</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10279"/>
        <source>Protocol version</source>
        <translation>     协议版本号</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10284"/>
        <location filename="../win.cpp" line="4593"/>
        <source>Converter software version</source>
        <translation>     变流器软件版本</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10289"/>
        <location filename="../win.cpp" line="4602"/>
        <source>CPLD software version</source>
        <translation>     CPLD软件版本</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10294"/>
        <source>SN:</source>
        <translation>     SN：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10305"/>
        <source>Network</source>
        <translation>网络</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10345"/>
        <source>              interface:</source>
        <translation>接口号：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10386"/>
        <source>Port:</source>
        <translation>端口：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10455"/>
        <source>DHCP</source>
        <translation>自动获取</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10471"/>
        <source>STATIC</source>
        <translation>静态</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10491"/>
        <source>ip：</source>
        <translation>地址：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10521"/>
        <source>netmask:</source>
        <translation>子网掩码：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10554"/>
        <source>gateway:</source>
        <translation>网关：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10584"/>
        <source>Server ip:</source>
        <translation>服务器IP：</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10504"/>
        <source>192 . 168 . 1 . 100</source>
        <translation>192 . 168 . 1 . 100</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10537"/>
        <source>255 . 255 . 255 . 0</source>
        <translation>255 . 255 . 255 . 0</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10567"/>
        <source>192 . 168 .  1  . 1</source>
        <translation>192 . 168 .  1  . 1</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10597"/>
        <source> 192 . 168 . 1  . 200</source>
        <translation> 192 . 168 . 1  . 200</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10624"/>
        <location filename="../win.cpp" line="2268"/>
        <source>Apply and Restart system</source>
        <translation>应用并重启系统</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10367"/>
        <source>eth0</source>
        <translation>eth0</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10408"/>
        <source>502</source>
        <translation>502</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10712"/>
        <source>Menu</source>
        <translation>菜单</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10753"/>
        <source>M_01 Converter turn off</source>
        <translation>M_01 变流器关闭</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10788"/>
        <source>Current mode:CP</source>
        <translation>当前模式：CP</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1052"/>
        <source>Advance setting</source>
        <translation>高级设置</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <location filename="../win.cpp" line="3828"/>
        <source>Check</source>
        <translation>选择</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <source>StartTime</source>
        <translation>开始时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <source>EndTime</source>
        <translation>结束时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <location filename="../win.cpp" line="3831"/>
        <source>State</source>
        <translation>状态</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1144"/>
        <source>Power(kW)</source>
        <translation>功率(kW)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1169"/>
        <location filename="../win.cpp" line="2933"/>
        <source>Inv. active power</source>
        <translation>逆变有功功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1169"/>
        <location filename="../win.cpp" line="2942"/>
        <source>Inv. reactive power</source>
        <translation>逆变无功功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1169"/>
        <location filename="../win.cpp" line="2951"/>
        <source>Inv. apparent power</source>
        <translation>逆变视在功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1169"/>
        <location filename="../win.cpp" line="2961"/>
        <source>Inv. power factor</source>
        <translation>逆变功率因素</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1360"/>
        <source>System Information</source>
        <translation>系统信息</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1952"/>
        <source>The converter off switch. Click to turn off the converter.</source>
        <translation>关闭变流器的开关，点击后关闭变流器。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1956"/>
        <source>The converter standby switch. Click the converter to enter the standby state.</source>
        <translation>变流器待机开关，点击后变流器进入待机状态。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1960"/>
        <source>The converter on switch. Click to turn on the converter.</source>
        <translation>开启变流器的开关，点击后开启变流器。</translation>
    </message>
    <message>
        <source>Display today&apos;s power discharge amount.</source>
        <translation type="vanished">显示当日放电电量。</translation>
    </message>
    <message>
        <source>Display this month&apos;s power discharge amount.</source>
        <translation type="vanished">显示这个月放电电量。</translation>
    </message>
    <message>
        <source>Display this year&apos;s power discharge amount.</source>
        <translation type="vanished">显示今年放电电量。</translation>
    </message>
    <message>
        <source>Display total power discharge amount.</source>
        <translation type="vanished">显示总放电电量。</translation>
    </message>
    <message>
        <source>Display today&apos;s power charge amount</source>
        <translation type="vanished">显示当日充电电量。</translation>
    </message>
    <message>
        <source>Display this month&apos;s power charge amount.</source>
        <translation type="vanished">显示这个月充电电量。</translation>
    </message>
    <message>
        <source>Display this year&apos;s power charge amount.</source>
        <translation type="vanished">显示今年充电电量。</translation>
    </message>
    <message>
        <source>Display total power charge amount.</source>
        <translation type="vanished">显示总充电电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2188"/>
        <source>To view the data of the previous month.</source>
        <translation>查看上个月的数据。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2192"/>
        <source>To view the data of the previous year.</source>
        <translation>查看上一年的数据。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2204"/>
        <source>To view the data of the next month.</source>
        <translation>查看下个月的数据。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2208"/>
        <source>To view the data of the next year.</source>
        <translation>查看下一年的数据。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2220"/>
        <source>Export History Records, click here to export the history records to a U disk. The exported file will be named Record.csv, and it needs to be opened with Excel.</source>
        <translation>导出历史记录，点击此处将会导出历史记录到U盘里,导出到U盘的文件为Record.csv，此文件需要用Excel打开。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2224"/>
        <source>Export operation log. Click here to export operation log to U disk.</source>
        <translation>导出操作日志，点击此处将会导出操作日志到U盘里。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2232"/>
        <source>Eject U disk.</source>
        <translation>退出U盘。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2318"/>
        <source>0 represents an alarm event, and this item will turn red. 1 represents a status event.</source>
        <translation>0表示告警事件，且此项会变红，1表示状态事件。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2320"/>
        <source>Event start time.</source>
        <translation>事件开始时间。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2322"/>
        <source>Event end time: &apos;... &apos;indicates that there is no end time,&apos;-&apos; indicates that the event is in progress.</source>
        <translation>事件结束时间：表示这条记录的结束时间，&apos;...&apos;表示无结束时间,&apos;-&apos;表示事件正在进行。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2324"/>
        <source>event description</source>
        <translation>事件描述</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2325"/>
        <source>event description.</source>
        <translation>事件描述。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2642"/>
        <source>System settings operation records.</source>
        <translation>系统设置的操作记录。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2798"/>
        <source>Total voltage of the battery uploaded by BMS.</source>
        <translation>BMS上传的电池组总压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2802"/>
        <source>Total current of the battery uploaded by BMS.</source>
        <translation>BMS上传的电池组总电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2806"/>
        <source>Battery SOH uploaded from BMS, the percentage of available capacity after full charge compared to the rated capacity.</source>
        <translation>BMS上传的电池组SOC，即当前电池剩余电量百分比。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2810"/>
        <source>Battery SOC uploaded by BMS refers to the current remaining battery capacity percentage.</source>
        <translation>BMS上传的电池组SOH，电池组充满后可用容量与出厂容量的百分比。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2814"/>
        <source>The highest voltage of single cell uploaded by BMS.</source>
        <translation>BMS上传的单体最高电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2818"/>
        <source>The lowest voltage of single cell uploaded by BMS.</source>
        <translation>BMS上传的单体最低电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2822"/>
        <source>The highest temperature of single cell uploaded by BMS.</source>
        <translation>BMS上传的单体最高温度。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2826"/>
        <source>The lowest temperature of single cell uploaded by BMS.</source>
        <translation>BMS上传的单体最低温度。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2830"/>
        <source>The limit of charging current uploaded by BMS.</source>
        <translation>BMS上传的充电电流限制。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2834"/>
        <source>The limit of discharging current uploaded by BMS.</source>
        <translation>BMS上传的放电电流限制。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2838"/>
        <source>The allowable charging power uploaded by BMS.</source>
        <translation>BMS上传的允许充电功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2842"/>
        <source>The allowable discharging power uploaded by BMS.</source>
        <translation>BMS上传的允许放电功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2846"/>
        <source>The allowable charging capacity uploaded by BMS.</source>
        <translation>BMS上传的允许充电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2850"/>
        <source>The allowable discharging capacity uploaded by BMS.</source>
        <translation>BMS上传的允许放电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3259"/>
        <source>The output circuit breaker has two states: On, Off. It can only be manually opened and closed.</source>
        <translation>输出断路器有两种状态:闭合、断开;只能手动断开。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3277"/>
        <source>The power grid circuit breaker has two states: On, Off; The power grid circuit breaker can only be manually disconnected.</source>
        <translation>电网断路器有两种状态:闭合、断开;只能手动断开。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3295"/>
        <source>The converter has two states: Enable,Disabled. The converter is enabled when the self-check is successful. Otherwise, the converter is disabled.</source>
        <translation>变流器有两种状态:使能、禁止;机器自检正常时，变流器使能;否则变流器禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3331"/>
        <source>LVRT states : Enable , Disable.</source>
        <translation>低电压穿越状态:使能、禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3439"/>
        <source>AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. When the advanced setting for power control mode is set to Constant Power mode (CP_AC), a positive value indicates discharging, and a negative value indicates charging.
For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.</source>
        <translation>交流侧功率：可通过修改该项的值来控制交流侧对电池的充放功率;当高级设置控制功率方式选择恒功率模式(CP_AC)时，正值表示放电，负值表示充电。
比如设置-5，表示交流侧将以-5kW的功率给电池充电，由于逆变器的损耗，此时直流侧的功率将小于交流侧的功率;比如设置5，表示交流侧将以5kW的功率输出，由于逆变器的损耗，此时直流侧的功率将大于交流侧的功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3501"/>
        <source>Local: Converter control through HMI, In this mode, the EMS can only read and cannot write.
Remote: In remote mode, the EMS can perform both read and write control.</source>
        <translation>本地:通过HMI控制变流器，EMS在该模式下只能读不能写;
远程:EMS可以进行读写控制。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3662"/>
        <source>Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC.</source>
        <translation>充电停止SOC：电网扩容模式下，电池处于充电状态时，电池SOC大于此SOC会停止充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4676"/>
        <source>Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:MEGA, LISHEN, PENGHUI, GAOTE, XIENENG, LANLI, SHENLAN, PAINENG, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD, GROUP_STANDARD, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, FARO.                                             
Select AUTO to automatically detect the battery manufacturer protocol.</source>
        <translation>电池协议:根据选择的电池协议解析BMS发送的报文。目前支持选择的电池厂家协议为:迈格, 力神, 鹏辉, 高特, 协能, 蓝锂, 深澜, 派能, 宁德时代, 索英, 欣旺达, 库博, 高特V2, 拓高, 团标, 沃博源, 科工, 里德, 派能L, 未蓝, 沃太能源, 拓普, 捷辉, 金锂动, 法罗.
选择AUTO时将自动判断电池厂家协议。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4873"/>
        <source>Upper limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as 0.2, 0.5, 1, 5.</source>
        <translation>电网频率变化范围上限：交流侧所允许的频率变化最大范围，可供选择为0.2、0.5、1、5。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5724"/>
        <source>Display the current status of the DCAC converter.</source>
        <translation>显示当前DCAC变流器状态。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5732"/>
        <source>Current Mode</source>
        <translation>当前模式</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5732"/>
        <source>Display the current control power mode.</source>
        <translation>显示当前控制功率模式。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5817"/>
        <source>Make sure to press the EPO button before upgrading.</source>
        <translation>升级前确保已按下EPO。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5817"/>
        <source>NEXT</source>
        <translation>下一步</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5817"/>
        <source>Cancel</source>
        <translation>取消</translation>
    </message>
    <message>
        <source>Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:MEGA, LISHEN, PENGHUI, GAOTE, XIENENG, LANLI, SHENLAN, PAINENG, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD, GROUP_STANDARD, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, ECUBE, FARO.                                             
Select AUTO to automatically detect the battery manufacturer protocol.</source>
        <translation type="vanished">电池协议:根据选择的电池协议解析BMS发送的报文。目前支持选择的电池厂家协议为:迈格, 力神, 鹏辉, 高特, 协能, 蓝锂, 深澜, 派能, 宁德时代, 索英, 欣旺达, 库博, 高特V2, 拓高, 团标, 沃博源, 科工, 里德, 派能L, 未蓝, 沃太能源, 拓普, 捷辉, 金锂动, ECUBE, 法罗.
选择AUTO时将自动判断电池厂家协议。</translation>
    </message>
    <message>
        <source>Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:MEGA, LISHEN, PENGHUI, GAOTE, XIENENG, LANLI, SHENLAN, PAINENG_L, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD, GROUP_STANDARD, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, ECUBE, FARO, BGS, JDITEC, HUASU, LIGAO.                                             
Select AUTO to automatically detect the battery manufacturer protocol.</source>
        <translation type="obsolete">电池协议:根据选择的电池协议解析BMS发送的报文。目前支持选择的电池厂家协议为:迈格, 力神, 鹏辉, 高特, 协能, 蓝锂, 深澜, 派能, 宁德时代, 索英, 欣旺达, 库博, 高特V2, 拓高, 团标, 沃博源, 科工, 里德, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, ECUBE, FARO, BGS, JDITEC, HUASU, LIGAO.
选择AUTO时将自动判断电池厂家协议。</translation>
    </message>
    <message>
        <source>Alarm levels uploaded from BMS, level one alarm is yellow, level two alarm is orange, and level three alarm is red; By default, the converter does not respond to level one and level two alarms, but shuts down in response to level three alarms.</source>
        <translation type="obsolete">BMS上传的告警等级，一级告警为黄色、二级告警为橙色、三级告警为红色；
默认一级告警、二级告警变流器不做响应，三级告警变流器关机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2857"/>
        <source>Charging enable</source>
        <translation>充电使能</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2858"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to charge, Disable indicates the battery is not allowed to charge.</source>
        <translation>BMS上传的电池状态：使能表示电池允许充电，禁止表示电池不允许充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2861"/>
        <source>Discharging enable</source>
        <translation>放电使能</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2862"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to discharge, Disable indicates the battery is not allowed to discharge.</source>
        <translation>BMS上传的电池状态：使能表示电池允许放电，禁止表示电池不允许放电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2880"/>
        <source>Inv. side AB line voltage.</source>
        <translation>逆变侧AB线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2889"/>
        <source>Inv. side BC line voltage.</source>
        <translation>逆变侧BC线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2898"/>
        <source>Inv. side CA line voltage.</source>
        <translation>逆变侧CA线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2907"/>
        <source>Inv. side A phase current.</source>
        <translation>逆变侧A相电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2916"/>
        <source>Inv. side B phase current.</source>
        <translation>逆变侧B相电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2925"/>
        <source>Inv. side C phase current.</source>
        <translation>逆变侧C相电流。</translation>
    </message>
    <message>
        <source>Active Power</source>
        <translation type="vanished">有功功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2934"/>
        <source>Active power P on the inv. side of the converter.</source>
        <translation>变流器逆变侧有功功率P。</translation>
    </message>
    <message>
        <source>Reactive Power</source>
        <translation type="vanished">无功功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2943"/>
        <source>Reactive power Q on the inv. side of the converter.</source>
        <translation>变流器逆变侧无功功率Q。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2952"/>
        <source>Apparent power S on the inv. side of the converter.</source>
        <translation>变流器逆变侧视在功率S。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2962"/>
        <source>Power factor PF on the inv. side of the converter.</source>
        <translation>变流器逆变侧功率因数PF。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2971"/>
        <source>Converter battery side voltage.</source>
        <translation>变流器电池侧电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2980"/>
        <source>Converter battery side current.</source>
        <translation>变流器电池侧电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2989"/>
        <source>Converter battery side power.</source>
        <translation>变流器电池侧功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2998"/>
        <source>Converter bus voltage.</source>
        <translation>变流器母线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3007"/>
        <source>The IGBT temperature of the converter: The IGBT temperature must not exceed 102°C. Otherwise, the converter will operate at a reduced capacity. It will resume full power operation when the temperature drops to 73°C.</source>
        <translation>变流器的IGBT温度：IGBT温度不得超过102℃，否则变流器将降额运行，降额后73℃恢复可满功率运行。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3016"/>
        <source>”The ambient temperature.</source>
        <translation>环境温度。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3031"/>
        <source>Grid side AB line voltage.</source>
        <translation>电网侧AB线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3040"/>
        <source>Grid side BC line voltage.</source>
        <translation>电网侧BC线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3049"/>
        <source>Grid side CA line voltage.</source>
        <translation>电网侧CA线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3058"/>
        <source>Grid side A phase current.</source>
        <translation>电网侧A相电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3067"/>
        <source>Grid side B phase current.</source>
        <translation>电网侧B相电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3076"/>
        <source>Grid side C phase current.</source>
        <translation>电网侧C相电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3085"/>
        <source>Active power P on the grid side of the converter.</source>
        <translation>变流器电网侧有功功率P。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3094"/>
        <source>Reactive power Q on the grid side of the converter.</source>
        <translation>变流器电网侧无功功率Q。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3103"/>
        <source>Apparent power S on the grid side of the converter.</source>
        <translation>变流器电网侧视在功率S。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3112"/>
        <source>Frequency on the grid side of the converter.</source>
        <translation>变流器电网频率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3121"/>
        <source>Power factor PF on the grid side of the converter.</source>
        <translation>变流器电网侧功率因素PF。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3136"/>
        <source>Load side AB line voltage.</source>
        <translation>负载侧AB线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3145"/>
        <source>Load side BC line voltage.</source>
        <translation>负载侧BC线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3154"/>
        <source>Load side CA line voltage.</source>
        <translation>负载侧CA线电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3163"/>
        <source>Load side A phase current.</source>
        <translation>负载侧A相电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3172"/>
        <source>Load side B phase current.</source>
        <translation>负载侧B相电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3181"/>
        <source>Load side C phase current.</source>
        <translation>负载侧C相电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3190"/>
        <source>Active power P on the load side of the converter.</source>
        <translation>变流器负载侧有功功率P。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3199"/>
        <source>Reactive power Q on the load side of the converter.</source>
        <translation>变流器负载侧无功功率Q。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3208"/>
        <source>Apparent power S on the load side of the converter.</source>
        <translation>变流器负载侧视在功率S。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3217"/>
        <source>Power factor PF on the load side of the converter.</source>
        <translation>变流器负载侧功率因素PF。</translation>
    </message>
    <message>
        <source>The output circuit breaker has three states: open, closed, and tripped. It can only be manually opened and closed. If there is an overcurrent in the output circuit breaker, it will trip.</source>
        <translation type="vanished">输出断路器有三种状态： 断开、闭合、脱扣；只能手动断开和闭合，如果输出断路器过流，输出断路器会发生脱扣。</translation>
    </message>
    <message>
        <source>The grid contactor has two states: open and closed. When the inverter is in grid-connected mode and the grid voltage is normal, the grid contactor is closed. When the inverter is in island mode, the grid contactor is open. In the islanded state, the grid contactor remains open.</source>
        <translation type="vanished">电网接触器有两种状态： 断开、闭合；当变流器处于并网模式下，且电网侧电压正常时，电网接触器闭合；变流器处于离网模式下，电网接触器断开；离网状态下，电网接触器断开。</translation>
    </message>
    <message>
        <source>This is the control mode: the dispatching machine can only monitor data through Ethernet cable, RS485 tool, and CAN tool, but cannot control the PCS.
The remote mode: the dispatching machine can only read and write data through Ethernet cable, RS485 tool, and CAN tool.</source>
        <translation type="vanished">这是控制模式：调度机只能通过网线、RS485工具、CAN工具来监听数据，不能控制PCS；
远程模式：调度机只能通过网线、RS485工具、CAN工具进行读写</translation>
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
        <translation>充电</translation>
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
        <translation>放电</translation>
    </message>
    <message>
        <source>Information</source>
        <translation type="vanished">信息</translation>
    </message>
    <message>
        <source>Inverter overcurrent</source>
        <translation type="vanished">逆变器过流</translation>
    </message>
    <message>
        <source>General failure</source>
        <translation type="vanished">一般故障</translation>
    </message>
    <message>
        <source>Inductive current instantaneous value &gt;3lp or inductive current RMS value &gt;1.36ln</source>
        <translation type="vanished">电感电流瞬时值&gt;3Ip\n或电感电流有效值&gt;1.36In</translation>
    </message>
    <message>
        <source>PCS shut down and disconnect the output contactor</source>
        <translation type="vanished">PCS 停机，输出接触器断开</translation>
    </message>
    <message>
        <source>Recoverable, automatic recovery 5 minutes after the fault is eliminated</source>
        <translation type="vanished">可恢复，故障消除5min后自动恢复</translation>
    </message>
    <message>
        <source>DC bus overvoltage</source>
        <translation type="vanished">直流母线过压</translation>
    </message>
    <message>
        <source>DC input voltage more then 850V</source>
        <translation type="vanished">直流输入电压&gt;850V</translation>
    </message>
    <message>
        <source>DC bus short circuit</source>
        <translation type="vanished">直流母线短路</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2244"/>
        <source>Interface</source>
        <translation>接口号</translation>
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
        <translation>确定</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1167"/>
        <location filename="../win.cpp" line="2879"/>
        <source>Inv. voltage(AB)</source>
        <translation>逆变电压（AB）</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1167"/>
        <location filename="../win.cpp" line="2888"/>
        <source>Inv. voltage(BC)</source>
        <translation>逆变电压（BC）</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1167"/>
        <location filename="../win.cpp" line="2897"/>
        <source>Inv. voltage(CA)</source>
        <translation>逆变电压（CA）</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1168"/>
        <location filename="../win.cpp" line="2906"/>
        <source>Inv. current(A)</source>
        <translation>逆变电流（A）</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1168"/>
        <location filename="../win.cpp" line="2915"/>
        <source>Inv. current(B)</source>
        <translation>逆变电流（B）</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1168"/>
        <location filename="../win.cpp" line="2924"/>
        <source>Inv. current(C)</source>
        <translation>逆变电流（C）</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1879"/>
        <location filename="../win.cpp" line="3339"/>
        <source>Start Diesel Generator Signal</source>
        <translation>启动柴发信号</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1880"/>
        <location filename="../win.cpp" line="3366"/>
        <source>Dry contact EPO</source>
        <translation>干接点EPO</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1881"/>
        <location filename="../win.cpp" line="3375"/>
        <source>Dry contact Shutdown</source>
        <translation>干接点关机</translation>
    </message>
    <message>
        <source>This is the converter off switch. Click to turn on and off the converter.</source>
        <translation type="vanished">这是变流器关闭开关，点击后开关闭变流器。</translation>
    </message>
    <message>
        <source>This is the converter standby switch. Click the converter to enter the standby state.</source>
        <translation type="vanished">这是变流器待机开关，点击后变流器进入待机状态。</translation>
    </message>
    <message>
        <source>This is the converter on switch, click to turn on the converter.</source>
        <translation type="vanished">这是变流器打开开关,点击后开启变流器。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2096"/>
        <source>Alarm icon</source>
        <translation>告警图标</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2096"/>
        <source>Alarm icon: It is not displayed when there is no alarm. When there is a minor alarm, a yellow icon is displayed. When there is a fault alarm, a red icon is displayed.</source>
        <translation>告警图标：无告警时不显示，轻微告警时显示黄色图表，故障告警时显示红色图标。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2155"/>
        <source>Discharge Day</source>
        <translation>日放电量</translation>
    </message>
    <message>
        <source>The discharge quantity of the day is shown here; Click here to jump to a histogram of daily charge and discharge, with the horizontal axis in days and the vertical axis in power (kWh)The discharge quantity of the day is shown here; Click here to jump to a histogram of daily charge and discharge, with the horizontal axis in days and the vertical axis in power (kWh).</source>
        <translation type="vanished">这里显示当日放电电量；点击此处将跳转到每日充放电量的直方图，横轴单位为日，纵轴单位为功率(kWh)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2159"/>
        <source>Discharge Month</source>
        <translation>月放电量</translation>
    </message>
    <message>
        <source>This shows the discharge amount of this month. Click here to jump to the histogram of monthly charge and discharge amount. The horizontal axis is in month and the vertical axis is in power (kWh).</source>
        <translation type="vanished">这里显示当月放电电量,点击此处将跳转到每月充放电量的直方图，横轴单位为月，纵轴单位为功率(kWh)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2163"/>
        <source>Discharge Year</source>
        <translation>年放电量</translation>
    </message>
    <message>
        <source>This shows the discharge amount of this year. Click here to jump to the histogram of the annual charge and discharge amount. The horizontal axis is in year, and the vertical axis is in power (kWh).</source>
        <translation type="vanished">这里显示当年放电电量,点击此处将跳转到每年充放电量的直方图，横轴单位为年，纵轴单位为功率(kWh)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2167"/>
        <source>Discharge Total</source>
        <translation>总放电量</translation>
    </message>
    <message>
        <source>The total discharge power is displayed here. Click here to jump to the overview chart.</source>
        <translation type="vanished">这里显示总放电电量，点击此处将跳转到总览图。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2171"/>
        <source>Charge Day</source>
        <translation>日充电量</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2175"/>
        <source>Charge Month</source>
        <translation>月充电量</translation>
    </message>
    <message>
        <source>This shows the amount of charging in this month. Click here to jump to the histogram of monthly charging and discharging. The horizontal axis is in month and the vertical axis is in power (kWh).</source>
        <translation type="vanished">这里显示当月充电电量,点击此处将跳转到每月充放电量的直方图，横轴单位为月，纵轴单位为功率(kWh)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2179"/>
        <source>Charge Year</source>
        <translation>年充电量</translation>
    </message>
    <message>
        <source>This shows the amount of charging for this year. Click here to jump to the histogram of charging and discharging for each year. The horizontal axis is in years and the vertical axis is in power (kWh).</source>
        <translation type="vanished">这里显示当年充电电量,点击此处将跳转到每年充放电量的直方图，横轴单位为年，纵轴单位为功率(kWh)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2183"/>
        <source>Charge Total</source>
        <translation>总充电量</translation>
    </message>
    <message>
        <source>This shows the total amount of charging, click here to jump to the overview chart.</source>
        <translation type="vanished">这里显示总充电电量，点击此处将跳转到总览图。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2187"/>
        <source>Month-</source>
        <translation>月-</translation>
    </message>
    <message>
        <source>To view the data of the previous month, click on it to display the data of the previous month of the current displayed month.</source>
        <translation type="vanished">查看上个月的数据，点击后将显示当前显示月份的上个月的数据。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2191"/>
        <source>Year-</source>
        <translation>年-</translation>
    </message>
    <message>
        <source>To view the previous year&apos;s data, click on it to display the previous year&apos;s data for the current displayed year.</source>
        <translation type="vanished">查看上一年的数据，点击后将显示当前显示年份的上一年的数据。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2195"/>
        <source>Daily electricity quantity</source>
        <translation>日电量</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2196"/>
        <source>To view the daily charge and discharge volume, click here to jump to the histogram of daily charge and discharge volume. The horizontal axis is in day, and the vertical axis is in power (kWh).</source>
        <translation>查看当日充放电量，点击此处将跳转到每日充放电量的直方图，横轴单位为日，纵轴单位为功率(kWh)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2199"/>
        <source>Annual electricity quantity</source>
        <translation>年电量</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2200"/>
        <source>To view the annual charge and discharge volume, click here to jump to the histogram of the annual charge and discharge volume, the horizontal axis is in year, and the vertical axis is in power (kWh).</source>
        <translation>查看当年充放电量,点击此处将跳转到每年充放电量的直方图，横轴单位为年，纵轴单位为功率(kWh)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2203"/>
        <source>Month+</source>
        <translation>月+</translation>
    </message>
    <message>
        <source>To view the data for the next month, click to display the data for the next month of the current displayed month.</source>
        <translation type="vanished">查看下个月的数据，点击后将显示当前显示月份的下个月的数据。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2207"/>
        <source>Year+</source>
        <translation>年+</translation>
    </message>
    <message>
        <source>To view the data for the next year, click on it to display the data for the next year of the current displayed year.</source>
        <translation type="vanished">查看下一年的数据，点击后将显示当前显示年份的下一年的数据。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2211"/>
        <source>Monthly electric quantity</source>
        <translation>月电量</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2212"/>
        <source>To view the monthly charge and discharge volume, click here to jump to the histogram of monthly charge and discharge volume. The horizontal axis is in month, and the vertical axis is in power (kWh).</source>
        <translation>查看当月充放电量,点击此处将跳转到每月充放电量的直方图，横轴单位为月，纵轴单位为功率(kWh)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2215"/>
        <source>Total electric quantity</source>
        <translation>总电量</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2216"/>
        <source>To view the total charge and discharge, click here to jump to the overview chart.</source>
        <translation>查看总充放电量，点击此处将跳转到总览图。</translation>
    </message>
    <message>
        <source>Click here to export operation logs to the USB flash drive. The Log file is Log.csv, and you need to open the file using Excel.</source>
        <translation type="vanished">导出操作日志，点击此处将会导出操作日志到U盘，导出到U盘的文件为Log.csv，此文件需要用Excel打开。</translation>
    </message>
    <message>
        <source>To export the battery table, click here to export the battery table to the USB flash drive. The file exported to the USB flash drive is Report.csv, which needs to be opened with Excel.</source>
        <translation type="vanished">导出电量统计表，点击此处将会导出电量统计表到U盘，导出到U盘的文件为Report.csv，此文件需要用Excel打开。</translation>
    </message>
    <message>
        <source>Exit the U disk and unmount the U disk mounted to the display control to ensure that the data in the U disk will not be damaged.</source>
        <translation type="vanished">退出U盘，将挂载到显控的U盘取消挂载，以保证U盘数据不会损坏。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2248"/>
        <source>Port</source>
        <translation>端口</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2252"/>
        <source>Ip</source>
        <translation>IP地址</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2256"/>
        <source>Netmask</source>
        <translation>子网掩码</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2260"/>
        <source>Gateway</source>
        <translation>网关</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2264"/>
        <source>Serber ip</source>
        <translation>服务器IP</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2269"/>
        <source>This is the application and restart the system. After clicking, the system will be restarted. If there is an upgrade of the monitoring screen program, the new monitoring screen program will be used after the restart.</source>
        <translation>这是应用并重启系统，点击后将重启系统，如有升级监控屏程序，重启后将会使用新的监控屏程序。</translation>
    </message>
    <message>
        <source>This is battery power-on, which can give the BMS instructions to close the contactor (Note: only some BMS manufacturers support this function).</source>
        <translation type="vanished">这是电池上电，该项可以给BMS下发闭合接触器的指令(注：仅部分BMS厂家支持该功能)。</translation>
    </message>
    <message>
        <source>This is the battery power off, this item can give the BMS to disconnect the contactor command (note: only some BMS manufacturers support this function).</source>
        <translation type="vanished">这是电池下电，该项可以给BMS下发断开接触器的指令(注：仅部分BMS厂家支持该功能)。</translation>
    </message>
    <message>
        <source>This is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.</source>
        <translation type="vanished">这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息。</translation>
    </message>
    <message>
        <source>This is the event start time, which means that the record started appearing at this time.</source>
        <translation type="vanished">这是事件开始时间，表示这条记录从这个时间开始出现。</translation>
    </message>
    <message>
        <source>This is the event end time, which means the end time of this record,&apos;... &apos;means no end time.</source>
        <translation type="vanished">这是事件结束时间，表示这条记录的结束时间,&apos;...&apos;表示无结束时间。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2323"/>
        <source>CAN communication failure</source>
        <translation>CAN通信故障</translation>
    </message>
    <message>
        <source>This is the event description, when there is an alarm information, the alarm information will be recorded here.</source>
        <translation type="vanished">这是事件描述，当有告警信息时，会将告警信息记录在这里。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2326"/>
        <source>Fire alarm (High temp. alarm)</source>
        <translation>消防告警 (高温告警)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2328"/>
        <source>Converter Standby.</source>
        <translation>变换器待机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2329"/>
        <source>The grid contactor connected</source>
        <translation>电网接触器闭合</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2330"/>
        <source>The grid breaker connected</source>
        <translation>电网断路器闭合</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2331"/>
        <source>The output breaker connected</source>
        <translation>输出断路器闭合</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2332"/>
        <source>Buck not softened</source>
        <translation>低压侧未软起</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2333"/>
        <source>Contactor off buck</source>
        <translation>低压侧接触器断开</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2335"/>
        <source>The grid breaker disconnected</source>
        <translation>电网断路器断开</translation>
    </message>
    <message>
        <source>Here is a record of the operation when a change is made to the system Settings.</source>
        <translation type="vanished">这里是对系统设置进行修改时的操作记录。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2723"/>
        <source>Power control type：CP_P-&gt;CP_N&amp;&amp;P</source>
        <translation>功率控制类型：CP_P-&gt;CP_N&amp;&amp;P</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2726"/>
        <source>Power control type：CP_N&amp;&amp;P-&gt;CP_P</source>
        <translation>功率控制类型：CP_N&amp;&amp;P-&gt;CP_P</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2729"/>
        <source>Grid Fre Upper limit：0.2-&gt;3</source>
        <translation>电网频率变化范围上限：0.2-&gt;3</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2732"/>
        <source>Grid Fre Upper limit：3-&gt;0.2</source>
        <translation>电网频率变化范围上限：3-&gt;0.2</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2735"/>
        <source>Voltage protection Lower limit：-10-&gt;-15</source>
        <translation>电压保护范围下限：-10-&gt;-15</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2738"/>
        <source>Voltage protection Lower limit：-15-&gt;-10</source>
        <translation>电压保护范围下限：-15-&gt;-10</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2741"/>
        <source>Operation mode：Prevent countercurrnet-&gt;Peak valley</source>
        <translation>操作模式：系统防逆流-&gt;削峰填谷</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2750"/>
        <source>Operation mode：UPS-&gt;Prevent countercurrnet</source>
        <translation>操作模式：UPS(备电模式)-&gt;系统防逆流</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2747"/>
        <source>Operation mode：Manual-&gt;UPS</source>
        <translation>操作模式：手动-&gt;UPS(备电模式)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1951"/>
        <source>Turn off</source>
        <translation>关闭</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1955"/>
        <source>Stand-by</source>
        <translation>待机</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1959"/>
        <source>Turn on</source>
        <translation>开启</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2156"/>
        <source>Display today&apos;s AC-side power discharge amount.</source>
        <translation>显示当日交流侧放电电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2160"/>
        <source>Display this month&apos;s AC-side power discharge amount.</source>
        <translation>显示这个月交流侧放电电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2164"/>
        <source>Display this year&apos;s AC-side power discharge amount.</source>
        <translation>显示今年交流侧放电电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2168"/>
        <source>Display total AC-side power discharge amount.</source>
        <translation>显示交流侧总放电电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2172"/>
        <source>Display today&apos;s AC-side power charge amount</source>
        <translation>显示当日交流侧充电电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2176"/>
        <source>Display this month&apos;s AC-side power charge amount.</source>
        <translation>显示这个月交流侧充电电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2180"/>
        <source>Display this year&apos;s AC-side power charge amount.</source>
        <translation>显示今年交流侧放电电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2184"/>
        <source>Display total AC-side power charge amount.</source>
        <translation>显示交流侧总充电电量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2283"/>
        <source>DO turn on</source>
        <translation>DO 闭合</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2284"/>
        <source>This is the DO control closure, provided for internal debugging use only.</source>
        <translation>这是DO控制闭合，仅提供内部调试使用。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2287"/>
        <source>Do turn off</source>
        <translation>DO 断开</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2288"/>
        <source>This is the DO control off, provided for internal debugging use only.</source>
        <translation>这是DO控制断开，仅提供内部调试使用。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2291"/>
        <source>Local on</source>
        <translation>本地启动</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2292"/>
        <source>This is to start a local soft boot, only for internal debugging use.</source>
        <translation>这是启动本地软启动，仅提供内部调试使用。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2295"/>
        <source>Local off</source>
        <translation>本地关闭</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2296"/>
        <source>This is to turn off the local soft boot for internal debugging use only.</source>
        <translation>这是关闭本地软启动，仅提供内部调试使用。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2744"/>
        <source>Operation mode：Peak valley-&gt;Manual</source>
        <translation>操作模式：削峰填谷-&gt;手动</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2753"/>
        <source>Inv ON/Off-Grid：Off-&gt;automatic</source>
        <translation>并离网：关闭-&gt;自动</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2756"/>
        <source>Inv ON/Off-Grid：automatic-&gt;Off</source>
        <translation>并离网：自动-&gt;关闭</translation>
    </message>
    <message>
        <source>Alarm name</source>
        <translation type="vanished">告警名称</translation>
    </message>
    <message>
        <source>Alarm leve</source>
        <translation type="vanished">告警等级</translation>
    </message>
    <message>
        <source>Trigger condition</source>
        <translation type="vanished">触发条件</translation>
    </message>
    <message>
        <source>Response action</source>
        <translation type="vanished">响应动作</translation>
    </message>
    <message>
        <source>Whether to reset
automatically and reset time</source>
        <translation type="vanished">是否自动复位及复位时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2797"/>
        <source>Bat volage</source>
        <translation>电池电压</translation>
    </message>
    <message>
        <source>This is the total battery pressure of the battery pack uploaded from the BMS via the CAN/485/TCP communication protocol.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的电池组的电池总压。</translation>
    </message>
    <message>
        <source>This is the total current of the battery pack uploaded from the BMS via the CAN/485/TCP communication protocol.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的电池组的总电流。</translation>
    </message>
    <message>
        <source>This is the SOC of the battery pack uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the percentage of the current battery remaining.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的电池组SOC，即当前电池剩余电量百分比。</translation>
    </message>
    <message>
        <source>This is the SOH of the battery pack uploaded from the BMS through the CAN/485/TCP communication protocol, the percentage of the current capacity of the battery pack to the factory capacity, that is, the health of the battery.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的电池组SOH，电池组当前的容量与出厂容量的百分比，即电池的健康度。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2813"/>
        <source>Cell voltage(max)</source>
        <translation>单体最高电压</translation>
    </message>
    <message>
        <source>This is the maximum voltage of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the maximum voltage of all cell cells at present.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的单体最高电压,即当前所有电池单体的最高电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2817"/>
        <source>Cell voltage(min)</source>
        <translation>单体最低电压</translation>
    </message>
    <message>
        <source>This is the lowest voltage of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the lowest voltage of all battery cells at present.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的单体最低电压,即当前所有电池单体的最低电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2821"/>
        <source>Cell temp.(max)</source>
        <translation>单体最高温度</translation>
    </message>
    <message>
        <source>This is the highest temperature of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the highest temperature of all battery cells at present.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的单体最高温度,即当前所有电池单体的最高温度。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2825"/>
        <source>Cell temp.(min)</source>
        <translation>单体最低温度</translation>
    </message>
    <message>
        <source>This is the lowest temperature of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the lowest temperature of all battery cells at present.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的单体最低温度,即当前所有电池单体的最低温度。</translation>
    </message>
    <message>
        <source>This is the upper limit of the charging current uploaded from the BMS via the CAN/485/TCP communication protocol, the maximum charging current allowed by the current battery pack (Note: when charging the end, PCS will limit the current according to the actual current).</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的充电电流上限，当前电池组所允许通过的最大充电电流(注: 充电末端时，PCS会根据实际电流来进行限流)。</translation>
    </message>
    <message>
        <source>This is the upper limit of the discharge current uploaded from the BMS via the CAN/485/TCP communication protocol, the maximum discharge current allowed by the current battery pack.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的放电电流上限，当前电池组所允许通过的最大放电电流。</translation>
    </message>
    <message>
        <source>This is the rechargeable power uploaded from the BMS through the CAN/485 communication protocol. The charging power of the battery cannot exceed this limit value.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的可充电功率，电池的充电功率不可超过这个限制数值。</translation>
    </message>
    <message>
        <source>This is the discharge power uploaded from the BMS using the CAN/485 communication protocol. The discharge power of the battery cannot exceed this limit.</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的可放电功率，电池的放电功率不可超过这个限制数值。</translation>
    </message>
    <message>
        <source>This is the allowable charge amount uploaded from the BMS via the CAN/485/TCP communication protocol, the capacity of the current battery pack allowed to charge (Note: only some BMS will provide this value).</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的允许充电量，当前电池组允许充电的容量(注: 仅部分BMS会提供这个值)。</translation>
    </message>
    <message>
        <source>This is the allowable discharge from the BMS via the CAN/485/TCP communication protocol, the current capacity of the battery pack allowed to discharge (Note: only some BMS will provide this value).</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的允许放电量，当前电池组允许放电的容量(注: 仅部分BMS会提供这个值)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2853"/>
        <source>Alarm level</source>
        <translation>告警等级</translation>
    </message>
    <message>
        <source>This is the alarm level icon. The color is changed according to the alarm level uploaded by the BMS. The alarm level is green for normal alarms, yellow for primary alarms, orange for secondary alarms, and red for tertiary alarms.If the alarm is Level 1 or Level 2, PCS does not respond.If the alarm is Level 3, the PCS shuts down.</source>
        <translation type="vanished">这是告警等级图示，根据BMS上传的告警等级改变颜色，此处可以通过颜色判断告警等级，正常为绿色、一级告警为黄色、二级告警为橙色、三级告警为红色；如果是一级告警或者二级告警，PCS不做响应；如果是三级告警，PCS关机。</translation>
    </message>
    <message>
        <source>Charge enable</source>
        <translation type="vanished">充电使能</translation>
    </message>
    <message>
        <source>This is the current battery status uploaded by BMS via CAN/485/TCP. Enable indicates that the battery can be charged. Disable indicates that the battery cannot be charged.</source>
        <translation type="vanished">这是充电使能，由BMS通过CAN/485/TCP通讯协议上传的当前电池的状态；使能表示目前电池允许充电，禁止表示目前电池不允许充电。</translation>
    </message>
    <message>
        <source>Discharge enable</source>
        <translation type="vanished">放电使能</translation>
    </message>
    <message>
        <source>This is the current state of the battery uploaded by the BMS via the CAN/485/TCP protocol. Enable indicates that the battery can be discharged. Disable indicates that the battery cannot be discharged.</source>
        <translation type="vanished">这是放电使能，由BMS通过CAN/485/TCP通讯协议上传的当前电池的状态；使能表示目前电池允许放电，禁止表示目前电池不允许放电。</translation>
    </message>
    <message>
        <source>The grid side voltage of the current PCS, this item is the phase voltage between phase A and phase B.</source>
        <translation type="vanished">当前PCS的电网侧电压，此项为A相和B相之间的相电压。</translation>
    </message>
    <message>
        <source>The grid side voltage of the current PCS, this item is the phase voltage between phase B and phase C.</source>
        <translation type="vanished">当前PCS的电网侧电压，此项为B相和C相之间的相电压。</translation>
    </message>
    <message>
        <source>The grid side voltage of the current PCS, this item is the phase voltage between phase A and phase C.</source>
        <translation type="vanished">当前PCS的电网侧电压，此项为A相和C相之间的相电压。</translation>
    </message>
    <message>
        <source>The current on the grid side of PCS, this item is the current of phase A.</source>
        <translation type="vanished">当前PCS的电网侧电流，此项为A相的电流。</translation>
    </message>
    <message>
        <source>The current on the grid side of PCS, this item is the current of phase B.</source>
        <translation type="vanished">当前PCS的电网侧电流，此项为B相的电流。</translation>
    </message>
    <message>
        <source>The current on the grid side of PCS, this item is the current of phase C.</source>
        <translation type="vanished">当前PCS的电网侧电流，此项为C相的电流。</translation>
    </message>
    <message>
        <source>Current active power (P) on the grid side of PCS.</source>
        <translation type="vanished">当前PCS的电网侧有功功率(P)。</translation>
    </message>
    <message>
        <source>Current reactive power (Q) on the grid side of PCS.</source>
        <translation type="vanished">当前PCS的电网侧无功功率(Q)。</translation>
    </message>
    <message>
        <source>Current PCS grid side view power (S), S= √((P^2+Q^2)).</source>
        <translation type="vanished">当前PCS的电网侧视在功率(S)，S= √((P^2+Q^2))。</translation>
    </message>
    <message>
        <source>Current PCS collection of power grid frequency.</source>
        <translation type="vanished">当前PCS的采集的电网频率。</translation>
    </message>
    <message>
        <source>Grid side power factor (Pf) of the current PCS, Pf = P/S.</source>
        <translation type="vanished">当前PCS的电网侧功率因素(Pf)， Pf = P/S。</translation>
    </message>
    <message>
        <source>The load side voltage of the current PCS, this item is the phase voltage between phase A and phase B.</source>
        <translation type="vanished">当前PCS的负载侧电压，此项为A相和B相之间的相电压。</translation>
    </message>
    <message>
        <source>The load side voltage of the current PCS, this item is the phase voltage between phase B and phase C.</source>
        <translation type="vanished">当前PCS的负载侧电压，此项为B相和C相之间的相电压。</translation>
    </message>
    <message>
        <source>The load side voltage of the current PCS, this item is the phase voltage between phase A and phase C.</source>
        <translation type="vanished">当前PCS的负载侧电压，此项为A相和C相之间的相电压。</translation>
    </message>
    <message>
        <source>The current on the load side of PCS is the current of phase A.</source>
        <translation type="vanished">当前PCS的负载侧电流，此项为A相的电流。</translation>
    </message>
    <message>
        <source>The current at the load side of PCS is the current of phase B.</source>
        <translation type="vanished">当前PCS的负载侧电流，此项为B相的电流。</translation>
    </message>
    <message>
        <source>The current at the load side of PCS is the current of phase C.</source>
        <translation type="vanished">当前PCS的负载侧电流，此项为C相的电流。</translation>
    </message>
    <message>
        <source>Current PCS active power (P) on load side.</source>
        <translation type="vanished">当前PCS的负载侧有功功率(P)。</translation>
    </message>
    <message>
        <source>Reactive power (Q) on the load side of current PCS.</source>
        <translation type="vanished">当前PCS的负载侧无功功率(Q)。</translation>
    </message>
    <message>
        <source>Current PCS load side view at power (S), S= √((P^2+Q^2)).</source>
        <translation type="vanished">当前PCS的负载侧视在功率(S)，S= √((P^2+Q^2))。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1281"/>
        <location filename="../win.cpp" line="3216"/>
        <source>Load power factor</source>
        <translation>负载功率因素</translation>
    </message>
    <message>
        <source>The load side power factor (Pf) of the current PCS, Pf = P/S.</source>
        <translation type="vanished">当前PCS的负载侧功率因素(Pf)， Pf = P/S。</translation>
    </message>
    <message>
        <source>Close</source>
        <translation type="vanished">闭合</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3231"/>
        <source>DC input Breaker</source>
        <translation>直流输入断路器</translation>
    </message>
    <message>
        <source>DC input circuit breaker has three states: Break, Close, Trip; The DC input circuit breaker can only be manually disconnected. If the DC input circuit breaker overcurrent, the DC input circuit breaker may trip.</source>
        <translation type="vanished">直流输入断路器有三种状态：断开(Break)，闭合(Close)，脱扣(Trip)；直流输入断路器只能手动断开，如果直流输入断路器过流，直流输入断路器会发生脱扣。</translation>
    </message>
    <message>
        <source>DC contactor has two states: Break, Close; When the DC side is soft Break, the DC contactor is closed. When the DC side of the battery is disconnected, the DC bus voltage drops to a certain voltage, and the DC contactor is disconnected.</source>
        <translation type="vanished">直流接触器有两种状态：断开(Break)，闭合(Close)；当直流侧软启完成后，直流接触器闭合；当电池直流侧断开，直流母线电压下降到一定电压，直流接触器断开。</translation>
    </message>
    <message>
        <source>The output circuit breaker has three states: Break, Close, Trip; If the output circuit breaker overcurrent, the output circuit breaker will trip.</source>
        <translation type="vanished">输出断路器有三种状态：断开(Break)，闭合(Close)，脱扣(Trip)；只能手动断开，如果输出断路器过流，输出断路器会发生脱扣。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3258"/>
        <source>Output Breaker</source>
        <translation>输出断路器</translation>
    </message>
    <message>
        <source>The output contactor has two states: Break, Close; When the DC side soft opening is completed, the output contactor is closed; When the converter is turned off, the output contactor is disconnected.</source>
        <translation type="vanished">输出接触器有两种状态：断开(Break)，闭合(Close)；当直流侧软启完成后，输出接触器闭合；当变流器关机时，输出接触器断开。</translation>
    </message>
    <message>
        <source>The network contactor has two states: Break, Close; When the converter is in grid-connected mode and the grid side voltage is normal, the network contactor is closed. The converter is in off-grid mode and the network contactor is disconnected.</source>
        <translation type="vanished">电网接触器有两种状态：断开(Break)，闭合(Close)，当变流器处于并网模式下，且电网侧电压正常时，电网接触器闭合；变流器处于离网模式下，电网接触器断开。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3276"/>
        <source>Grid Breaker</source>
        <translation>电网断路器</translation>
    </message>
    <message>
        <source>The power grid circuit breaker has three states: Break, Close, Trip; The power grid circuit breaker can only be manually disconnected. If the power grid circuit breaker overflows, the power grid circuit breaker may trip.</source>
        <translation type="vanished">电网断路器有三种状态：断开(Break)，闭合(Close)，脱扣(Trip)；电网断路器只能手动断开，如果电网断路器过流，电网断路器会发生脱扣。</translation>
    </message>
    <message>
        <source>EPO signal</source>
        <translation type="vanished">EPO信号</translation>
    </message>
    <message>
        <source>Shutdown</source>
        <translation type="vanished">关机</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2228"/>
        <source>Export the battery statistics. Click here to export the battery statistics to the U disk.
The accuracy is 0.1, which means that the obtained data multiplied by 0.1 gives the actual value.</source>
        <translation>导出电量统计表，点击此处将会导出电量统计表到U盘里.精度为0.1,即所得数据*0.1为实际的数值.</translation>
    </message>
    <message>
        <source>The current IGBT temperature of the MPS must not exceed 105 ° C. Otherwise, the MPS will derate and can resume full power operation at 73 ° C after derating.</source>
        <translation type="vanished">当前MPS的IGBT温度，IGBT温度不得超过105℃，否则MPS将降额运行，降额后73℃恢复可满功率运行。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3427"/>
        <source>automatic</source>
        <translation>自动</translation>
    </message>
    <message>
        <source>    When automatic and off-grid is selected, it will automatically identify and switch and off-grid. When the voltage on the grid side is normal, the contactor on the grid side will close, and the machine is in grid-connected mode (PQ).When the grid is out of power, the grid side contactor will be disconnected, and the machine is in off-grid mode (VF).
   When the grid-connected mode is selected, and the grid side voltage is normal, the grid side contactor will close, and the machine is in grid-connected mode (PQ);If the power grid loses power, the machine will give an alarm warning of the power grid low voltage.
    When off-grid mode is selected, the machine will disconnect the grid side contactor, and the machine is in off-grid mode (VF).</source>
        <translation type="vanished">    选择自动并离网时，自动识别并切换并离网，当电网侧电压正常时，电网侧接触器将闭合，此时机器处于并网模式（PQ）；当电网失电时，电网侧接触器将断开，此时机器处于离网模式（VF）。
    选择并网模式时，且电网侧电压正常时，电网侧接触器将闭合，此时机器处于并网模式（PQ）；如果电网失电，机器将给出“电网电压低”告警提示。
    选择离网模式时，机器将断开电网侧接触器，此时机器处于离网模式（VF）。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3438"/>
        <source>Constant power(AC)</source>
        <translation>交流侧功率</translation>
    </message>
    <message>
        <source>    This is the power setting of the AC side. The charging and discharging power of the AC side can be controlled by modifying the value of this item.When advanced Settings control power mode select constant power mode (CP_N&amp;P), positive value indicates discharge, negative value indicates charging.
    For example, set -5, indicating that the AC side will charge the battery with a power of -5kW, due to the loss of the inverter, the power on the DC side will be less than the power on the AC side.
    For example, set 5, indicating that the AC side will be 5kW power output, due to the loss of the inverter, the DC side of the power will be greater than the AC side of the power.</source>
        <translation type="vanished">    这是交流侧功率设置，可通过修改该项的值来控制交流侧对电池的充放功率；当高级设置控制功率方式选择恒功率模式(CP_N&amp;P)时，正值表示放电，负值表示充电。比如设置-5，表示交流侧将以-5kW的功率给电池充电，由于逆变器的损耗，此时直流侧的功率将小于交流侧的功率；比如设置5，表示交流侧将以5kW的功率输出，由于逆变器的损耗，此时直流侧的功率将大于交流侧的功率。</translation>
    </message>
    <message>
        <source>Charge</source>
        <translation type="vanished">充电</translation>
    </message>
    <message>
        <source>Reserve.</source>
        <translation type="vanished">保留。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3444"/>
        <source>Manual</source>
        <translation>手动</translation>
    </message>
    <message>
        <source>    When manual mode is selected (applicable to EMS remote scheduling), you can use the HMI or EMS to control the running status of the machine. Charge and discharge power (active power) Reactive power information such as the power factor.
    When the UPS mode (backup mode) is selected, the system switches from zero power to off-grid discharge mode to provide energy for critical loads when the power grid loses power.Please go to the battery setting page to set this mode. Note: This mode is only used in lithium mode, and the communication between PCS and BMS is normal.
    The peak-valley filling mode is used for peak-valley arbitrage. PCS can operate according to the local peak-valley electricity price period, and can go to the automatic operation page to set the charging and discharging mode charging and discharging power and other information during the operation period.
    When the system anti-countercurrent mode is selected, the PCS in this mode is in the local power grid system, and the energy meter is connected at the entrance of the power grid. When the PCS discharges the system, if the PCS detects that there is energy flowing into the power grid in reverse direction, the PCS will actively reduce the power to prevent energy flowing into the power grid.</source>
        <translation type="vanished">    当选择手动模式(适用于EMS远程调度)时，此时可通过HMI 或者EMS 控制机器的运行状态、充放电功率(有功功率)、无功功率、功率因素等信息。
    当选择UPS模式(备电模式)时，当电网失电时，系统将从零功率转换成离网放电模式，给关键负载提供能量；此模式的设置请前往“电池设置”页面进行设置。注：此模式仅用于锂电模式，且PCS与BMS通讯正常。
    削峰填谷模式用于峰谷套利，PCS可根据当地的峰谷电价时段运行，可前往“自动运行”页面设置运行时间段、充放电模式、充放电功率等信息。
    当选择系统防逆流模式时，此模式PCS处于局部电网系统内，且在电网入口处接入了电能表。当PCS对系统放电时，如果PCS检测到有能量反向流入电网，PCS将主动降功率，防止能量流入电网。</translation>
    </message>
    <message>
        <source>    The power factor Pf can be modified. The power factor is equal to the ratio of active power and reactive power. Positive value indicates reactive power lead and negative value indicates reactive power lag.
    The power factor is a coefficient used to measure the output efficiency of electrical equipment, and the power factor is equal to the ratio of active power to reactive power. When the output reactive power factor is selected in the advanced settings &apos;system Settings&apos; page, this output power factor can be modified to control the output of active power and reactive power.</source>
        <translation type="vanished">    此项可以修改功率因素Pf，功率因素等于有功功率和无功功率的比值，正值代表无功超前，负值代表无功滞后。
    功率因数是用来衡量电气设备输出效率高低的一个系数，功率因素等于有功功率和无功功率的比值，当高级设置“系统设置”页面的输出无功方式选择功率因素时，可修改此项输出功率因素，控制有功功率和无功功率的输出。</translation>
    </message>
    <message>
        <source>    This parameter can change the reactive power Q, positive value indicates reactive power lead, negative value indicates reactive power lag.</source>
        <translation type="vanished">    此项可以修改无功功率Q，正值代表无功超前，负值代表无功滞后。</translation>
    </message>
    <message>
        <source>    When the control power mode of the advanced Settings page is set to constant current (CC), modify the constant current value, then the machine will charge and discharge the battery with the current value, positive value represents discharge, negative value represents charging.</source>
        <translation type="vanished">    当高级设置“功能设置”页面的控制功率方式选择恒流(CC)时，修改恒流值，此时机器将以该电流值给电池充放电，正值代表放电，负值代表充电。</translation>
    </message>
    <message>
        <source>    When the control power mode of the Advanced Settings &apos;Function Settings&apos; page is set to constant voltage (CV), modify the constant voltage value, the machine will operate at a constant voltage value, and the machine will be used as a constant voltage source.</source>
        <translation type="vanished">    当高级设置“功能设置”页面的控制功率方式选择恒压(CV)时，修改恒压值，机器将以恒压值进行运行，此时机器将作为一个恒压源。</translation>
    </message>
    <message>
        <source>    This is the control mode;If the local mode is selected, the dispatcher (EMS, RS485) can only monitor data but cannot control PCS. If the remote mode is selected,PCS parameter setting is disabled and the dispatcher (EMS,  RS485) can read and write data.</source>
        <translation type="vanished">    这是控制模式；选择本地模式时，调度机（EMS、RS485等）只能监听数据，不能控制PCS，选择远程模式时，PCS禁止参数设置，调度机（EMS、RS485等）可进行读写。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2854"/>
        <source>Alarm levels uploaded from BMS, level one alarm is yellow, level two alarm is orange, and level three alarm is red;
By default, the converter does not respond to level one and level two alarms, but shuts down in response to level three alarms.</source>
        <translation>BMS上传的告警等级，一级告警为黄色、二级告警为橙色、三级告警为红色；
默认一级告警、二级告警变流器不做响应，三级告警变流器关机。</translation>
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
        <translation>闭合</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3232"/>
        <source>There are two states for a DC circuit breaker: On, Off.</source>
        <translation>直流断路器有两种状态:闭合、断开。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3241"/>
        <source>The DC contactor has two states: On, Off. After the soft start of the DC side is completed, the DC contactor closes. When the DC side of the battery is disconnected and the voltage of the DC bus drops to a certain level, the DC contactor opens.</source>
        <translation>直流接触器有两种状态:闭合，断开;当直流侧软启完成后，直流接触器闭合;当电池直流侧断开，直流母线电压下降到一定电压，直流接触器断开。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3250"/>
        <source>The output contactor has two states: On, Off. The output contactor closes after the soft start on the inv. side is completed. The output contactor opens when the converter is shut down.</source>
        <translation>输出接触器有两种状态:闭合、断开;当逆变侧软启完成后，输出接触器闭合;当变流器关机时，输出接触器断开。</translation>
    </message>
    <message>
        <source>The output circuit breaker has three states: On, Off. It can only be manually opened and closed. If there is an overcurrent in the output circuit breaker, it will trip.</source>
        <translation type="vanished">输出断路器有两种状态:闭合、断开;只能手动断开，如果输出断路器过流，输出断路器会发生脱扣。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3268"/>
        <source>The grid contactor has two states: On, Off. When the inverter is in grid-connected mode and the grid voltage is normal, the grid contactor is closed. When the inverter is in island mode, the grid contactor is open. In the islanded state, the grid contactor remains open.</source>
        <translation>电网接触器有两种状态： 闭合、断开；当变流器处于并网模式下，且电网侧电压正常时，电网接触器闭合；变流器处于离网模式下，电网接触器断开；离网状态下，电网接触器断开。</translation>
    </message>
    <message>
        <source>The power grid circuit breaker has three states: On, Off; The power grid circuit breaker can only be manually disconnected. If the power grid circuit breaker overflows, the power grid circuit breaker may trip.</source>
        <translation type="vanished">电网断路器有两种状态:闭合、断开;只能手动断开，如果电网断路器过流，电网断路器会发生脱扣。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3286"/>
        <source>There are two states for the maintenance bypass circuit breaker: On, Off. This circuit breaker is only used for machine maintenance. If maintenance is required, please contact the maintenance personnel.</source>
        <translation>维修旁路断路器有两种状态:闭合、断开;此断路器仅用于机器维护，如需维护，请联系维护人员。</translation>
    </message>
    <message>
        <source>    This is the device number, and you can choose host(Master) or slave(Slave), where master is Master_00 and Slave_01 to Slave_08 are slaves.</source>
        <translation type="vanished">    这是设备号，可以选择主机(Master)或者从机(Slave)，其中主机为Master_00，其余八项Slave_01~Slave_08均为从机。</translation>
    </message>
    <message>
        <source>Parallel Operation: When multiple devices are operating off-grid in parallel, this setting needs to be enabled.</source>
        <translation type="vanished">并机：多台设备，离网并机时，此项需设为使能。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3427"/>
        <source>Grid conected mode of the converter </source>
        <translation>变流器并网方式 </translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3428"/>
        <source>When &quot;Auto&quot; is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).                                               When &quot;Grid-on&quot; is selected, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.                                               When &quot;Grid-off&quot; is selected, the converter operates in grid-off mode (VF).</source>
        <translation>选择“自动”时，自动切换并离网，当电网侧电压正常时，变流器处于并网模式(PQ);电网失电时，变流器处于离网模式(VF).
选择“并网”时，变流器处于并网模式(PQ);如果电网失电，变流器将关机。
选择“离网”时，变流器处于离网模式(VF).</translation>
    </message>
    <message>
        <source>AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. When the advanced setting for power control mode is set to Constant Power mode (CP_N&amp;P), a positive value indicates discharging, and a negative value indicates charging.For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.</source>
        <translation type="obsolete">2.交流侧功率：可通过修改该项的值来控制交流侧对电池的充放功率;当高级设置控制功率方式选择恒功率模式(CP_N&amp;P)时，正值表示放电，负值表示充电。
比如设置-5，表示交流侧将以-5kW的功率给电池充电，由于逆变器的损耗，此时直流侧的功率将小于交流侧的功率;比如设置5，表示交流侧将以5kW的功率输出，由于逆变器的损耗，此时直流侧的功率将大于交流侧的功率。</translation>
    </message>
    <message>
        <source>AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. When the advanced setting for power control mode is set to Constant Power mode (CP_N&amp;P), a positive value indicates discharging, and a negative value indicates charging.
For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.</source>
        <translation type="vanished">交流侧功率：可通过修改该项的值来控制交流侧对电池的充放功率;当高级设置控制功率方式选择恒功率模式(CP_N&amp;P)时，正值表示放电，负值表示充电。
比如设置-5，表示交流侧将以-5kW的功率给电池充电，由于逆变器的损耗，此时直流侧的功率将小于交流侧的功率;比如设置5，表示交流侧将以5kW的功率输出，由于逆变器的损耗，此时直流侧的功率将大于交流侧的功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3463"/>
        <source>This item can modify the power factor, where the power factor is equal to the ratio of active power to apparent power. A positive value indicates leading reactive power, while a negative value indicates lagging reactive power.</source>
        <translation>此项可以修改功率因素Pf，功率因素等于有功功率和视在功率的比值，正值代表无功超前，负值代表无功滞后。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3472"/>
        <source>This parameter can change the reactive power Q, positive value indicates leading reactive power, negative value indicates lagging reactive power.</source>
        <translation>此项可以修改无功功率Q，正值代表无功超前，负值代表无功滞后。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3481"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant voltage and modify the voltage value. Converter will operate at the constant voltage value and function as a constant voltage source.</source>
        <translation>进入高级设置的功能设置界面，在控制功率方式选择：恒流(CC)，修改恒流值，此时机器将以该电流值给电池充放电，正值代表放电，负值代表充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3490"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant current and modify the current value. Converter will charge or discharge the battery with this current value. Positive values represent discharging, while negative values represent charging.</source>
        <translation>进入高级设置的功能设置界面的控制功率方式选择：恒压(CV)，修改恒压值，机器将以恒压值进行运行，此时机器将作为一个恒压源。</translation>
    </message>
    <message>
        <source>M_00</source>
        <translation type="obsolete">M_00</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3510"/>
        <source>M_01</source>
        <translation>M_01</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3511"/>
        <source>Device number: You can set ID number, which can be set within the range of M_01 to M_12.</source>
        <translation>设备号：可以设置设备标识号，可设置范围为M_01~M_12。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3520"/>
        <source>Parallel operation: When converter operates at grid-off mode in parallel, this item needs to be enabled.</source>
        <translation>并机:多台设备离网并机时，此项需设为使能。</translation>
    </message>
    <message>
        <source>DOD_OnGrid</source>
        <translation type="vanished">并网DOD</translation>
    </message>
    <message>
        <source>Grid-connected DOD, the depth of discharge allowed in grid-connected mode.</source>
        <translation type="vanished">并网DOD，并网模式下允许的放电深度。</translation>
    </message>
    <message>
        <source>DOD_OffGrid</source>
        <translation type="vanished">离网DOD</translation>
    </message>
    <message>
        <source>Off-network DOD: Discharge depth allowed in off-network mode.</source>
        <translation type="vanished">离网DOD，离网模式下允许的放电深度。</translation>
    </message>
    <message>
        <source>Charge_Vol_Up_Limit</source>
        <translation type="vanished">充电电压上限</translation>
    </message>
    <message>
        <source>This is the upper limit of the charging voltage. When the total battery voltage reaches this value during charging, the PCS will enter the constant voltage mode to prevent the battery from overcharging.</source>
        <translation type="vanished">这是充电电压上限，当充电时电池总电压达到这个值时，PCS将会进入到恒压模式，防止电池过充。</translation>
    </message>
    <message>
        <source>Disc_Vol_lower_Limit</source>
        <translation type="vanished">放电电压下限</translation>
    </message>
    <message>
        <source>This is the lower limit of the discharge voltage. When the total battery voltage during discharge reaches this value, PCS will trigger a battery low voltage alarm, and PCS will shut down to prevent battery overdischarge.</source>
        <translation type="vanished">这是放电电压下限，当放电时电池总电压达到这个值时，PCS将会触发电池电压低告警，PCS关机，防止电池过放.</translation>
    </message>
    <message>
        <source>Charge_Cur_Limit</source>
        <translation type="vanished">充电限流点</translation>
    </message>
    <message>
        <source>This is the upper limit of charging current, which is the maximum current allowed on the DC side of PCS to prevent charging overcurrent.</source>
        <translation type="vanished">这是充电电流上限，这是PCS直流侧允许的最大电流，防止充电过流。</translation>
    </message>
    <message>
        <source>Gen_turn_off_SOC</source>
        <translation type="vanished">柴发关闭SOC</translation>
    </message>
    <message>
        <source>When the specified SCO value is reached, the diesel generator shuts down.</source>
        <translation type="vanished">达到指定SCO值时，柴油发电机关闭。</translation>
    </message>
    <message>
        <source>Gen_turn_on_SOC</source>
        <translation type="vanished">柴发开启SOC</translation>
    </message>
    <message>
        <source>When the specified SOC value is reached, the diesel generator starts.</source>
        <translation type="vanished">达到指定SOC值时，柴油发电机开启。</translation>
    </message>
    <message>
        <source>Gen_charge_SOC</source>
        <translation type="vanished">柴发充电</translation>
    </message>
    <message>
        <source>This is the diesel generator charging SOC, this parameter is used in the combined power supply mode, when the battery SOC reaches this value, the PCS starts charging.</source>
        <translation type="vanished">这是柴发充电SOC，该参数在联合供电模式下使用，当电池SOC达到该值时，PCS开启充电。</translation>
    </message>
    <message>
        <source>Grid_charge_SOC</source>
        <translation type="vanished">电网充电</translation>
    </message>
    <message>
        <source>This is the grid charging SOC, this parameter is used in the combined power supply mode, when the battery SOC reaches this value, the PCS starts charging.</source>
        <translation type="vanished">这是电网充电SOC，该参数在联合供电模式下使用，当电池SOC达到该值时，PCS开启充电。</translation>
    </message>
    <message>
        <source>Charge stop SOC: The battery will stop charging when the current SOC is higher than the preset value.</source>
        <translation type="vanished">充电停止SOC：当电池的当前SOC高于预设值时，将停止充电。</translation>
    </message>
    <message>
        <source>Discharge stop SOC: The battery will stop discharging when the current SOC is below a preset value.</source>
        <translation type="vanished">放电停止SOC：当电池的当前SOC低于预设值时，将停止放电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3679"/>
        <source>Grid_capacity</source>
        <translation>电网容量</translation>
    </message>
    <message>
        <source>This is the power grid capacity, the maximum capacity input on the AC side of PCS, and this parameter takes effect in the combined power supply mode.</source>
        <translation type="vanished">这是电网容量，PCS交流侧输入的最大容量，该参数在联合供电模式下生效。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3691"/>
        <source>Turn_on_SOC</source>
        <translation>启动SOC</translation>
    </message>
    <message>
        <source>When UPS mode is selected and battery SOC reaches this value,PCS starts charging.</source>
        <translation type="vanished">当工作模式选择UPS模式时，电池SOC达到该值时，PCS开启充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3700"/>
        <source>Turn_off_SOC</source>
        <translation>停止SOC</translation>
    </message>
    <message>
        <source>When UPS mode is selected,PCS stops charging when battery SOC reaches this value.</source>
        <translation type="vanished">当工作模式选择UPS模式时，电池SOC达到该值时，PCS停止充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3709"/>
        <source>Turn_on_cell_vol</source>
        <translation>启动单体电压</translation>
    </message>
    <message>
        <source>When UPS mode is selected, the PCS starts charging when the minimum battery voltage reaches the value.</source>
        <translation type="vanished">当工作模式选择UPS模式时，电池单体最低电压达到该值时，PCS开启充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3718"/>
        <source>Turn_off_cell_vol</source>
        <translation>停止单体电压</translation>
    </message>
    <message>
        <source>When UPS mode is selected, PCS stops charging when the maximum battery voltage reaches this value.</source>
        <translation type="vanished">当工作模式选择UPS模式时，电池单体最高电压达到该值时，PCS停止充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3727"/>
        <source>Turn_on_total_vol</source>
        <translation>启动总压</translation>
    </message>
    <message>
        <source>When the UPS mode is selected, the PCS starts charging when the total battery voltage reaches the value.</source>
        <translation type="vanished">当工作模式选择UPS模式时，电池总压达到该值时，PCS开启充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3736"/>
        <source>Turn_off_total_vol</source>
        <translation>停止总压</translation>
    </message>
    <message>
        <source>When UPS mode is selected, PCS stops charging when the total battery voltage reaches this value.</source>
        <translation type="vanished">当工作模式选择UPS模式时，电池总压达到该值时，PCS停止充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3745"/>
        <source>UPS_charge_power</source>
        <translation>后备充电功率</translation>
    </message>
    <message>
        <source>When UPS mode is selected, the backup charging power of PCS is used when the battery starts charging.</source>
        <translation type="vanished">当工作模式选择UPS模式时，电池启动充电时PCS的后备充电功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3754"/>
        <source>Monthly_cycle_time</source>
        <translation>月循环日期</translation>
    </message>
    <message>
        <source>On the same day of each month, there is a deep charge and discharge.</source>
        <translation type="vanished">每月的当日，会进行一次深度充放电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3764"/>
        <source>Capacity, the capacity of the lead-acid battery.</source>
        <translation>容量，铅酸电池的容量大小。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3768"/>
        <source>Cell_number_2V</source>
        <translation>电池节数（2V）</translation>
    </message>
    <message>
        <source>The number of cells connected in a battery stack.</source>
        <translation type="vanished">电池堆串联单体的数量。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3774"/>
        <source>This is the floating charge voltage.</source>
        <translation>这是浮充电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3779"/>
        <source>This is the filling voltage.</source>
        <translation>这是均充电压。</translation>
    </message>
    <message>
        <source>Charge_limiting_value</source>
        <translation type="vanished">充电限流值</translation>
    </message>
    <message>
        <source>Upper limit of charging current, which is the maximum current allowed on the DC side of PCS to prevent charging overcurrent.</source>
        <translation type="vanished">充电电流上限，这是PCS直流侧允许的最大电流，防止充电过流。</translation>
    </message>
    <message>
        <source>Discharge_limiting_value</source>
        <translation type="vanished">放电限流值</translation>
    </message>
    <message>
        <source>The upper limit of discharge current, which is the maximum current allowed to discharge on the DC side of PCS to prevent discharge from overcurrent.</source>
        <translation type="vanished">放电电流上限，这是PCS直流侧允许放电的最大电流，防止放电过流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3835"/>
        <source>End time: The system stops automatically running when the system reaches this time.</source>
        <translation>结束时间：系统到达此时间后停止自动运行.</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3836"/>
        <source>This working state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic.</source>
        <translation>工作状态,将在工作时间执行此状态,有三种可供选择，分别为充电、放电、自动。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3837"/>
        <source>Working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.</source>
        <translation>工作功率,此状态下工作时根据工作状态执行此功率，正数为放电，负数为充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3838"/>
        <source>Start time: When the system reaches this time, it starts to run automatically.</source>
        <translation>开始时间：系统到达此时间后开始自动运行.</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3839"/>
        <source>Select: After this function is enabled, the system automatically runs the selected function mode within the specified period.</source>
        <translation>选择：使能后，系统将按照设置的时间段自动运行选择的功能模式.</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4576"/>
        <source>This is the monitoring version number.</source>
        <translation>这是监控版本号</translation>
    </message>
    <message>
        <source>Battery Protocol: This is the battery protocol that parses the packets sent by the BMS according to the selected battery protocol.
Currently, the following battery manufacturer protocols are supported: MEGA, LISHEN, PENGHUI, GOLD, BMSER, LANLI, SHENLAN, PAINENG, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD,PGS, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, ECUBE, FARO, BGS, JDITEC, HUASU, LIGAO.
When you select AUTO, the system automatically determines the battery manufacturer.</source>
        <translation type="vanished">    电池协议：这是电池协议，根据选择的电池协议解析BMS发送的报文。
    目前支持选择的电池厂家协议为：MEGA、LISHEN、PENGHUI、GOLD、BMSER、LANLI、SHENLAN、PAINENG、NINGDESHIDAI、SUOYING、XINGWANGDA、KUBO、GAOTE_V2、TOGOOD、PGS、WOBO 、KGOOER 、LIDE、 PAINENG_L 、WEILAN 、ALPHA 、TUOPU、 JIEHUI、 JDI 、ECUBE、FARO、 BGS 、JDITEC 、HUASU、 LIGAO。
    选择AUTO时将自动判断电池厂家协议。</translation>
    </message>
    <message>
        <source>Transformer Turns Ratio: Please refer to the factory nameplate for the turns ratio setting based on the built-in transformer. If any changes are required, please contact customer service for confirmation.</source>
        <translation type="vanished">变压器变比：根据内置变压器的变比设置，以出厂铭牌标识为准,如需更改，请联系客服确认。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5017"/>
        <source>Non
adjustable</source>
        <translation>不可调节</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5018"/>
        <source>Reactive Power Output Mode: Default non-adjustable, options include Power Factor, Reactive Power, non-adjustable.</source>
        <translation>输出无功方式：默认不可调节，可供选择为功率因数、无功功率、不可调节。</translation>
    </message>
    <message>
        <source>Non
countercurrent</source>
        <translation type="vanished">不可逆流</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1253"/>
        <location filename="../win.cpp" line="5026"/>
        <source>Converter Anti-Reverse Flow</source>
        <translation>变流器防逆流</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5027"/>
        <source>Converter Anti-Reverse Flow: Enable, Disable; Enabling prevents converter current from flowing into the grid, while Disabling allows converter current to flow into the grid.</source>
        <translation>变流器防逆流：使能、禁止
使能即变流器电流禁止流向电网，禁止即变流器电流允许流向电网。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5037"/>
        <source>System Anti-Reverse Flow: Enable, Disable;
Enabling prevents system current from flowing into the grid, while Disabling allows system current to flow into the grid.</source>
        <translation>系统防逆流：使能、禁止
使能即系统电流禁止流向电网，禁止即系统电流允许流向电网。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5047"/>
        <source>Frequency Deviation Deadzone: A frequency difference settings to prevent unnecessary frequency regulation actions during minor grid frequency fluctuations. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation>一次调频死区：为了防止在电网频差小范围变化时调频不必要的动作而设置的频差。(注:此项一般在大型并网电站使用。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5056"/>
        <source>Active Frequency Regulation Coefficient: The active frequency regulation coefficient can be configured. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation>有功调频系数：可以设置有功调频系数。(注:此项—般在大型并网电站使用。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5100"/>
        <source>Backup</source>
        <translation>备份</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5129"/>
        <source>When the dry contact is enabled, the device will perform the selected action when there is a change in the signal.</source>
        <translation>当干接点使能后，信号变化时，设备将会执行此项所选的动作。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5130"/>
        <source>Input Dry Contact:                       
Enabled: Triggers the Action when the dry contact detects a state other than the specified NO/NC.                      
Disabled: No action is taken when the dry contact detects a state other than the specified NO/NC.</source>
        <translation>输入干接点：
使能：当干接点检测到与指定的常开/常闭状态不一致时，触发动作。
禁止：当干接点检测到与指定的常开/常闭状态不一致时，不执行任何动作。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5139"/>
        <source>DI 1 Enable</source>
        <translation>干接点1使能</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5147"/>
        <source>DI 2 Enable</source>
        <translation>干接点2使能</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5155"/>
        <source>DI 3 Enable</source>
        <translation>干接点3使能</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5163"/>
        <source>DI 4 Enable</source>
        <translation>干接点4使能</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5171"/>
        <source>DI 5 Enable</source>
        <translation>干接点5使能</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5179"/>
        <source>DI 6 Enable</source>
        <translation>干接点6使能</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5290"/>
        <source>DOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation>DOD保护，触发DOD保护时执行的动作，可选功能为不动作、待机、关机、0功率待机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5299"/>
        <source>The action performed when the charge ban is triggered;Optional function: NO action, Standby, Shut down,0 power standby.</source>
        <translation>触发禁充时执行的动作，可选功能为不动作、待机、关机、0功率待机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5308"/>
        <source>The action to be performed when a ban is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation>触发禁放时执行的动作，可选功能为不动作、待机、关机、0功率待机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5343"/>
        <source>level 1 alarm CP</source>
        <translation>一级告警充电功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5344"/>
        <source>The charging power executed when a level 1 alarm is triggered.</source>
        <translation>触发一级告警时执行的的充电功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5352"/>
        <source>level 2 alarm CP</source>
        <translation>二级告警充电功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5353"/>
        <source>The charging power executed when a level 2 alarm is triggered.</source>
        <translation>触发二级告警时执行的的充电功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5370"/>
        <source>level 1 alarm DP</source>
        <translation>一级告警放电功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5371"/>
        <source>The discharging power executed when a level 1 alarm is triggered.</source>
        <translation>触发一级告警时执行的的放电功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5379"/>
        <source>level 2 alarm DP</source>
        <translation>二级告警放电功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5380"/>
        <source>The discharging power executed when a level 2 alarm is triggered.</source>
        <translation>触发二级告警时执行的的放电功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5816"/>
        <source>Upgrade prompt</source>
        <translation>升级提示</translation>
    </message>
    <message>
        <source>1. Make sure to press the EPO button before upgrading.                              
2. Before upgrading the DCDC, switch off the ship-type switch of the DCDC module.</source>
        <translation type="vanished">1. 升级前确保已按下EPO。
2. 升级DCDC前先把DCDC模块的船型开关拨到OFF位置。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5838"/>
        <source>Working mode</source>
        <translation>工作模式</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5839"/>
        <source>When selecting the manual mode, the converter’s operating status, charging or discharging power (active power), reactive power, power factor etc,can be controlled through HMI or EMS.                              When selecting the UPS mode, When the grid side is abnormal, the system will switch from zero power to grid-off discharge mode to provide energy to critical loads. Please go to the &quot;Battery Settings&quot; page to configure this mode. Note: This mode is only applicable to lithium battery mode and requires normal communication between the converter and BMS.                              Peak shaving and valley filling mode is used for peak-valley price arbitrage. The converter can operate according to the local peak-valley electricity price periods. Please set the operating time period, charging or discharging mode, charging or discharging power, and other information on the &quot;Mixed mode&quot; page.
Grid expansion.</source>
        <translation>当选择手动模式时，可通过HMI或者EMS 控制机器的运行状态、充放电功率(有功功率)、无功功率、功率因素等。
当选择UPS模式时，当电网失电时，系统将从零功率转换成离网放电模式，给关键负载提供能量;此模式的设置请前往&quot;电池设置&quot;页面进行设置。注:此模式仅用于锂电模式，且变流器与BMS通讯正常。
削峰填谷模式用于峰谷套利，PCS可根据当地的峰谷电价时段运行，请在&quot;混合模式&quot;页面设置运行时间段、充放电模式、充放电功率等信息。
电网扩容。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5842"/>
        <source>Click to view grid expansion</source>
        <translation>点击查看电网扩容</translation>
    </message>
    <message>
        <source>Generator_turn_off_SOC_B1</source>
        <translation type="vanished">发电机关闭SOC</translation>
    </message>
    <message>
        <source>Generator_turn_on_SOC_A1</source>
        <translation type="vanished">发电机开启SOC</translation>
    </message>
    <message>
        <source>Grid_off_EOD</source>
        <translation type="vanished">离网EOD</translation>
    </message>
    <message>
        <source>Grid_on_EOD</source>
        <translation type="vanished">并网EOD</translation>
    </message>
    <message>
        <source>This is uniform charging and flushing current.</source>
        <translation type="vanished">这是浮充转均充电流。</translation>
    </message>
    <message>
        <source>This is float turn uniform charging current.</source>
        <translation type="vanished">这是均充转浮充电流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3829"/>
        <source>Start_Time</source>
        <translation>开始时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3830"/>
        <source>End_Time</source>
        <translation>结束时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3832"/>
        <source>Power</source>
        <translation>功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3833"/>
        <source>9:00</source>
        <translation>9:00</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3834"/>
        <source>10:00</source>
        <translation>10:00</translation>
    </message>
    <message>
        <source>This is&apos; Enable &apos;, which will enable the specified state at the specified time with the specified power, and end at the specified time.</source>
        <translation type="vanished">这是&apos;使能&apos;，选择后将在指定的时间以指定的功率开启指定的状态，并在指定的时间结束。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4829"/>
        <source>Energy meter model: The energy meter model is selected according to the type of energy meter that is connected. According to the characteristics and specifications of the connected watt-hour meter, select the corresponding watt-hour meter model, which can be selected NONE, DTSD1352, AMC96-E4/KC or ADL3000-E-B.</source>
        <translation>电能表型号：电能表型号是根据接入的电能表类型进行选择的。根据所连接的电能表的特性和规格，选择相应的电能表型号，可根据情况选择NONE、DTSD1352、AMC96-E4/KC或ADL3000-E-B。</translation>
    </message>
    <message>
        <source>Insulation detection Enable, insulation resistance greater than 33KΩ to be able to operate normally, less than 33KΩ can not start, and to alarm, the default prohibition, the choice is to Enable, prohibit.</source>
        <translation type="vanished">绝缘检测使能，绝缘电阻大于33KΩ要能正常起机运行，小于33KΩ不能起机，并且要告警，默认禁止,可供选择为允许(Enable)、禁止(prohibit)。</translation>
    </message>
    <message>
        <source>Set according to the machine model on site, the factory value prevails, the default PCS-TS, if you need to change, please contact customer service.</source>
        <translation type="vanished">根据现场机器机器型号设置，以出厂值为准，默认PCS-TS，如需更改，请联系客服。</translation>
    </message>
    <message>
        <source>This is the start time at which the specified state will begin to be entered with the specified power.</source>
        <translation type="vanished">这是开始时间，将在此时间开始以指定的功率进入指定的状态。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10058"/>
        <location filename="../win.cpp" line="3793"/>
        <source>Generator turn off voltage</source>
        <translation>发电机关闭电压</translation>
    </message>
    <message>
        <source>Generator shutdown voltage.</source>
        <translation type="vanished">发电机关闭电压。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="10122"/>
        <location filename="../win.cpp" line="3798"/>
        <source>Generator turn on voltage</source>
        <translation>发电机开启电压</translation>
    </message>
    <message>
        <source>Generator opening voltage.</source>
        <translation type="vanished">发电机开启电压。</translation>
    </message>
    <message>
        <source>Off-grid discharge cut-off voltage.</source>
        <translation type="vanished">离网放电截止电压。</translation>
    </message>
    <message>
        <source>Grid-connected discharge cut-off voltage.</source>
        <translation type="vanished">并网放电截止电压。</translation>
    </message>
    <message>
        <source>This is the end time at which the state started with the &apos;start time&apos; will end.</source>
        <translation type="vanished">这是结束时间，将在此时间结束由&apos;开始时间&apos;开始的状态。</translation>
    </message>
    <message>
        <source>This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic.</source>
        <translation type="vanished">这是状态，将在工作时间执行此状态，有三种可供选择，分别为充电、放电、自动。</translation>
    </message>
    <message>
        <source>This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.</source>
        <translation type="vanished">这是工作功率，此状态下工作时根据工作状态执行此功率，正数为放电，负数为充电。</translation>
    </message>
    <message>
        <source>This is the name of the manufacturer.</source>
        <translation type="vanished">这是厂家名称。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="395"/>
        <location filename="../win.cpp" line="4584"/>
        <source>Protocol Version</source>
        <translation>监控版本</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4585"/>
        <source>This is the protocol version number.</source>
        <translation>这是协议版本号。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4594"/>
        <source>This is the converter software version.</source>
        <translation>这是变流器软件版本。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4603"/>
        <source>This is the CPLD software version.</source>
        <translation>这是CPLD软件版本。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4611"/>
        <source>SN</source>
        <translation>SN</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4612"/>
        <source>This is SN, the serial number of the product.</source>
        <translation>这是SN,即产品序列号。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8994"/>
        <location filename="../win.cpp" line="4626"/>
        <source>Lithium</source>
        <translation>锂电</translation>
    </message>
    <message>
        <source>Choose the battery type according to the actual situation, there are two types of Lithium and LeadAcid to choose from.</source>
        <translation type="vanished">根据实际情况选择电池类型，有锂电(Lithium)和铅酸(LeadAcid)两种类型可供选择。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4635"/>
        <source>BMS Comm type</source>
        <translation>电池通信方式</translation>
    </message>
    <message>
        <source>Set the communication mode between the battery, RS485 or CAN communication or Ethernet can be selected according to the situation.</source>
        <translation type="vanished">设置与电池之间的通信方式，可根据情况选择RS485(RS485)或CAN通信(CAN)或以太网(Ethernet)。</translation>
    </message>
    <message>
        <source>Set the control power mode, including constant voltage (CV), constant current (CC), constant power (CP_P), and positive and negative power (CP_N&amp;P).
If constant voltage (CV) mode is selected, the converter will operate in constant voltage mode.
If constant current (CC) mode is selected, the converter will operate in constant current mode.
If you choose constant power (CP_P) or positive and negative power (CP_N&amp;P) mode: you can set the power size at &apos;constant power&apos;, the value is the size of the power size, positive for discharge, negative for charging.</source>
        <translation type="vanished">设置控制功率的方式，有恒压(CV)、恒流(CC)、恒功率(CP_P)、正负功率(CP_N&amp;P)。
如果选择恒压(CV)模式，变流器将以恒压模式运行。
如果选择恒流(CC)模式，变流器将以恒流模式运行。
如果选择恒功率(CP_P)或者正负功率(CP_N&amp;P)模式：可以在&apos;恒功率&apos;处设置功率大小，数值为大小为功率大小，正值为放电，负值为充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4656"/>
        <source>EMS Comm type</source>
        <translation>EMS通信方式</translation>
    </message>
    <message>
        <source>You CAN set the communication mode of the EMS, including RS485,CAN, and Ethernet. Select one communication mode that can be read and written remotely, and the other two communication modes can be read only.</source>
        <translation type="vanished">设置EMS的通信方式，有RS485(RS485),CAN通信(CAN)和以太网(Ethernet)三种方式，选中其中一种通信方式，该通信方式远程可读可写，其他两种通信方式仅可读。</translation>
    </message>
    <message>
        <source>HMI Limits the range of power Settings on the AC side.</source>
        <translation type="vanished">HMI限制交流侧功率设置值的范围。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4675"/>
        <source>Auto</source>
        <translation>自动</translation>
    </message>
    <message>
        <location filename="../win.ui" line="603"/>
        <location filename="../win.cpp" line="4675"/>
        <source>BAT protocol</source>
        <translation>电池协议</translation>
    </message>
    <message>
        <source>This is the battery protocol that parses the packets sent by the BMS according to the selected battery protocol.</source>
        <translation type="vanished">这是电池协议，根据选择的电池协议解析BMS发送的报文。</translation>
    </message>
    <message>
        <source>Set the power back difference, the default power back difference is 10kw, the output power increases to &apos;output power limit + power back difference&apos;, will reduce the output power to &apos;output power - power back difference&apos;, (Note: this setting only takes effect in the system anti-countercurrent mode, for control of power grid inlet power back difference).</source>
        <translation type="vanished">设置功率回差，默认功率回差为10kw，输出功率增加达到&apos;输出功率限制+功率回差&apos;时，会将输出功率降低到&apos;输出功率-功率回差&apos;，(注：本设置仅在系统防逆流模式生效，用于控制电网入口的功率回差)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3608"/>
        <source>Set the charging power limit to allow the maximum power of charging.</source>
        <translation>设置充电功率限制,允许充电的功率最大值。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3535"/>
        <source>Grid-on DOD</source>
        <translation>并网DOD</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3536"/>
        <source>Grid-on DOD, allowable depth of discharge in grid-on mode.</source>
        <translation>并网DOD，并网模式下允许的放电深度。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3544"/>
        <source>Grid-off DOD</source>
        <translation>离网DOD</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3545"/>
        <source>Grid-off DOD, allowable depth of discharge in grid-off mode.</source>
        <translation>离网DOD，离网模式下允许的放电深度。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3553"/>
        <source>Charge Volt upper Limit</source>
        <translation>充电电压上限</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3554"/>
        <source>Charging voltage upper limit: When the battery total voltage reaches this value during charging, the converter will shut down.</source>
        <translation>充电电压上限：充电时电池总电压达到这个值，变流器将关机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3563"/>
        <source>Charging voltage upper limit hysteresis: When the battery is charging, if the battery total voltage reaches the charging voltage upper limit, the converter will shut down. When the battery total voltage drops below the charging voltage upper limit minus the hysteresis value, the converter will automatically turn on.</source>
        <translation>充电电压上限回差：电池充电时，电池总压达到充电电压上限后，变流器将关机。电池总压低于充电电压上限减去回差值时，变流器自动开机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3571"/>
        <source>Discharge Volt lower Limit</source>
        <translation>放电电压下限</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3572"/>
        <source>Discharge voltage lower limit: When the battery total voltage reaches this value during discharge, the converter will shut down.</source>
        <translation>放电电压下限：放电时电池总电压低于这个值，变流器将关机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3581"/>
        <source>Discharge voltage lower limit hysteresis: When the battery is discharging, if the battery total voltage drops below the discharge voltage lower limit, the converter will shut down. When the battery total voltage exceeds the discharge voltage lower limit plus the hysteresis value, the converter will automatically turn on.</source>
        <translation>放电电压下限回差：电池放电时，电池总压低于放电电压下限后，变流器将关机。电池总压高于放电电压下限加上回差值时，变流器自动开机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3589"/>
        <source>Charge Current Limit</source>
        <translation>充电电流限制</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3590"/>
        <source>Charging current limit: The maximum allowable current on the battery side to prevent overcurrent during charging.</source>
        <translation>充电电流限制：电池侧允许的最大电流，防止充电过流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3598"/>
        <source>Discharge Current Limit</source>
        <translation>放电电流限制</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3599"/>
        <source>Discharging current limit: The maximum allowable current on the battery side to prevent overcurrent during Discharging.</source>
        <translation>放电电流限制：电池侧允许的最大电流，防止放电过流。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3617"/>
        <source>The discharge power limit is set to allow the maximum power of the discharge.</source>
        <translation>设置放电功率限制，允许放电的功率最大值。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3562"/>
        <source>Charge Vol upper Limit delta</source>
        <translation>充电电压上限回差</translation>
    </message>
    <message>
        <source>Set the upper Limit of Charge voltage delta (Charge Vol upper Limit delta). The default upper limit of charge voltage is 10V. When the charge voltage reaches the &apos;upper limit of charge voltage + charge voltage delta&apos;, the device will be forbidden to charge, and when the charge voltage drops to the &apos;upper limit of charge voltage - charge voltage delta&apos;, the forbidden charge will be lifted.</source>
        <translation type="vanished">设置充电电压上限回差，默认充电电压上限为10V，充电电压达到&apos;充电电压上限+充电电压回差&apos;时，将会对设备进行禁充，充电电压降到&apos;充电电压上限-充电电压回差&apos;时解除禁充。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3580"/>
        <source>Discharge Vol lower Limit delta</source>
        <translation>放电电压下限回差</translation>
    </message>
    <message>
        <source>Set the Discharge voltage lower Limit delta (Discharge Vol lower Limit delta), the default discharge voltage lower limit delta is 10V, when the discharge voltage is lower than the &apos;discharge voltage lower limit - discharge voltage delta&apos;, the device will be prohibited, when the discharge voltage reaches the &apos;discharge voltage lower limit + charge voltage delta&apos;, the prohibited discharge will be lifted.</source>
        <translation type="vanished">设置放电电压下限回差，默认放电电压下限回差为10V，放电电电压低于&apos;放电电压下限-放电电电压回差&apos;时，将会对设备进行禁放，放电电压达到&apos;放电电压下限+充电电压回差&apos;时解除禁放。</translation>
    </message>
    <message>
        <source>This is the device address, which defaults to 1 and can be adjusted from 1 to 255 to match the host address during EMS communication.</source>
        <translation type="vanished">这是设备地址，默认值为1，可调范围在1~255之间，用于EMS通信时匹配主机地址。</translation>
    </message>
    <message>
        <source>This is serial port 1, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 1 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1).</source>
        <translation type="vanished">这是串口1，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口1默认波特率是9600bps，八个数据位，无校验，一个停止位（8，N，1）。</translation>
    </message>
    <message>
        <source>This is serial port 2, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 2 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1).</source>
        <translation type="vanished">这是串口2，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口2默认波特率是9600bps，八个数据位，无校验，一个停止位（8，N，1）。</translation>
    </message>
    <message>
        <source>This is serial port 3, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 3 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1).</source>
        <translation type="vanished">这是串口3，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口3默认波特率是9600bps，八个数据位，无校验，一个停止位（8，N，1）。</translation>
    </message>
    <message>
        <source>This is serial port 4, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 4 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1).</source>
        <translation type="vanished">这是串口4，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口4默认波特率是9600bps，八个数据位，无校验，一个停止位（8，N，1）。</translation>
    </message>
    <message>
        <source>This is serial port 5, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 5 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1).</source>
        <translation type="vanished">这是串口5，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口5默认波特率是9600bps，八个数据位，无校验，一个停止位（8，N，1）。</translation>
    </message>
    <message>
        <source>This is the CAN1 port, the baud rate of PCS internal communication, the default baud rate is 500kbps, eight data bits, no check, one stop bit(8, N, 1).</source>
        <translation type="vanished">这是CAN1端口，PCS内部通讯的波特率，默认波特率500kbps，八个数据位，无校验，一个停止位（8，N，1）。</translation>
    </message>
    <message>
        <source>This is the CAN2 port, the baud rate of PCS internal communication, the default baud rate is 125kbps, eight data bits, no check, one stop bit(8, N, 1).</source>
        <translation type="vanished">这是CAN2端口，PCS内部通讯的波特率，默认波特率125kbps，八个数据位，无校验，一个停止位（8，N，1）。</translation>
    </message>
    <message>
        <source>This is the protocol version number, which is used to view the current protocol version. The protocol version number defaults to V1.0.</source>
        <translation type="vanished">这是协议版本号，用于查看当前协议版本,协议版本号默认为V1.0。</translation>
    </message>
    <message>
        <source>This is the user password, you can reset the user password, the default user password 123456, (note: User password must be six digits).</source>
        <translation type="vanished">这是用户密码，可供重新设置用户密码，默认用户密码123456，(注：用户密码必须为六位数)。</translation>
    </message>
    <message>
        <source>This is the super permission password, you can reset the super permission password, the default super permission password 888888, (Note: super permission password must be six digits).</source>
        <translation type="vanished">这是超级权限密码，可供重新设置超级权限密码，默认超级权限密码888888，(注：超级权限密码必须为六位数)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4797"/>
        <source>English</source>
        <translation>中文</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4798"/>
        <source>Set the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages.</source>
        <translation>设置显示屏的显示语言，可供选择为中文与英文，切换语言时系统会重启。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4811"/>
        <source>upgrade</source>
        <translation>升级</translation>
    </message>
    <message>
        <source>Click to enter the system upgrade application and upgrade the system according to the upgrade document.</source>
        <translation type="vanished">点击即可进入系统升级应用程序，根据升级文档进行系统升级。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4819"/>
        <source>Allow</source>
        <translation>允许</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4820"/>
        <source>Set whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid).</source>
        <translation>设置显示屏是否开启声音，可供选择为允许(Allow)、禁止(forbid)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4828"/>
        <source>NONE</source>
        <translation>NONE</translation>
    </message>
    <message>
        <source>Energy meter model: The energy meter model is selected according to the type of energy meter that is connected. According to the characteristics and specifications of the connected energy meter, select the corresponding energy meter model.</source>
        <translation type="vanished">电能表型号：电能表型号是根据接入的电能表类型进行选择的。根据所连接的电能表的特性和规格，选择相应的电能表型号。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4837"/>
        <source>20</source>
        <translation>20</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4837"/>
        <source>Bms Com. Fault Time</source>
        <translation>BMS通信故障判定时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4838"/>
        <source>BMS communication fault determination time: The BMS communication fault determination time refers to the BMS communication fault when the BMS communication is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation>BMS通信故障判定时间：BMS通信故障判定时间是指当BMS通信断开，并经过预设的一段时间后仍未恢复正常通信时，将判定为BMS通信故障。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4846"/>
        <source>EMS Com. Fault Model</source>
        <translation>EMS通信故障判定时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4847"/>
        <source>EMS communication fault determination time: The EMS communication fault determination time refers to the time when the communication between the EMS is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation>EMS通信故障判定时间：EMS通信故障判定时间是指当EMS通信断开，并经过预设的一段时间后仍未恢复正常通信时，将判定为EMS通信故障。</translation>
    </message>
    <message>
        <source>How fast the power changes per unit time.</source>
        <translation type="vanished">单位时间内功率变化的快慢。</translation>
    </message>
    <message>
        <source>The upper limit of the frequency range allowed on the AC side is 0.2, 0.5, 1, and 3.</source>
        <translation type="vanished">交流侧所允许的频率变化范围的上限，可供选择为0.2、0.5、1、3。</translation>
    </message>
    <message>
        <source>The lower limit of the frequency range allowed on the AC side can be selected as -0.2, -0.5, -1, or -3.</source>
        <translation type="vanished">交流侧所允许的频率变化范围的下限，可供选择为-0.2、-0.5、-1、-3。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1109"/>
        <location filename="../win.cpp" line="4890"/>
        <source>Vol protection upper limit</source>
        <translation>电压保护范围上限</translation>
    </message>
    <message>
        <source>The upper limit of the voltage range allowed on the AC side can be +10, +15, +20, or +30.</source>
        <translation type="vanished">交流侧所允许的电压变化范围的上限，可供选择为+10、+15、+20、+30。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1157"/>
        <location filename="../win.cpp" line="4899"/>
        <source>Vol protection lower limit</source>
        <translation>电压保护范围下限</translation>
    </message>
    <message>
        <source>The lower limit of the voltage variation range allowed on the AC side can be -10, -15, -20, or -30.</source>
        <translation type="vanished">交流侧所允许的电压变化范围的下限，可供选择为-10、-15、-20、-30。</translation>
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
        <translation>禁止</translation>
    </message>
    <message>
        <source>This is the high voltage crossing (HVRT) Enable, enable the device will not stop because of a short period of high voltage, the option is to Enable, prohibit, (note: this is generally used in large grid-connected power stations).</source>
        <translation type="vanished">这是高压穿越(HVRT)使能,使能后该设备不会因为短时间的高电压而停机,可供选择为允许(Enable)、禁止(prohibit)，(注：此项一般在大型并网电站使用)。</translation>
    </message>
    <message>
        <source>This is the low voltage crossing (LVRT) Enable, enable the device will not stop because of a short period of low voltage, the option is to Enable, prohibit, (note: this is generally used in large grid-connected power stations).</source>
        <translation type="vanished">这是低压穿越(LVRT)使能，使能后该设备不会因为短时间的低电压而停机,可供选择为允许(Enable)、禁止(prohibit) ，(注：此项一般在大型并网电站使用)。</translation>
    </message>
    <message>
        <source>Prevent islanding effect, When the detection of the island effect (in the photovoltaic grid-connected system, when the power failure occurs in the large power grid, the photovoltaic grid-connected inverter power generation and the local load on the low-voltage side of the grid if the power is just matched, it is easy to appear self-sufficient maintenance power state, resulting in the &apos;island&apos; phenomenon, thereby endangering the safety of maintenance personnel), the inverter automatically shut down, and the option is allowed Enable, prohibit, (Note: this is generally used in large grid-connected power stations).</source>
        <translation type="vanished">防止孤岛效应，当检测出现孤岛效应(在光伏并网系统中,当大电网出现停电事故时,光伏并网逆变器发电与电网低压侧本地负载如果刚好出现功率相匹配时,容易出现自给自足的维持发电状态,从而出现&quot;&quot;孤岛&quot;&quot;现象,从而危及检修人员安全)时,让逆变器自动停机,可供选择为允许(Enable)、禁止(prohibit) ，(注：此项一般在大型并网电站使用)。</translation>
    </message>
    <message>
        <source>Insulation detection Enable, insulation resistance greater than 33KΩ to be able to operate normally, less than 33KΩ can not start, and to alarm, the default prohibition, the choice is to Enable, prohibit, (Note: this is generally used in large grid-connected power stations).</source>
        <translation type="vanished">绝缘检测使能，绝缘电阻大于33KΩ要能正常起机运行，小于33KΩ不能起机，并且要告警，默认禁止,可供选择为允许(Enable)、禁止(prohibit) ，(注：此项一般在大型并网电站使用)。</translation>
    </message>
    <message>
        <source>When the frequency of the power grid deviates from the rated value, the power grid frequency is maintained stable by controlling the increase or decrease of the active power, which can be selected to Enable, prohibit, (Note: this is generally used in large grid-connected power stations).</source>
        <translation type="vanished">一次调频使能,电网的频率偏离额定值时，通过控制有功功率的增减使电网频率维持稳定，可供选择为允许(Enable)、禁止(prohibit) ，(注：此项一般在大型并网电站使用)。</translation>
    </message>
    <message>
        <source>Moment of inertia Enable, can be selected to Enable, prohibit, (Note: this is generally used in large grid-connected power stations).</source>
        <translation type="vanished">转动惯量使能，可供选择为允许(Enable)、禁止(prohibit) ，(注：此项一般在大型并网电站使用)。</translation>
    </message>
    <message>
        <source>Constant voltage parallel Enable, you can choose to Enable, prohibit, (Note: this setting is used in constant voltage parallel mode).</source>
        <translation type="vanished">恒压并机使能,可供选择为允许(Enable)、禁止(prohibit)，(注：此项设置在恒压并机模式下使用)。</translation>
    </message>
    <message>
        <source>The rated capacity of PCS is subject to the ex-factory value and cannot be changed.</source>
        <translation type="vanished">PCS的额定容量，以出厂值为准，不可更改。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4990"/>
        <source>Output Fre grade</source>
        <translation>输出频率等级</translation>
    </message>
    <message>
        <source>Set the output frequency level, the default is 50Hz, generally 50Hz or 60Hz, can be fine-tuned according to the project.</source>
        <translation type="vanished">设置输出频率的等级，默认50Hz，一般为50Hz或60Hz，可根据项目地微调。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4999"/>
        <source>Output vol level</source>
        <translation>输出电压等级</translation>
    </message>
    <message>
        <source>The voltage level is changed according to the actual local power grid voltage. The voltage level is subject to delivery. If you need to change it, contact customer service for confirmation.</source>
        <translation type="vanished">电压等级根据当地实际电网电压更改，以出厂为准，如需更改，请联系客服确认。</translation>
    </message>
    <message>
        <source>Converter side vol level</source>
        <translation type="vanished">逆变电压等级</translation>
    </message>
    <message>
        <source>The inverter voltage level is the voltage level of the inverter, which should be set according to the transformer nameplate, subject to the factory default value, and cannot be changed at will. If you need to change, please contact customer service to confirm.</source>
        <translation type="vanished">逆变电压等级是逆变器逆变出来的电压等级，要根据变压器铭牌来设置，以出厂默认值为准，不可随意更改，如需更改，请联系客服确认。</translation>
    </message>
    <message>
        <source>Non adjustable</source>
        <translation type="vanished">不可调节</translation>
    </message>
    <message>
        <source>Output reactive mode, the default is not adjustable, can be selected as power factor (Pf), reactive power (Q), Non adjustable.</source>
        <translation type="vanished">输出无功方式，默认不可调节，可供选择为功率因数(Pf)、无功功率(Q)、不可调节(Non adjustable)。</translation>
    </message>
    <message>
        <source>Non countercurrent</source>
        <translation type="vanished">不可逆流</translation>
    </message>
    <message>
        <source>Set the grid-connected mode of the inverter, which can be countercurrent, that is, DC can be converted into AC power and then incorporated into the power grid; Irreversible means that the current on the DC side does not flow to the grid. The default value can be Countercurrent. The options can be countercurrent or Non countercurrent. With the local grid qualification, it can be changed to &apos;countercurrent&apos;; When using Prevent countercurrent mode, you can change to &apos;countercurrent&apos;.</source>
        <translation type="vanished">设置逆变器的并网方式，可逆流即直流转换成交流电后可以并入电网；不可逆则是直流侧的电流不会流向电网。默认可逆流，可供选择为可逆流(Countercurrent)、不可逆流(Non countercurrent)；具备当地并网资质时，可改为‘可逆流’；使用系统防逆流模式时，可改为‘逆流’。</translation>
    </message>
    <message>
        <source>Primary frequency modulation dead zone, in order to prevent unnecessary action of the switch when the frequency difference of the grid changes in a small range, (Note: This is generally used in large grid-connected power stations).</source>
        <translation type="vanished">一次调频死区,为了防止在电网频差小范围变化时调门不必要的动作而设置的频差，(注：此项一般在大型并网电站使用)。</translation>
    </message>
    <message>
        <source>This can set the active power frequency modulation coefficient, (Note: this is generally used in large grid-connected power stations).</source>
        <translation type="vanished">此项可以设置有功调频系数，(注：此项一般在大型并网电站使用)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5065"/>
        <source>Grid restoration time: reserved function, setting invalid.</source>
        <translation>电网恢复并网时间：预留功能，设置无效。</translation>
    </message>
    <message>
        <source>Enable the power network expansion. The options are Enable and Disable.</source>
        <translation type="vanished">电网扩容使能,当负载在短时间内所需功率大于电网容量时，可暂时从电池辅助供电以达到功率要求，可供选择为使能(Enable)、禁止(Disable)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5083"/>
        <source>Number of modules for PCS, default 1(invalid setting).</source>
        <translation>PCS的模块数量，默认值1(无效设置)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5091"/>
        <source>restore</source>
        <translation>恢复出厂</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5092"/>
        <source>Restore the factory default Settings.</source>
        <translation>恢复出厂时的默认设置。</translation>
    </message>
    <message>
        <source>Backup Settings</source>
        <translation type="vanished">设置备份</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5100"/>
        <source>Backup Set Parameters</source>
        <translation>备份设置参数</translation>
    </message>
    <message>
        <source>Backup
Settings</source>
        <translation type="vanished">设置备份</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5101"/>
        <source>Backup setting parameters: Backup setting parameters refers to backing up the parameters set on the current device so that the backup parameter Settings can be restored when needed.</source>
        <translation>备份设置参数：备份设置参数是指将当前设备设置的参数进行备份，以便在需要时可以恢复到这些备份的参数设置。 </translation>
    </message>
    <message>
        <source>Restore Backup</source>
        <translation type="vanished">恢复备份</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5109"/>
        <source>Restore Backup Set Parameters</source>
        <translation>恢复备份设置参数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5109"/>
        <source>Restore
Backup</source>
        <translation>恢复备份</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5110"/>
        <source>Restore backup setting parameters: Restore backup setting parameters means to restore the device to the last backup setting parameters and restart the device.</source>
        <translation>恢复备份设置参数：恢复备份设置参数是指将设备恢复到上一次备份好的设置参数，并重新启动设备。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5118"/>
        <source>Clear</source>
        <translation>清除</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5119"/>
        <source>Clear previous recorded data and operation data of the system.</source>
        <translation>清除系统此前的记录数据及操作数据。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5128"/>
        <source>Normally closed circuit (NC) or normally open circuit (NO) according to field Settings.</source>
        <translation>根据现场设置为常闭电路(NC)或常开电路（NO）。</translation>
    </message>
    <message>
        <source>When the dry contact is enabled and an abnormal signal is received, the device performs the selected action.</source>
        <translation type="vanished">当干接点使能后，收到异常信号时，设备将会执行此项所选的动作。</translation>
    </message>
    <message>
        <source>DI_1_Enable</source>
        <translation type="vanished">输入干接点1使能项</translation>
    </message>
    <message>
        <source>Enter dry contact 1. If Enable is selected, the Action is triggered when the dry contact detects that NO/NC is not set. If Disable is selected, the dry contact does not take any action when it detects that NO/NC is not set.</source>
        <translation type="vanished">输入干接点1，如果选择使能，当干接点检测到不是设置的NO/NC时，会触发Action的动作；如果选择禁止，当干接点检测到不是设置的NO/NC时，不做任何动作。</translation>
    </message>
    <message>
        <source>DI_2_Enable</source>
        <translation type="vanished">输入干接点2使能项</translation>
    </message>
    <message>
        <source>Enter dry contact 2. If Enable is selected, the Action is triggered when the dry contact detects that NO/NC is not set. If Disable is selected, the dry contact does not take any action when it detects that NO/NC is not set.</source>
        <translation type="vanished">输入干接点2，如果选择使能，当干接点检测到不是设置的NO/NC时，会触发Action的动作；如果选择禁止，当干接点检测到不是设置的NO/NC时，不做任何动作。</translation>
    </message>
    <message>
        <source>DI_3_Enable</source>
        <translation type="vanished">输入干接点3使能项</translation>
    </message>
    <message>
        <source>Enter dry contact 3. If Enable is selected, the Action is triggered when the dry contact detects that NO/NC is not set. If Disable is selected, the dry contact does not take any action when it detects that NO/NC is not set.</source>
        <translation type="vanished">输入干接点3，如果选择使能，当干接点检测到不是设置的NO/NC时，会触发Action的动作；如果选择禁止，当干接点检测到不是设置的NO/NC时，不做任何动作。</translation>
    </message>
    <message>
        <source>DI_4_Enable</source>
        <translation type="vanished">输入干接点4使能项</translation>
    </message>
    <message>
        <source>Enter dry contact 4. If Enable is selected, the Action is triggered when the dry contact detects that NO/NC is not set. If Disable is selected, the dry contact does not take any action when it detects that NO/NC is not set.</source>
        <translation type="vanished">输入干接点4，如果选择使能，当干接点检测到不是设置的NO/NC时，会触发Action的动作；如果选择禁止，当干接点检测到不是设置的NO/NC时，不做任何动作。</translation>
    </message>
    <message>
        <source>DI_5_Enable</source>
        <translation type="vanished">输入干接点5使能项</translation>
    </message>
    <message>
        <source>Enter dry contact 5. If Enable is selected, the Action is triggered when the dry contact detects that NO/NC is not set. If Disable is selected, the dry contact does not take any action when it detects that NO/NC is not set.</source>
        <translation type="vanished">输入干接点5，如果选择使能，当干接点检测到不是设置的NO/NC时，会触发Action的动作；如果选择禁止，当干接点检测到不是设置的NO/NC时，不做任何动作。</translation>
    </message>
    <message>
        <source>DI_6_Enable</source>
        <translation type="vanished">输入干接点6使能项</translation>
    </message>
    <message>
        <source>Enter dry contact 6. If Enable is selected, the Action is triggered when the dry contact detects that NO/NC is not set. If Disable is selected, the dry contact does not take any action when it detects that NO/NC is not set.</source>
        <translation type="vanished">输入干接点6，如果选择使能，当干接点检测到不是设置的NO/NC时，会触发Action的动作；如果选择禁止，当干接点检测到不是设置的NO/NC时，不做任何动作。</translation>
    </message>
    <message>
        <source>DO_1_Enable</source>
        <translation type="vanished">输出干接点1使能项</translation>
    </message>
    <message>
        <source>Output dry contact 1. If Enable is selected, the Action is triggered when the dry contact detects that NO/NC is not set. If Disable is selected, the dry contact does not take any action when it detects that NO/NC is not set.</source>
        <translation type="vanished">输出干接点1，如果选择使能，当干接点检测到不是设置的NO/NC时，会触发Action的动作；如果选择禁止，当干接点检测到不是设置的NO/NC时，不做任何动作。</translation>
    </message>
    <message>
        <source>DO_2_Enable</source>
        <translation type="vanished">输出干接点2使能项</translation>
    </message>
    <message>
        <source>Output dry contact 2. If Enable is selected, the Action is triggered when the dry contact detects that NO/NC is not set. If Disable is selected, the dry contact does not take any action when it detects that NO/NC is not set.</source>
        <translation type="vanished">输出干接点2，如果选择使能，当干接点检测到不是设置的NO/NC时，会触发Action的动作；如果选择禁止，当干接点检测到不是设置的NO/NC时，不做任何动作。</translation>
    </message>
    <message>
        <source>DO_3_Enable</source>
        <translation type="vanished">输出干接点3使能项</translation>
    </message>
    <message>
        <source>Output dry contact 3. If Enable is selected, the Action is triggered when the dry contact detects that NO/NC is not set. If Disable is selected, the dry contact does not take any action when it detects that NO/NC is not set.</source>
        <translation type="vanished">输出干接点3，如果选择使能，当干接点检测到不是设置的NO/NC时，会触发Action的动作；如果选择禁止，当干接点检测到不是设置的NO/NC时，不做任何动作。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5187"/>
        <source>DI_1_NC_O</source>
        <translation>输入干接点1常闭/常开项</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5195"/>
        <source>DI_2_NC_O</source>
        <translation>输入干接点2常闭/常开项</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5203"/>
        <source>DI_3_NC_O</source>
        <translation>输入干接点3常闭/常开项</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5211"/>
        <source>DI_4_NC_O</source>
        <translation>输入干接点4常闭/常开项</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5219"/>
        <source>DI_5_NC_O</source>
        <translation>输入干接点5常闭/常开项</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5227"/>
        <source>DI_6_NC_O</source>
        <translation>输入干接点6常闭/常开项</translation>
    </message>
    <message>
        <source>DO_1_NC_O</source>
        <translation type="vanished">输出干接点1常闭/常开项</translation>
    </message>
    <message>
        <source>DO_2_NC_O</source>
        <translation type="vanished">输出干接点2常闭/常开项</translation>
    </message>
    <message>
        <source>DO_3_NC_O</source>
        <translation type="vanished">输出干接点3常闭/常开项</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5235"/>
        <source>DI_1_Action</source>
        <translation>输入干接点1响应动作</translation>
    </message>
    <message>
        <location filename="../win.ui" line="1629"/>
        <location filename="../win.ui" line="1673"/>
        <location filename="../win.ui" line="1717"/>
        <location filename="../win.cpp" line="5243"/>
        <location filename="../win.cpp" line="5251"/>
        <location filename="../win.cpp" line="5259"/>
        <source>Prompt</source>
        <translation>提示</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5243"/>
        <source>DI_2_Action</source>
        <translation>输入干接点2响应动作</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5251"/>
        <source>DI_3_Action</source>
        <translation>输入干接点3响应动作</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5259"/>
        <source>DI_4_Action</source>
        <translation>输入干接点4响应动作</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5267"/>
        <source>DI_5_Action</source>
        <translation>输入干接点5响应动作</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5275"/>
        <source>DI_6_Action</source>
        <translation>输入干接点6响应动作</translation>
    </message>
    <message>
        <source>DO_1_Action</source>
        <translation type="vanished">输出干接点1响应动作</translation>
    </message>
    <message>
        <source>DO_2_Action</source>
        <translation type="vanished">输出干接点2响应动作</translation>
    </message>
    <message>
        <source>DO_3_Action</source>
        <translation type="vanished">输出干接点3响应动作</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5289"/>
        <location filename="../win.cpp" line="5298"/>
        <location filename="../win.cpp" line="5307"/>
        <location filename="../win.cpp" line="5325"/>
        <source>Standby</source>
        <translation>待机</translation>
    </message>
    <message>
        <source>DOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="vanished">DOD保护，触发DOD保护时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)、0功率待机（0 power standby）。</translation>
    </message>
    <message>
        <source>DOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action, Power down, Standby, Shut down.</source>
        <translation type="vanished">DOD保护，触发DOD保护时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)。</translation>
    </message>
    <message>
        <source>The action performed when the charge ban is triggered;Optional function: NO action, Power down, Standby, Shut down.</source>
        <translation type="vanished">触发禁充时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)。</translation>
    </message>
    <message>
        <source>The action to be performed when a ban is triggered.The optional functions are NO action, Power down, Standby, Shut down.</source>
        <translation type="vanished">触发禁放时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5316"/>
        <source>NO action</source>
        <translation>不动作</translation>
    </message>
    <message>
        <source>Action to be performed when a BMS prompt is triggered.The optional functions are NO action, Power down, Standby, Shut down.</source>
        <translation type="vanished">触发BMS提示时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)。</translation>
    </message>
    <message>
        <source>Action when a BMS alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down.</source>
        <translation type="vanished">触发BMS告警时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)。</translation>
    </message>
    <message>
        <source>Action that is performed when a BMS fault is triggered.The optional functions are NO action, Power down, Standby, Shut down.</source>
        <translation type="vanished">触发BMS故障时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)。</translation>
    </message>
    <message>
        <source>BMS warning CP</source>
        <translation type="vanished">BMS 提示 充电功率</translation>
    </message>
    <message>
        <source>The charge power when the BMS prompt is triggered.</source>
        <translation type="vanished">触发BMS提示时的充电功率。</translation>
    </message>
    <message>
        <source>BMS alarm CP</source>
        <translation type="vanished">BMS 告警 充电功率</translation>
    </message>
    <message>
        <source>Charge power that is executed when a BMS alarm is triggered.</source>
        <translation type="vanished">触发BMS告警时执行的的充电功率。</translation>
    </message>
    <message>
        <source>BMS fualt CP</source>
        <translation type="vanished">BMS 故障 充电功率</translation>
    </message>
    <message>
        <source>Charging power when a BMS fault is triggered.</source>
        <translation type="vanished">触发BMS故障时的充电功率。</translation>
    </message>
    <message>
        <source>BMS warning DP</source>
        <translation type="vanished">BMS 提示 放电功率</translation>
    </message>
    <message>
        <source>Discharge power when the BMS prompt is triggered.</source>
        <translation type="vanished">触发BMS提示时的放电功率。</translation>
    </message>
    <message>
        <source>BMS alarm DP</source>
        <translation type="vanished">BMS 告警 放电功率</translation>
    </message>
    <message>
        <source>Discharge power when a BMS alarm is triggered.</source>
        <translation type="vanished">触发BMS告警时的放电功率。</translation>
    </message>
    <message>
        <source>BMS fualt DP</source>
        <translation type="vanished">BMS 故障 放电功率</translation>
    </message>
    <message>
        <source>Discharge power when triggering a BMS fault.</source>
        <translation type="vanished">触发BMS故障时的放电功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5398"/>
        <source>It is used for internal debugging only.</source>
        <translation>仅提供内部调试使用。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5429"/>
        <source>Debug variable 1 addr</source>
        <translation>调试地址变量1</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5437"/>
        <source>Debug variable 2 addr</source>
        <translation>调试地址变量2</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5445"/>
        <source>Debug variable 3 addr</source>
        <translation>调试地址变量3</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5453"/>
        <source>Debug memery var 1</source>
        <translation>调试内存变量1</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5461"/>
        <source>Debug memery var 2</source>
        <translation>调试内存变量2</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5469"/>
        <source>Debug memery var 3</source>
        <translation>调试内存变量3</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5477"/>
        <source>Input Vol revise</source>
        <translation>输入电压系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5485"/>
        <source>Input Cur revise</source>
        <translation>输入电流系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5493"/>
        <source>1.5 Voltage revise</source>
        <translation>1.5V电压系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5501"/>
        <source>Bus Vol revise</source>
        <translation>母线电压系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5509"/>
        <source>Grid A AB Vol revise</source>
        <translation>电网A相电压系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5517"/>
        <source>Grid B BC Vol revise</source>
        <translation>电网B相电压系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5525"/>
        <source>Grid C CA Vol revise</source>
        <translation>电网C相电压系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5533"/>
        <source>Output A Cur revise</source>
        <translation>输出A相电流系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5541"/>
        <source>Output B Cur revise</source>
        <translation>输出B相电流系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5549"/>
        <source>Output C Cur revise</source>
        <translation>输出C相电流系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5557"/>
        <source>INV A Vol revise</source>
        <translation>逆变A相电压系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5565"/>
        <source>INV B Vol revise</source>
        <translation>逆变B相电压系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5573"/>
        <source>INV C Vol revise</source>
        <translation>逆变C相电压系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5581"/>
        <source>INV A ind Cur revise</source>
        <translation>逆变A相电感电流系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5589"/>
        <source>INV B ind Cur revise</source>
        <translation>逆变B相电感电流系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5597"/>
        <source>INV_C_ind_Cur_revise</source>
        <translation>逆变C相电感电流系数</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5693"/>
        <source>static</source>
        <translation>静态</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5693"/>
        <source>If this parameter is selected, static IP addresses are used.</source>
        <translation>如果选择此项，表示使用静态的IP地址。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5716"/>
        <source>This is an automatic IP acquisition, currently not supported.</source>
        <translation>这是自动获取IP，暂不支持。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5716"/>
        <source>dhcp</source>
        <translation>自动获取</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5740"/>
        <source>Call in test data (for internal testing personnel only).</source>
        <translation>调入测试数据(仅供内部测试人员使用)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5748"/>
        <source>Time</source>
        <translation>时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5748"/>
        <source>Click here to modify the time displayed on the HMI.</source>
        <translation>点击此处，可以对HMI显示的时间进行修改。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3500"/>
        <source>Local</source>
        <translation>本地</translation>
    </message>
    <message>
        <source>Closed</source>
        <translation type="vanished">闭合</translation>
    </message>
    <message>
        <source>There are two states for a DC circuit breaker: open, closed.</source>
        <translation type="vanished">直流断路器有两种状态:断开、闭合。</translation>
    </message>
    <message>
        <source>The DC contactor has two states: open and closed. After the soft start of the DC side is completed, the DC contactor closes. When the DC side of the battery is disconnected and the voltage of the DC bus drops to a certain level, the DC contactor opens.</source>
        <translation type="vanished">直流接触器有两种状态:断开，闭合;当直流侧软启完成后，直流接触器闭合;当电池直流侧断开，直流母线电压下降到一定电压，直流接触器断开。</translation>
    </message>
    <message>
        <source>The output contactor has two states: Open, Closed. The output contactor closes after the soft start on the inv. side is completed. The output contactor opens when the converter is shut down.</source>
        <translation type="vanished">输出接触器有两种状态:断开、闭合;当逆变侧软启完成后，输出接触器闭合;当变流器关机时，输出接触器断开。</translation>
    </message>
    <message>
        <source>The output circuit breaker has three states: open, closed. It can only be manually opened and closed. If there is an overcurrent in the output circuit breaker, it will trip.</source>
        <translation type="vanished">输出断路器有两种状态:断开、闭合;只能手动断开，如果输出断路器过流，输出断路器会发生脱扣。</translation>
    </message>
    <message>
        <source>The power grid circuit breaker has three states: Break, Close; The power grid circuit breaker can only be manually disconnected. If the power grid circuit breaker overflows, the power grid circuit breaker may trip.</source>
        <translation type="vanished">电网断路器有两种状态:断开、闭合;只能手动断开，如果电网断路器过流，电网断路器会发生脱扣。</translation>
    </message>
    <message>
        <source>There are two states for the maintenance bypass circuit breaker: Open, Closed. This circuit breaker is only used for machine maintenance. If maintenance is required, please contact the maintenance personnel.</source>
        <translation type="vanished">维修旁路断路器有两种状态:断开、闭合;此断路器仅用于机器维护，如需维护，请联系维护人员。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3294"/>
        <source>Disabled</source>
        <translation>禁止</translation>
    </message>
    <message>
        <source>The converter has two states: enabled,disabled. The converter is enabled when the self-check is successful. Otherwise, the converter is disabled.</source>
        <translation type="vanished">变流器有两种状态:使能、禁止;机器自检正常时，变流器使能;否则变流器禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3304"/>
        <source>There are three states for DC soft start: Not starting, Soft starting, and Complete. Soft start refers to the process in which the converter charges the busbar with the battery during startup, causing the busbar voltage to rise close to the battery voltage.</source>
        <translation>直流软启动有三种状态:未启动，软启中，软启完成;软启动是指变流器在启动时，通过控制电池给母线充电使母线的电压上升到接近电池电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3313"/>
        <source>Converter states include: OFF, AC Soft Start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Derating grid-on, Standby, Grid-OFF Charge, Constant Voltage Discharge and Constant Voltage Charge.</source>
        <translation>变流器状态包括：关闭、交流软启动、并网充电、并网放电、离网放电、降额并网、待机、离网充电、恒压放电、恒压充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3322"/>
        <source>There are three types of reactive power regulation: Disable,PF regulation, and  regulation.</source>
        <translation>无功调节有三种:禁止、功率因数调节、无功功率调节。</translation>
    </message>
    <message>
        <source>LVRT states : enabled , disabled.</source>
        <translation type="vanished">低电压穿越状态:使能、禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3340"/>
        <source>Signal to start the diesel generator, start the diesel generator when enabled, stop the diesel generator when disabled.</source>
        <translation>启动柴发的信号，使能时启动柴发，禁止是停止柴发。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3349"/>
        <source>Dry contact 2 is output.</source>
        <translation>输出干接点2.</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3358"/>
        <source>Dry contact 3 is output.</source>
        <translation>输出干接点3.</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3367"/>
        <source>Dry contact EPO：Enable，Disable.</source>
        <translation>干接点EPO:使能，禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3376"/>
        <source>Dry contact Shutdown：Enable，Disable.</source>
        <translation>干接点关机：使能，禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3384"/>
        <source>Access signal</source>
        <translation>门禁信号</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3385"/>
        <source>Access signal:Enable, Disable.</source>
        <translation>门禁信号：使能，禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3394"/>
        <source>Full power signal:Enable, Disable.</source>
        <translation>满功率信号：使能，禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3403"/>
        <source>Smoke alarm signal:Enable, Disable.</source>
        <translation>烟雾报警信号：使能，禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1882"/>
        <location filename="../win.cpp" line="3411"/>
        <source>Fire fighting signal</source>
        <translation>消防信号</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3412"/>
        <source>Fire fighting signal:Enable, Disable.</source>
        <translation>消防信号：使能，禁止。</translation>
    </message>
    <message>
        <source>Master_00</source>
        <translation type="vanished">主机_00</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3519"/>
        <source>Parallel</source>
        <translation>并机</translation>
    </message>
    <message>
        <location filename="../win.ui" line="5019"/>
        <location filename="../win.cpp" line="3285"/>
        <source>Maintenance Bypass Breaker</source>
        <translation>维修旁路</translation>
    </message>
    <message>
        <source>Maintenance bypass circuit breaker has two states: Break, Close; This circuit breaker is only used for machine maintenance, if necessary, please contact the maintenance personnel.</source>
        <translation type="vanished">维修旁路断路器有两种状态：断开(Break)，闭合(Close)；此断路器仅用于机器维护，如有需要，请联系维护人员。</translation>
    </message>
    <message>
        <source>The converter can be enabled in two states: Enable and Disable. When the internal self-test of the machine is no problem, the converter is enabled; Otherwise the converter is prohibited.</source>
        <translation type="vanished">变流器使能有两种状态：使能(Enable)、禁止(Disable)；当机器内部自检没有问题时，变流器使能；否则变流器禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3303"/>
        <source>Not starting</source>
        <translation>未启动</translation>
    </message>
    <message>
        <source>The DC Soft boot has three states: Soft starting, complete, and Not starting. Soft start means that when the converter is started, it gradually accelerates or decelerates the device to the normal operating state by controlling the change of current or voltage, so as to reduce the current shock and voltage peak in the circuit, protect the circuit components and reduce the mechanical damage of the device. Soft start can increase device life, reduce energy consumption, and improve system efficiency.</source>
        <translation type="vanished">直流软启动有三种状态：软启中(Soft starting)，软启完成(complete)，未启动(Not starting)；软启动是指变流器在启动时，通过控制电流或电压的变化使设备逐渐加速或减速到正常运行状态，以减少电路中的电流冲击和电压峰值，保护电路元器件并减少设备的机械损伤。软启动可以增加设备的寿命，减少能耗，提高系统效率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3312"/>
        <location filename="../win.cpp" line="5235"/>
        <location filename="../win.cpp" line="5267"/>
        <location filename="../win.cpp" line="5275"/>
        <location filename="../win.cpp" line="5334"/>
        <source>Shut down</source>
        <translation>关机</translation>
    </message>
    <message>
        <source>There are eight converter states:Shut down, Soft start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Drop and Connected,Standby, Grid-OFF Charge.</source>
        <translation type="vanished">变流器状态有八种：关机(Shut down)，软启动(Soft start)，并网充电(Grid-ON Charge)，并网放电(Grid-ON Discharge)，离网放电(Grid-OFF Discharge)，降额并网(Drop and Connected)，待机(Standby)，离网充电(Grid-OFF Charge)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3321"/>
        <source>Reactive Power Regulation</source>
        <translation>无功调节</translation>
    </message>
    <message>
        <source>There are three types of reactive power regulation: Disable, Pf regulation, and Q regulation.</source>
        <translation type="vanished">无功调节有三种：禁止(Disable)、功率因数调节(Pf regulation)、无功功率调节(Q regulation)。</translation>
    </message>
    <message>
        <source>This is the current state of low voltage crossing (LVRT). Low voltage crossing refers to the ability to withstand a certain limit of low voltage of the grid within a certain period of time without exiting the operation. There are two states here, namely Non and LVRT.</source>
        <translation type="vanished">这是当前低电压穿越(LVRT)的状态，低电压穿越是在确定的时间内承受一定限值的电网低电压而不退出运行的能力，这里有两种状态，分别为无(Non)、有(LVRT)。</translation>
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
        <translation>使能</translation>
    </message>
    <message>
        <source>This is the status of the current chai signal, output dry contact 1, there are Enable and Disable two states, here is the most real physical hardware status.</source>
        <translation type="vanished">这是当前柴发信号的状态，输出干接点1，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态。</translation>
    </message>
    <message>
        <source>This bit is reserved and has no effect. Dry contact 2 is output. The status of dry contact 2 is Enable(Enable) or Disable(Disable).</source>
        <translation type="vanished">这是保留位，无作用，输出干接点2，有使能(Enable)、禁止(Disable)两种状态。</translation>
    </message>
    <message>
        <source>Reserve2</source>
        <translation type="vanished">保留位2</translation>
    </message>
    <message>
        <source>This bit is reserved and has no effect. Dry contact 2 is output. The status of dry contact 3 is Enable(Enable) or Disable(Disable)</source>
        <translation type="vanished">这是保留位，无作用，输出干接点3，有使能(Enable)、禁止(Disable)两种状态</translation>
    </message>
    <message>
        <source>EPO_Cont signal1</source>
        <translation type="vanished">EPO节点信号1</translation>
    </message>
    <message>
        <source>This is signal 1 of the EPO node. Enter dry contact 1, that is, dry contact signal 1 of external shutdown. There are two states: Enable and Disable.</source>
        <translation type="vanished">这是EPO节点信号1，输入干接点1，即外部停机干接点信号1，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态。</translation>
    </message>
    <message>
        <source>EPO_Cont signal2</source>
        <translation type="vanished">EPO节点信号2</translation>
    </message>
    <message>
        <source>This is signal 2 of the EPO node. Enter dry contact 2, that is, dry contact signal 2 of the external shutdown. There are two states: Enable and Disable.</source>
        <translation type="vanished">这是EPO节点信号2，输入干接点2，即外部停机干接点信号2，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态。</translation>
    </message>
    <message>
        <source>Access_signal</source>
        <translation type="vanished">门禁信号</translation>
    </message>
    <message>
        <source>This is the access signal. Enter dry contact 3. The status is Enable or Disable. The actual physical hardware status is obtained here.</source>
        <translation type="vanished">这是门禁信号，输入干接点3，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态。</translation>
    </message>
    <message>
        <source>Full_P_signal</source>
        <translation type="vanished">满功率信号</translation>
    </message>
    <message>
        <source>This is a full power signal, the input dry contact 4 has two states of Enable and Disable, and what is obtained here is the most real physical hardware state.</source>
        <translation type="vanished">这是满功率信号，输入干接点4，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态。</translation>
    </message>
    <message>
        <source>This isa smoke alarm signal. Enter dry contact 5. The status is Enable or Disable. The actual physical hardware status is obtained here.</source>
        <translation type="vanished">这是烟雾告警信号，输入干接点5，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态。</translation>
    </message>
    <message>
        <source>Hight temp signal</source>
        <translation type="vanished">高温信号</translation>
    </message>
    <message>
        <source>This isa high temperature signal. Input dry contact 6. Two states are available: Enable and Disable.</source>
        <translation type="vanished">这是高温信号，输入干接点6，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4328"/>
        <source>PCS voltage(AB)</source>
        <translation>PCS 电压(AB)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4338"/>
        <source>PCS voltage(BC)</source>
        <translation>PCS 电压(BC)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4348"/>
        <source>PCS voltage(CA)</source>
        <translation>PCS 电压(CA)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4358"/>
        <source>PCS current(A)</source>
        <translation>PCS 电流(A)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4368"/>
        <source>PCS current(B)</source>
        <translation>PCS 电流(B)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4378"/>
        <source>PCS current(C)</source>
        <translation>PCS 电流(C)</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4388"/>
        <source>PCS Active P.</source>
        <translation>PCS有功功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4393"/>
        <source>PCS Reactive P.</source>
        <translation>PCS无功功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4398"/>
        <source>PCS Parent P.</source>
        <translation>PCS视在功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4403"/>
        <source>PCS Pf</source>
        <translation>PCS功率因素</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4333"/>
        <location filename="../win.cpp" line="1171"/>
        <location filename="../win.cpp" line="2970"/>
        <source>Battery voltage</source>
        <translation>电池电压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4343"/>
        <location filename="../win.cpp" line="1171"/>
        <location filename="../win.cpp" line="2979"/>
        <source>Battery current</source>
        <translation>电池电流</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4353"/>
        <location filename="../win.cpp" line="1171"/>
        <location filename="../win.cpp" line="2988"/>
        <source>Battery power</source>
        <translation>电池功率</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4363"/>
        <location filename="../win.cpp" line="1172"/>
        <location filename="../win.cpp" line="2997"/>
        <source>Bus voltage</source>
        <translation>母线电压</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4373"/>
        <location filename="../win.cpp" line="1172"/>
        <location filename="../win.cpp" line="3006"/>
        <source>IGBT temperature</source>
        <translation>IGBT温度</translation>
    </message>
    <message>
        <location filename="../win.ui" line="4383"/>
        <location filename="../win.cpp" line="1173"/>
        <location filename="../win.cpp" line="3015"/>
        <source>Environment temperature</source>
        <translation>环境温度</translation>
    </message>
    <message>
        <source>Converter fault</source>
        <translation type="vanished">变流器故障</translation>
    </message>
    <message>
        <source>During soft startup of converter, inverter voltage RMS more then 1.2Vgrid or inverter voltage RMS less than 0.3Vgrid after 30s</source>
        <translation type="vanished">变流器开机软启过程中，30s后逆变电压有效值&gt;1.2Vgrid或逆变电压有效值&lt;0.3Vgrid</translation>
    </message>
    <message>
        <source>PCS shut down and Stop the soft startup</source>
        <translation type="vanished">PCS 停机，停止开机软启</translation>
    </message>
    <message>
        <source>Battery low voltage</source>
        <translation type="vanished">电池电压低</translation>
    </message>
    <message>
        <source>Warning</source>
        <translation type="vanished">告警</translation>
    </message>
    <message>
        <source>The DC input/output voltage is lower than the battery EOD voltage or less than 1.414 times the grid line voltage</source>
        <translation type="vanished">直流出入电压低于电池EOD电压或者小于1.414倍电网线电压</translation>
    </message>
    <message>
        <source>PCS shut down and the AC contactor is disconnected</source>
        <translation type="vanished">PCS 停机，交流接触器断开</translation>
    </message>
    <message>
        <source>Low battery power</source>
        <translation type="vanished">电池功率低</translation>
    </message>
    <message>
        <source>The battery voltage is lower than the EOD voltage value (applicable to BMS free battery systems to prevent voltage rebound)</source>
        <translation type="vanished">电池电压低于电池EOD电压值(适用无BMS电池系统，防止电压回升)</translation>
    </message>
    <message>
        <source>When the PCS is in discharge state, the machine stops (the charging process is not affected) and the AC contactor is disconnected</source>
        <translation type="vanished">处于放电状态时PCS停机(充电过程不受影响)，交流接触器断开</translation>
    </message>
    <message>
        <source>Recoverable, The alarm is cleared when the charging time of PCS is longer than 5 minutes</source>
        <translation type="vanished">可恢复，PCS充电时间大于5min后，告警消除</translation>
    </message>
    <message>
        <source>Serious failure</source>
        <translation type="vanished">严重故障</translation>
    </message>
    <message>
        <source>PCS shut down, the AC contactor is disconnected, and the DC circuit breaker is tripped</source>
        <translation type="vanished">PCS 停机，交流接触器断开，直流断路器脱扣</translation>
    </message>
    <message>
        <source>Unrecoverable</source>
        <translation type="vanished">不可恢复</translation>
    </message>
    <message>
        <source>The DC bus voltage is less than 200V, the DC current is more than 50A, and the judgment time is 200us</source>
        <translation type="vanished">直流母线电压低于200V，直流电流大于50A，判断时间为200us</translation>
    </message>
    <message>
        <source>The output contactor is open</source>
        <translation type="vanished">输出接触器开路</translation>
    </message>
    <message>
        <source>When PCS is running, the auxiliary contact signal of AC contactor is in the disconnected state</source>
        <translation type="vanished">PCS运行状态下，交流接触器的辅助触点信号为断开状态</translation>
    </message>
    <message>
        <source>Output contactor short circuit</source>
        <translation type="vanished">输出接触器短路</translation>
    </message>
    <message>
        <source>When PCS is shut down, the auxiliary contact signal of AC contactor is closed</source>
        <translation type="vanished">PCS停机状态下，交流接触器的辅助触点信号为闭合状态</translation>
    </message>
    <message>
        <source>The converter is overheated</source>
        <translation type="vanished">变流器过温</translation>
    </message>
    <message>
        <source>IGBT temperature exceeds 105℃ or reactor temperature exceeds 160℃</source>
        <translation type="vanished">IGBT温度超过105℃或电抗器温度超过160℃</translation>
    </message>
    <message>
        <source>IGBT overtemperature: derating operation (grid-connected); IGBT overtemperature: PCS shut down (off-grid), AC contactor is disconnected; Reactor overtemperature: PCS shut down and AC contactor is disconnected</source>
        <translation type="vanished">IGBT过温：降额运行(并网)；IGBT过温：PCS停机(离网)，交流接触器断开；电抗器过温：PCS 停机，交流接触器断开</translation>
    </message>
    <message>
        <source>Output over load</source>
        <translation type="vanished">输出过载</translation>
    </message>
    <message>
        <source>Off-grid load power &gt;110%Pn</source>
        <translation type="vanished">离网负载功率&gt;110%Pn</translation>
    </message>
    <message>
        <source>The positive and negative terminals of the battery are connected inversely fault</source>
        <translation type="vanished">电池接反故障</translation>
    </message>
    <message>
        <source>The DC input is reversed</source>
        <translation type="vanished">直流输入正负极性接反</translation>
    </message>
    <message>
        <source>The DC contactor is faulty</source>
        <translation type="vanished">DC接触器故障</translation>
    </message>
    <message>
        <source>When the driving signal is a closed signal, the pressure difference between the battery and the bus is greater than 50V;When the driving signal is off, the auxiliary contact signal is closed</source>
        <translation type="vanished">驱动信号为闭合信号条件下，电池和母线之间的压测&gt;50V；驱动信号为断开条件下，辅助触点信号为闭合状态</translation>
    </message>
    <message>
        <source>EMS communicate
fault</source>
        <translation type="vanished">EMS通信故障</translation>
    </message>
    <message>
        <source>The communication between PCS and EMS is lost, and the judgment time is 3 minutes</source>
        <translation type="vanished">PCS与EMS通信丢失，判断时间3min</translation>
    </message>
    <message>
        <source>Recoverable, the fault recovers automatically 30 seconds after it is rectified</source>
        <translation type="vanished">可恢复，故障消除后30s自动恢复</translation>
    </message>
    <message>
        <source>BMS communicate
fault</source>
        <translation type="vanished">BMS通信故障</translation>
    </message>
    <message>
        <source>Communication loss between PCS and BMS, judgment time 50s</source>
        <translation type="vanished">PCS与BMS通信丢失，判断时间50s</translation>
    </message>
    <message>
        <source>Converter phase loss fault</source>
        <translation type="vanished">变流器缺相故障</translation>
    </message>
    <message>
        <source>When the grid-connected power is greater than 50%, one or more lines of the three-phase circuit have no output power, and the judgment time is 10s</source>
        <translation type="vanished">并网功率大于50%条件下，三相电路出现一项或多项线路无输出功率，判断时间为10s</translation>
    </message>
    <message>
        <source>Grid overvoltage</source>
        <translation type="vanished">电网过压</translation>
    </message>
    <message>
        <source>If the power grid voltage exceeds the maximum allowable voltage (90% to 70% can be set), the judgment time is 1s</source>
        <translation type="vanished">电网电压超过最大允许电压(90%~70%可设定),判断时间1s</translation>
    </message>
    <message>
        <source>Grid undervoltage</source>
        <translation type="vanished">电网欠压</translation>
    </message>
    <message>
        <source>Grid reverse sequence</source>
        <translation type="vanished">电网反序</translation>
    </message>
    <message>
        <source>The three-phase phase sequence is reversed (the positive sequence mode value of the grid voltage is less than the negative sequence mode value), and the judgment time is 1s</source>
        <translation type="vanished">三相相序接反(电网电压正序模值小于负序模值)，判断时间为1s</translation>
    </message>
    <message>
        <source>Grid frequency anomaly</source>
        <translation type="vanished">电网频率异常</translation>
    </message>
    <message>
        <source>Grid frequency frequency beyond the allowable range of PCS (±2Hz can be set)</source>
        <translation type="vanished">电网频率超出PCS允许范围内(±2Hz可设定)</translation>
    </message>
    <message>
        <source>Converter shutter island protection</source>
        <translation type="vanished">变流器孤岛保护</translation>
    </message>
    <message>
        <source>Initiative shutter island protection mode, the power grid loses power, and the load matches the grid-connected power and phase Angle of the inverter</source>
        <translation type="vanished">主动孤岛保护模式下电网失电，且负载和逆变器并网功率和相角相匹配</translation>
    </message>
    <message>
        <source>Drive line fault</source>
        <translation type="vanished">驱动线故障</translation>
    </message>
    <message>
        <source>The driver cable port is loose</source>
        <translation type="vanished">驱动线端口松动</translation>
    </message>
    <message>
        <source>Lightning protection fault</source>
        <translation type="vanished">防雷故障</translation>
    </message>
    <message>
        <source>Surge arrester breakdown or leakage</source>
        <translation type="vanished">防雷器击穿或漏电</translation>
    </message>
    <message>
        <source>Insulation impedance anomaly</source>
        <translation type="vanished">绝缘阻抗异常</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2300"/>
        <source>Battery power-on: This function allows the BMS to send a command to close the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation>电池上电：该项可以给BMS下发闭合接触器的指令(注:仅部分BMS厂家支持该功能)。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2304"/>
        <source>Battery power-off: This function allows the BMS to send a command to open the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation>电池下电：该项可以给BMS下发断开接触器的指令(注:仅部分BMS厂家支持该功能)。</translation>
    </message>
    <message>
        <source>The output circuit breaker has two states: On, Off. It can only be manually opened and closed. If there is an overcurrent in the output circuit breaker, it will trip.</source>
        <translation type="vanished">输出断路器有两种状态:闭合、断开;只能手动断开，如果输出断路器过流，输出断路器会发生脱扣。</translation>
    </message>
    <message>
        <source>The power grid circuit breaker has two states: On, Off; The power grid circuit breaker can only be manually disconnected. If the power grid circuit breaker overflows, the power grid circuit breaker may trip.</source>
        <translation type="vanished">电网断路器有两种状态:闭合、断开;只能手动断开，如果电网断路器过流，电网断路器会发生脱扣。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3626"/>
        <source>When the specified SOC is reached, the diesel generator shuts down.</source>
        <translation>达到指定SOC时，柴油发电机关闭。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3634"/>
        <source>Genertor turn on SOC</source>
        <translation>发电机开启SOC</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3635"/>
        <source>When the specified SOC is reached, the diesel generator starts.</source>
        <translation>达到指定SOC时，柴油发电机开启。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3643"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation>柴发充电SOC</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3644"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation>柴发充电SOC：电网扩容模式下，当有柴发接入时，电池SOC低于此SOC会充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3653"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation>电网充电SOC：电网扩容模式下，柴发没有接入时，电池SOC低于此SOC会充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3671"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation>放电停止SOC：电网扩容模式下，电池SOC小于此SOC会停止放电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3680"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation>电网容量：电网扩容模式下运行接入最大的电网功率。</translation>
    </message>
    <message>
        <source>Genertor charge SOC</source>
        <translation type="vanished">发电机开启SOC</translation>
    </message>
    <message>
        <source>Diesel Generator Charging SOC: In the grid expansion mode, when the diesel generator is connected, if the battery&apos;s SOC is lower than this value, the battery will be charged.</source>
        <translation type="vanished">柴发充电SOC：电网扩容模式下，有柴发接入时，电池的SOC低于此值，电池会充电。</translation>
    </message>
    <message>
        <source>Grid Charging SOC: In the grid expansion mode, when the diesel generator is not connected, if the battery&apos;s SOC is lower than this value, the battery will be charged.</source>
        <translation type="vanished">电网充电SOC：电网扩容模式下，柴发没有接入时，电池的SOC低于此值，电池会充电。</translation>
    </message>
    <message>
        <source>Stop Charging SOC: When the current State of Charge (SOC) of the battery is higher than the preset value, the converter will stop charging. </source>
        <translation type="vanished">充电停止SOC:电池当前SOC高于预设值时，将停止充电。 </translation>
    </message>
    <message>
        <source>Stop Discharging SOC: When the current SOC of the battery is lower than the preset value, the converter will stop discharging. </source>
        <translation type="vanished">放电停止SOC:电池当前SOC低于预设值时，将停止放电。 </translation>
    </message>
    <message>
        <source>Grid Capacity: The maximum capacity of the converter&apos;s AC side input, which takes effect in the converter power supply mode.</source>
        <translation type="vanished">电网容量：变流器交流侧输入的最大容量，该参数在电网扩容模式下生效。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3692"/>
        <source>Start SOC: In UPS mode, when the battery SOC reaches that value, the converter starts charging.</source>
        <translation>启动SOC：在UPS模式下，电池SOC达到该值时，变流器开启充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3701"/>
        <source>Stop SOC: In UPS mode, when the battery SOC reaches that value, the converter stops charging.</source>
        <translation>停止SOC：在UPS模式下，电池SOC达到该值时，变流器停止充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3710"/>
        <source>Start cell voltage: In UPS mode, when the lowest voltage of a battery cell reaches that value, the converter starts charging.</source>
        <translation>启动单体电压：UPS模式下：电池单体最低电压达到该值时，变流器开启充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3719"/>
        <source>Stop cell voltage: In UPS mode, when the highest voltage of a battery cell reaches that value, the converter stops charging.</source>
        <translation>停止单体电压：UPS模式下：电池单体最高电压达到该值时，变流器停止充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3728"/>
        <source>Start total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter starts charging.</source>
        <translation>启动总压：在UPS模式下，电池总压达到该值时，变流器开启充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3737"/>
        <source>Stop total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter stops charging.</source>
        <translation>停止总压：在UPS模式下，电池总压达到该值时，变流器停止充电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3746"/>
        <source>Backup charging power: In UPS mode, the backup charging power of the converter when the battery starts charging.</source>
        <translation>后备充电功率：在UPS模式下，电池启动充电时，变流器的后备充电功率。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3755"/>
        <source>Monthly cycling date: On the same day of each month, a deep discharge and recharge will be performed.</source>
        <translation>月循环日期：每月的当日，会进行一次深度充放电。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3769"/>
        <source>The number of battery cells connected in series in the battery stack (based on a 2V unit).</source>
        <translation>电池堆串联单体的的数量（以2V为基准）。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3784"/>
        <source>Charging Current Limit: The maximum allowable current on the battery side to prevent overcurrent during charging. (Upper limit: 0.25C)</source>
        <translation>充电电流限制：电池侧允许的最大电流，防止充电过流（上限0.25C）。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3789"/>
        <source>Discharge Current Limit: The maximum allowable current on the battery side to prevent overcurrent during discharge. (Upper limit: 0.5C)</source>
        <translation>放电电流限制：电池侧允许的最大电流，防止放电过流（上限0.5C）。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3794"/>
        <source>Generator Shutdown Voltage: When the specified voltage is reached, the diesel generator will shut down.</source>
        <translation>发电机关闭电压：达到指定电压时，柴油发电机关闭。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3799"/>
        <source>Generator Start Voltage: When the specified voltage is reached, the diesel generator will start up.</source>
        <translation>发电机开启电压：达到指定电压时，柴油发电机开启。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3803"/>
        <source>Grid-off EOD</source>
        <translation>离网EOD</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3804"/>
        <source>Grid-off discharge cut-off voltage.</source>
        <translation>离网放电截止电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3808"/>
        <source>Grid-on EOD</source>
        <translation>并网EOD</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3809"/>
        <source>Grid-on discharge cut-off voltage.</source>
        <translation>并网放电截止电压。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3814"/>
        <source>Uniform charging to flushing current: Upper limit of 0.025C.</source>
        <translation>均充转浮充：上限为0.025C。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3819"/>
        <source>Float turn to uniform charging current: Upper limit of 0.15C.</source>
        <translation>浮充转均充：上限为0.15C。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4627"/>
        <source>Battery Types: Lithium, Lead-Acid.</source>
        <translation>电池类型：锂电、铅酸。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4636"/>
        <source>Battery Communication Modes: None, RS485, CAN, Ethernet. (Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as &quot;CAN&quot; or &quot;Ethernet&quot; simultaneously.)</source>
        <translation>电池通信方式：无、RS485、CAN、以太网。(备注:由于CAN端口和以太网都只有一个端口，因此电池通讯方式和EMS通讯方式不可同时选&quot;CAN&quot;或“以太网&quot;。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4645"/>
        <source>Constant Voltage (CV) mode: The converter will operate in constant voltage mode on the DC side.                                              Constant Current (CC) mode: The converter will operate in constant current mode on the DC side.                                              Constant Power AC (CP_AC) mode: The power level can be set at &quot;constant power.&quot; The value represents the power level, positive for discharge and negative for charge. For example, setting it to -5 means that the AC side will charge the battery with a power of 5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Conversely, setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.                                              Reserved.</source>
        <translation>恒压(CV)模式：变流器直流侧将以恒压模式运行。
恒流(CC)模式，变流器直流侧将以恒流模式运行。
交流恒功率(CP_AC)模式:可以在&apos;′恒功率”处设置功率大小，数值为大小为功率大小，正值为放电，负值为充电。比如设置-5，表示交流侧将以-5kW的功率给电池充电，由于逆变器的损耗，此时直流侧的功率将小于交流侧的功率;比如设置5，表示交流侧将以5kW的功率输出，由于逆变器的损耗，此时直流侧的功率将大于交流侧的功率。
预留</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4657"/>
        <source>EMS communication methods: RS485, CAN, Ethernet.                                         The setting communication methods are readable and writable in remote mode, and only readable in local mode. The unselected communication methods are only readable in both remote and local mode.</source>
        <translation>EMS通信方式：RS485、CAN、以太网。
设定的通信方式在远程模式下可读可写，在本地模式下只可读，未选中的通信方式远程和本地仅可读。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4667"/>
        <source>Output Power Limit: Restricts the upper limit of the set value for the power on the AC side of the converter.</source>
        <translation>输出功率上限：限制变流器交流侧功率设置值的上限。</translation>
    </message>
    <message>
        <source>Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:MEGA, LISHEN, PENGHUI, GAOTE, XIENENG, LANLI, SHENLAN, PAINENG, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD, GROUP_STANDARD, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, ECUBE, FARO, BGS, JDITEC, HUASU, LIGAO.                                             
Select AUTO to automatically detect the battery manufacturer protocol.</source>
        <translation type="vanished">电池协议:根据选择的电池协议解析BMS发送的报文。目前支持选择的电池厂家协议为:迈格, 力神, 鹏辉, 高特, 协能, 蓝锂, 深澜, 派能, 宁德时代, 索英, 欣旺达, 库博, 高特V2, 拓高, 团标, 沃博源, 科工, 里德, 派能L, 未蓝, 沃太能源, 拓普, 捷辉, 金锂动, ECUBE, 法罗, BGS, JDITEC, 华塑, 力高.
选择AUTO时将自动判断电池厂家协议。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="491"/>
        <location filename="../win.cpp" line="4788"/>
        <source>Admin password</source>
        <translation>高级密码</translation>
    </message>
    <message>
        <location filename="../win.ui" line="950"/>
        <location filename="../win.cpp" line="4863"/>
        <source>Power change rate</source>
        <translation>功率变化率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4864"/>
        <source>Power change rate: the rate at which power changes within a second .</source>
        <translation>功率变化率：单位时间内功率变化的速率。</translation>
    </message>
    <message>
        <source>Upper limit of power grid frequency variation: The maximum range of frequency variation allowed on the AC side, which can be selected as 0.2, 0.5, 1, 5.</source>
        <translation type="vanished">电网频率变化范围上限：交流侧所允许的频率变化最大范围，可供选择为0.2、0.5、1、5。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4882"/>
        <source>Lower limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as-0.5, -1, -2, -5.</source>
        <translation>电网频率变化范围下限：交流侧所允许的频率变化最大范围，可供选择为-0.5、-1、-2、-5。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4891"/>
        <source>Upper limit of voltage protection range: The maximum range of voltage variation allowed on the AC side, which can be selected as 10, 15, 20.</source>
        <translation>电压保护范围上限：交流侧所允许的电压变化范围的上限，可供选择为10、15、20。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4900"/>
        <source>Lower limit of voltage protection range: The minimum range of voltage variation allowed on the AC side, which can be selected as -10, -15, -20.</source>
        <translation>电压保护范围下限：交流侧所允许的电压变化范围的下限，可供选择为-10、-15、-20。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4909"/>
        <source>High voltage ride through(HVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation>高压穿越使能：使能、禁止。(注:此项一般在大型并网电站使用。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4918"/>
        <source>Low voltage ride through(LVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation>低压穿越使能：使能、禁止。(注:此项一般在大型并网电站使用。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4927"/>
        <source>Prevent islanding effect. When islanding effect is detected (in a photovoltaic grid-on system, when a power outage occurs in the main grid, and the PV grid-connected converter generates power that matches the local load on the low-voltage side of the grid, it can easily sustain power generation independently, resulting in an &apos;island&apos; phenomenon, which endangers the safety of maintenance personnel), the converter automatically shuts down. The options for this feature can be set as &apos;Enable&apos; or &apos;prohibited&apos; .(Note: This option is generally used in large grid-on power stations.)</source>
        <translation>防止孤岛效应，当检测出现孤岛效应(在光伏并网系统中,当大电网出现停电事故时,光伏并网逆变器发电与电网低压侧本地负载如果刚好出现功率相匹配时,容易出现自给自足的维持发电状态,从而出现&quot;孤岛&quot;现象,从而危及检修人员安全)时,让逆变器自动停机,可供选择为允许、禁止，(注:此项一般在大型并网电站使用。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4937"/>
        <source>Insulation detection enable, the insulation resistance should be greater than 33KΩ for normal start-up and operation. If it is less than 33KΩ, it should not start, and an alarm should be triggered. By default, it is disabled, but can be set as &apos;Enable&apos; or &apos;prohibited&apos;.</source>
        <translation>绝缘检测使能，绝缘电阻大于33KΩ要能正常起机运行，小于33KΩ不能起机，并且要告警，默认禁止,可供选择为允许、禁止。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4946"/>
        <source>Primary frequency control enable: When the grid frequency deviates from the rated value, the active power is controlled to increase or decrease in order to maintain the grid frequency at the rated value. It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation>一次调频使能,电网的频率偏离额定值时，通过控制有功功率的增减使电网频率维持额定值，可供选择为允许、禁止(注:此项一般在大型并网电站使用。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4955"/>
        <source>Rotational inertia enable: It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation>转动惯量使能，可供选择为使能、禁止。(注:此项一般在大型并网电站使用。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4964"/>
        <source>Constant voltage parallel operation enable: It can be selected as enabled or disabled.  (Note: This option is generally used in large grid-on power stations.)</source>
        <translation>恒压并机使能,可供选择为使能、禁止。(注:此项设置在恒压并机模式下使用。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4973"/>
        <source>Converter Model: As per factory settings, generally not modifiable.</source>
        <translation>机器型号：以出厂设置为准，一般不可修改。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4982"/>
        <source>The rated capacity of the converter shall be based on the factory value and cannot be changed.</source>
        <translation>机器的额定容量，以出厂值为准，不可更改。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4991"/>
        <source>Output Frequency Level: Default 50Hz, typically 50Hz or 60Hz.</source>
        <translation>输出频率等级，默认50Hz，一般为50Hz或60Hz。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5000"/>
        <source>Output Voltage Level: As per factory settings, generally not modifiable.</source>
        <translation>输出电压等级：以出厂为准，一般不可修改。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5009"/>
        <source>Transformer Voltage Ratio: To be determined by the factory nameplate, not modifiable.</source>
        <translation>变压器变比:以出厂铭牌标识为准,不可修改。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5316"/>
        <source>level 1 alarm</source>
        <translation>一级告警</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5317"/>
        <source>Action to be performed when level 1 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation>触发一级告警时执行的动作，可选功能为不动作、降功率、待机、关机、0功率待机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5325"/>
        <source>level 2 alarm</source>
        <translation>二级告警</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5326"/>
        <source>Action to be performed when level 2 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation>触发二级告警时执行的动作，可选功能为不动作、降功率、待机、关机、0功率待机。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5334"/>
        <source>level 3 alarm</source>
        <translation>三级告警</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5335"/>
        <source>Action that is performed when level 3 alarm is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation>触发三级告警时执行的动作，可选功能为不动作、待机、关机、0功率待机。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="643"/>
        <location filename="../win.cpp" line="4686"/>
        <source>Anti-backflow power tolerance</source>
        <translation>防逆流功率容差</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4687"/>
        <source>Anti-backflow power tolerance.The default power tolerance is 10 kW. When the output power increases to &quot;output power limit + power tolerance&quot;, the output power will be reduced to &quot;output power limit - power tolerance&quot;.
(Note: This setting only takes effect in the system anti-backflow mode and is used to control the power tolerance at the grid entrance).</source>
        <translation>防逆流功率容差，默认功率容差为10kw，输出功率增加达到’输出功率限制+功率容差’时，会将输出功率降低到’输出动率-功率容差’.
(注:本设置仅在系统防逆流模式生效，用于控制电网入口的功率容差)。</translation>
    </message>
    <message>
        <location filename="../win.ui" line="379"/>
        <location filename="../win.cpp" line="4697"/>
        <source>Serial Communication Address</source>
        <translation>串口通信地址</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4698"/>
        <source>Serial Communication Address: The default value is 1, adjustable range is between 1 and 255, used for matching address during serial communication.</source>
        <translation>串口通信地址：默认值为1，可调范围在1~255之间，用于串口通信时匹配地址。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4707"/>
        <source>Serial Port 2 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 2 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation>串口2，波特率有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口2默认波特率是9600 bps,八个数据位，无校验，一个停止位(8，N, 1).</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4716"/>
        <source>Serial Port 3 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 3 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation>串口3，波特率有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口3默认波特率是9600 bps,八个数据位，无校验，一个停止位(8，N, 1).</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4726"/>
        <source>Serial Port 4 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 4 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation>串口4，波特率有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口4默认波特率是9600 bps,八个数据位，无校验，一个停止位(8，N, 1).</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4735"/>
        <source>Serial Port 5 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 5 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation>串口5，波特率有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口5默认波特率是9600 bps,八个数据位，无校验，一个停止位(8，N, 1).</translation>
    </message>
    <message>
        <location filename="../win.ui" line="619"/>
        <location filename="../win.cpp" line="4743"/>
        <source>serial port 6</source>
        <translation>串口6</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4744"/>
        <source>Serial Port 6 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 6 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation>串口6，波特率有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口6默认波特率是9600 bps,八个数据位，无校验，一个停止位(8，N, 1).</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4753"/>
        <source>CAN1 Port: The baud rate for internal communication is 500 kbps by default and cannot be modified. </source>
        <translation>CAN1端口：内部通讯的波特率，默认波特率500 kbps,不可修改。 </translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4762"/>
        <source>CAN2 Port: Optional baud rates for the CAN2 port include 100, 125, 250, 500, and 800 kbps, with a default baud rate of 500 kbps.</source>
        <translation>CAN2端口：可选波特率100、125、250、500、800 kbps，默认波特率500kbps。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4771"/>
        <source>Protocol version: View the current protocol version. The default protocol version number is V1.0.</source>
        <translation>协议版本：查看当前协议版本,协议版本号默认为V1.0.</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4780"/>
        <source>User password: Available for resetting the user password. The default user password is 123456. (Note: The user password must be six digits.)</source>
        <translation>用户密码：可供重新设置用户密码，默认用户密码123456。(注：用户密码必须为六位数。)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4789"/>
        <source>Admin password: Available for resetting the admin password. The default admin password is 888888. (Note: The admin password must be six digits.)</source>
        <translation>高级设置密码：可供重新设置高级设置密码，默认高级设置密码888888。(注：高级设置密码必须为六位数。)</translation>
    </message>
    <message>
        <source>The AC auxiliary power supply is faulty</source>
        <translation type="vanished">交流辅助电源故障</translation>
    </message>
    <message>
        <source>The AC auxiliary power output is abnormal. Procedure</source>
        <translation type="vanished">交流辅助电源输出出现异常</translation>
    </message>
    <message>
        <source>The DC auxiliary power supply is faulty</source>
        <translation type="vanished">直流辅助电源故障</translation>
    </message>
    <message>
        <source>The DC auxiliary power output is abnormal. Procedure</source>
        <translation type="vanished">直流辅助电源输出出现异常</translation>
    </message>
    <message>
        <source>Fan failure</source>
        <translation type="vanished">风扇故障</translation>
    </message>
    <message>
        <source>The fan cannot be started</source>
        <translation type="vanished">风扇无法启动运行</translation>
    </message>
    <message>
        <source>PCS derating operation</source>
        <translation type="vanished">PCS 降额运行</translation>
    </message>
    <message>
        <source>Emergency shutdown</source>
        <translation type="vanished">紧急关机</translation>
    </message>
    <message>
        <source>Press the EPO button on the converter control panel</source>
        <translation type="vanished">在变流器控制面板上按下EPO按钮</translation>
    </message>
    <message>
        <source>CT or Hall open circuit fault</source>
        <translation type="vanished">CT或霍尔开路故障</translation>
    </message>
    <message>
        <source>When PCS grid-connected power is greater than 50%, CT detection current is less than 70% of the given quantity</source>
        <translation type="vanished">PCS并网功率大于50%运行时，CT检测电流小于给定量的70%</translation>
    </message>
    <message>
        <source>For 1000V systems, the positive or negative ground impedance is less than 33KΩ</source>
        <translation type="vanished">对于1000V系统，正对地或负对地阻抗小于33K欧姆</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1229"/>
        <location filename="../win.cpp" line="3030"/>
        <source>Grid voltage(AB)</source>
        <translation>电网电压 (AB)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1229"/>
        <location filename="../win.cpp" line="3039"/>
        <source>Grid voltage(BC)</source>
        <translation>电网电压 (BC)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1229"/>
        <location filename="../win.cpp" line="3048"/>
        <source>Grid voltage(CA)</source>
        <translation>电网电压 (CA)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1230"/>
        <location filename="../win.cpp" line="3057"/>
        <source>Grid current(A)</source>
        <translation>电网电流 (A)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1230"/>
        <location filename="../win.cpp" line="3066"/>
        <source>Grid current(B)</source>
        <translation>电网电流 (B)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1230"/>
        <location filename="../win.cpp" line="3075"/>
        <source>Grid current(C)</source>
        <translation>电网电流 (C)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1231"/>
        <location filename="../win.cpp" line="3084"/>
        <source>Grid active power</source>
        <translation>电网有功功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1231"/>
        <location filename="../win.cpp" line="3093"/>
        <source>Grid reactive power</source>
        <translation>电网无功功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1232"/>
        <location filename="../win.cpp" line="3102"/>
        <source>Grid apparent power</source>
        <translation>电网视在功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1232"/>
        <location filename="../win.cpp" line="3111"/>
        <source>Grid frequency</source>
        <translation>电网频率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1232"/>
        <location filename="../win.cpp" line="3120"/>
        <source>Grid power factor</source>
        <translation>电网功率因素</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1278"/>
        <location filename="../win.cpp" line="3135"/>
        <source>Load voltage(AB)</source>
        <translation>负载电压 (AB)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1278"/>
        <location filename="../win.cpp" line="3144"/>
        <source>Load voltage(BC)</source>
        <translation>负载电压 (BC)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1278"/>
        <location filename="../win.cpp" line="3153"/>
        <source>Load voltage(CA)</source>
        <translation>负载电压 (CA)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1279"/>
        <location filename="../win.cpp" line="3162"/>
        <source>Load current(A)</source>
        <translation>负载电流 (A)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1279"/>
        <location filename="../win.cpp" line="3171"/>
        <source>Load current(B)</source>
        <translation>负载电流 (B)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1279"/>
        <location filename="../win.cpp" line="3180"/>
        <source>Load current(C)</source>
        <translation>负载电流 (C)</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1280"/>
        <location filename="../win.cpp" line="3189"/>
        <source>Load active power</source>
        <translation>负载有功功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1280"/>
        <location filename="../win.cpp" line="3198"/>
        <source>Load reactive power</source>
        <translation>负载无功功率</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1281"/>
        <location filename="../win.cpp" line="3207"/>
        <source>Load apparent power</source>
        <translation>负载视在功率</translation>
    </message>
    <message>
        <source>Load power fator</source>
        <translation type="vanished">负载功率因素</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1869"/>
        <location filename="../win.cpp" line="1873"/>
        <source>Maintenance Bypass breaker</source>
        <translation>维修旁路</translation>
    </message>
    <message>
        <source>Generator signal</source>
        <translation type="vanished">柴发信号</translation>
    </message>
    <message>
        <source>EPO contact signal 1</source>
        <translation type="vanished">EPO 节点信号1</translation>
    </message>
    <message>
        <source>EPO contact signal 2</source>
        <translation type="vanished">EPO 节点信号2</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1881"/>
        <source>Access control signal</source>
        <translation>门禁信号</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1882"/>
        <location filename="../win.cpp" line="3393"/>
        <source>Full power signal</source>
        <translation>满功率信号</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1882"/>
        <location filename="../win.cpp" line="3402"/>
        <source>Smoke alarm signal</source>
        <translation>烟雾报警信号</translation>
    </message>
    <message>
        <source>Hight temp. signal</source>
        <translation type="vanished">高温信号</translation>
    </message>
    <message>
        <source>Here shows the charge of the day; Click here to jump to a histogram of daily charge and discharge, with the horizontal axis in days and the vertical axis in power (kWh).</source>
        <translation type="vanished">这里显示当日充电电量；点击此处将跳转到每日充放电量的直方图，横轴单位为日，纵轴单位为功率(kWh)。</translation>
    </message>
    <message>
        <source>To export history records, click here to export history records to the USB flash drive. The file exported to the USB flash drive is HistoryRecord.csv, which needs to be opened with Excel.</source>
        <translation type="vanished">导出历史记录，点击此处将会导出历史记录到U盘，导出到U盘的文件为HistoryRecord.csv，此文件需要用Excel打开。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2245"/>
        <source>This is the interface number, which defaults to eth0.</source>
        <translation>这是接口号，默认eth0。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2249"/>
        <source>This is the port number, which defaults to 502 and can be changed as needed.</source>
        <translation>这是端口号，默认为502，可以根据需要进行更改。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2253"/>
        <source>This is the IP address. The default is 192.168.1.100.</source>
        <translation>这是IP地址，默认192.168.1.100。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2257"/>
        <source>This is the subnet mask, 255.255.255.0.</source>
        <translation>这是子网掩码，255.255.255.0。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2261"/>
        <source>This is the gateway. The default is 192.168.1.1.</source>
        <translation>这是网关，默认192.168.1.1。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2265"/>
        <source>This is the server IP address. The default is 192.168.1.200.</source>
        <translation>这是服务器IP，默认192.168.1.200。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1065"/>
        <location filename="../win.cpp" line="2317"/>
        <source>Level</source>
        <translation>等级</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1065"/>
        <location filename="../win.cpp" line="2319"/>
        <source>Start Time</source>
        <translation>开始时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1065"/>
        <location filename="../win.cpp" line="2321"/>
        <source>End Time</source>
        <translation>结束时间</translation>
    </message>
    <message>
        <location filename="../win.ui" line="8965"/>
        <location filename="../win.cpp" line="1065"/>
        <source>Description</source>
        <translation>描述</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1103"/>
        <location filename="../win.cpp" line="2639"/>
        <source>ModificationTime</source>
        <translation>修改时间</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1103"/>
        <location filename="../win.cpp" line="2641"/>
        <source>RecordEvent</source>
        <translation>事件记录</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2327"/>
        <source>Power Meter Comm fualttLead-acid abnormal</source>
        <translation>电能表通信故障</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2640"/>
        <source>Time when the system Settings are modified.</source>
        <translation>系统设置修改时的时间。</translation>
    </message>
    <message>
        <source>This is the allowable charging capacity uploaded from BMS through CAN/485/TCP communication protocol. It represents the current battery pack&apos;s capacity for charging. This value is not displayed when it does not exist (Note: Only certain BMSs provide this value).</source>
        <translation type="vanished">这是PCS通过CAN/485/TCP通讯协议从BMS上传得到允许充电功率或通过CAN/485/TCP通讯协议从BMS上传的当前充电限流值乘以当前电压值得到允许充电功率，电池的充电功率不可超过这个限制数值。</translation>
    </message>
    <message>
        <source>This is the allowable discharge power obtained by PCS from BMS through CAN/485/TCP communication protocol, or obtained by multiplying the current discharge limit value uploaded from BMS through CAN/485/TCP communication protocol with the current voltage value. The battery&apos;s discharge power should not exceed this limitation value.</source>
        <translation type="vanished">这是PCS通过CAN/485/TCP通讯协议从BMS上传得到允许放电功率或通过CAN/485/TCP通讯协议从BMS上传的当前放电限流值乘以当前电压值得到允许放电功率，电池的放电功率不可超过这个限制数值。</translation>
    </message>
    <message>
        <source>This is the allowable discharge capacity uploaded from BMS through CAN/485/TCP communication protocol. It represents the current battery pack&apos;s capacity for discharging. This value is not displayed when it does not exist (Note: Only certain BMSs provide this value).</source>
        <translation type="vanished">这是通过CAN/485/TCP通讯协议从BMS上传的允许放电量，当前电池组允许放电的容量，当不存在该值时，此项不显示(注:仅部分BMS会提供这个值)。</translation>
    </message>
    <message>
        <source>The inverter side voltage of the current PCS is the phase voltage between phase A and phase B.</source>
        <translation type="vanished">当前PCS的逆变侧电压，此项为A相和B相之间的相电压。</translation>
    </message>
    <message>
        <source>The inverter side voltage of the current PCS is the phase voltage between phase B and phase C.</source>
        <translation type="vanished">当前PCS的逆变侧电压，此项为B相和C相之间的相电压。</translation>
    </message>
    <message>
        <source>The inverter side voltage of the current PCS is the phase voltage between phase A and phase C.</source>
        <translation type="vanished">当前PCS的逆变侧电压，此项为A相和C相之间的相电压。</translation>
    </message>
    <message>
        <source>The current of the inverter side of the current PCS is the current of phase A.</source>
        <translation type="vanished">当前PCS的逆变侧电流，此项为A相的电流。</translation>
    </message>
    <message>
        <source>The current of the inverter side of the current PCS is the current of phase B.</source>
        <translation type="vanished">当前PCS的逆变侧电流，此项为B相的电流。</translation>
    </message>
    <message>
        <source>The current of the inverter side of the current PCS is the current of phase C.</source>
        <translation type="vanished">当前PCS的逆变侧电流，此项为C相的电流。</translation>
    </message>
    <message>
        <source>PCS Active Power</source>
        <translation type="vanished">PCS有功功率</translation>
    </message>
    <message>
        <source>The active power P of the inverter side of the current PCS.</source>
        <translation type="vanished">当前PCS的逆变侧有功功率P。</translation>
    </message>
    <message>
        <source>PCS Reactive Power</source>
        <translation type="vanished">PCS无功功率</translation>
    </message>
    <message>
        <source>The reactive power Q of the inverter side of the current PCS.</source>
        <translation type="vanished">当前PCS的逆变侧无功功率Q。</translation>
    </message>
    <message>
        <source>PCS Parent Power</source>
        <translation type="vanished">PCS视在功率</translation>
    </message>
    <message>
        <source>The inverter side view of the current PCS is at power S, S= √((P^2+Q^2)).</source>
        <translation type="vanished">当前PCS的逆变侧视在功率S，S= √((P^2+Q^2))。</translation>
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
        <translation>0</translation>
    </message>
    <message>
        <source>PCS Power factor</source>
        <translation type="vanished">PCS功率因数</translation>
    </message>
    <message>
        <source>Power factor Pf on the inverter side of current PCS, Pf = P/S.</source>
        <translation type="vanished">当前PCS的逆变侧功率因素Pf， Pf = P / S。</translation>
    </message>
    <message>
        <source>PCS Battery voltage</source>
        <translation type="vanished">电池电压</translation>
    </message>
    <message>
        <source>The current PCS samples the battery voltage from the connected battery.</source>
        <translation type="vanished">当前PCS从接入的电池侧采样的电池电压。</translation>
    </message>
    <message>
        <source>PCS Battery current</source>
        <translation type="vanished">电池电流</translation>
    </message>
    <message>
        <source>Battery current sampled by the PCS from the connected battery.</source>
        <translation type="vanished">当前PCS从接入的电池侧采样的电池电流。</translation>
    </message>
    <message>
        <source>PCS Battery power</source>
        <translation type="vanished">电池功率</translation>
    </message>
    <message>
        <source>At present, PCS calculates the product of battery voltage and battery current to obtain battery power.</source>
        <translation type="vanished">当前PCS内部计算电池电压与电池电流的乘积，得到电池功率。</translation>
    </message>
    <message>
        <source>PCS Bus voltage</source>
        <translation type="vanished">母线电压</translation>
    </message>
    <message>
        <source>The current bus voltage sampled by PCS from the bus side.</source>
        <translation type="vanished">当前PCS从母线侧采样的母线电压。</translation>
    </message>
    <message>
        <source>PCS IGBT temperature</source>
        <translation type="vanished">IGBT温度</translation>
    </message>
    <message>
        <source>The current IGBT temperature of PCS shall not exceed 105℃, otherwise PCS will run derated.</source>
        <translation type="vanished">当前PCS的IGBT温度，IGBT温度不得超过105℃，否则PCS将降额运行。</translation>
    </message>
    <message>
        <source>PCS Environment temperature</source>
        <translation type="vanished">环境温度</translation>
    </message>
    <message>
        <source>The ambient temperature of the current PCS.</source>
        <translation type="vanished">当前PCS所处的环境温度。</translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1719"/>
        <source>Change Language</source>
        <translation>切换语言</translation>
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
        <translation></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="49"/>
        <source>Host</source>
        <translation>主页</translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="80"/>
        <source>Rt.Data</source>
        <translation>数据</translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="115"/>
        <source>Record</source>
        <translation>记录</translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="146"/>
        <source>System</source>
        <translation>系统</translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="186"/>
        <source>Turn on</source>
        <translation>开启</translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="217"/>
        <source>Stand-by</source>
        <translation>待机</translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="248"/>
        <source>Turn off</source>
        <translation>关闭</translation>
    </message>
</context>
<context>
    <name>Specification</name>
    <message>
        <location filename="../Specification/Specification.cpp" line="36"/>
        <source>OK</source>
        <translation>确定</translation>
    </message>
</context>
<context>
    <name>UpgradeTools</name>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="43"/>
        <source>MPS</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="66"/>
        <source>MPS Upgrade app V2.0</source>
        <translation>MPS升级软件V2.0</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="102"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="502"/>
        <source> Message:</source>
        <translation>消息</translation>
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
        <translation> 挂载完成 
 文件检查通过 
 监控更新文件不存在 
 DCAC更新文件准备就绪 
 DCDC更新文件不存在 
 开始复制... 
 
 DCAC_Update.hex 
 更新开始 
 收到未知信号 
 收到未知信号 
 收到未知信号 
 擦除进行中 
 擦除进行中 
 特定块的数据传输已结束 
 特定块校验和验证通过 
 特定块校验和验证通过 
 特定块头部验证通过 
 特定块校验和验证通过 
 特定块的数据传输已结束 
 特定块头部验证通过</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="174"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="438"/>
        <source>Module number</source>
        <translation>模块号</translation>
    </message>
    <message>
        <source>DCDC</source>
        <translation type="vanished">监控</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="230"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="58"/>
        <source>DCDC Upgrade</source>
        <translation>DCDC升级</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="251"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="63"/>
        <source>DCAC Upgrade</source>
        <translation>DCAC升级</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="274"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="661"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="68"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="91"/>
        <source>Monitor</source>
        <translation>监控</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="295"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="682"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="72"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="95"/>
        <source>Backup</source>
        <translation>备份</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="316"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="703"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="76"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="99"/>
        <source>Restore</source>
        <translation>恢复</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="339"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="81"/>
        <source>Apply and restart</source>
        <translation>应用并重启</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="414"/>
        <source>PCS Upgrade Tools V2.0</source>
        <translation>PCS升级工具V2.0</translation>
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
        <translation> 挂载完成 
 文件检查通过 
 Monitor.hex不存在 
 DSP更新程序准备就绪 
 开始复制... 
 
 DSPUpdate.hex
 更新开始</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="566"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="115"/>
        <source>Monitor.hex</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="587"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="119"/>
        <source>DSPUpdate.hex</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="612"/>
        <source>Baud rate</source>
        <translation>波特率</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="636"/>
        <source>500k</source>
        <translation>500k</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="726"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="103"/>
        <source>DSP Upgrade</source>
        <translation>DSP升级</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="391"/>
        <source>PCS</source>
        <translation>PCS</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="14"/>
        <source>UpgradeTools</source>
        <translation>升级工具</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="747"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="109"/>
        <source>Restart</source>
        <translation>重启</translation>
    </message>
    <message>
        <source>After inserting the USB flash drive and detecting the DCDC upgrade program DCDC_Update.hex,click to upgrade the corresponding DCDC module based on the displayed module number.</source>
        <translation type="vanished">在插入U盘并检查到有DCDC升级程序DCDC_Update.hex后，点击将按照上面显示的模块号升级对应的DCDC模块。</translation>
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
        <translation>确定</translation>
    </message>
    <message>
        <source>After inserting the USB flash drive and detecting the DCAC upgrade program DCAC_Update.hex,click to upgrade DCAC.
You need to press the EPO during the upgrade.</source>
        <translation type="vanished">在插入U盘并检查到有DCAC升级程序DCAC_Update.hex后，点击将升级DCAC。
升级过程中需要按下EPO。</translation>
    </message>
    <message>
        <source>After inserting the USB flash drive and checking that there is a Monitor upgrade program monitor.hex, click to upgrade the monitor program.</source>
        <translation type="vanished">在插入U盘并检查到有监控升级程序Monitor.hex后，点击将升级监控程序。</translation>
    </message>
    <message>
        <source>Click to back up the upgrade program.</source>
        <translation type="vanished">点击将对升级程序进行备份。</translation>
    </message>
    <message>
        <source>Click to restore to the already backed up program.</source>
        <translation type="vanished">点击将恢复到已经备份好程序。</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="59"/>
        <source>DCDC Upgrade: Insert a u disk and check for the presence of the DCDC upgrade program &apos;DCDC_Update.hex&apos;. Click on DCDC, and then upgrade the corresponding DCDC module according to the selected module number above.                                
(Note: Before upgrading the DCDC, ensure that the ship mode switch on the DCDC module is set to the OFF position.)</source>
        <translation>DCDC升级：插入U盘并检查是否有DCDC升级程序&apos;DCDC_Update.hex&apos;，点击‘DCDC升级’后，将按照上面选择的模块号升级对应的DCDC模块。
（注：升级DCDC前，需要把DCDC模块的船型开关拨到OFF位置。）</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="64"/>
        <source>DCAC Upgrade: Insert the u disk and check if there is a DCAC upgrade program called &apos;DCAC_Update.hex&apos;. Click to upgrade the DCAC.                                
(Note: Press the EPO button before upgrading.)</source>
        <translation>DCAC升级：插入U盘并检查到有DCAC升级程序&apos;DCAC_Update.hex&apos;后，点击‘DCAC升级’后，将升级DCAC软件.
(注：升级前需要按下EPO.）</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="69"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="92"/>
        <source>After inserting the u disk and checking that there is a Monitor upgrade program &apos;Monitor.hex&apos;, click to upgrade the monitor program.</source>
        <translation>在插入U盘并检查到有监控升级程序Monitor.hex后，点击将升级监控升级程序。</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="73"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="96"/>
        <source>Backup: Click to backup the current program files.</source>
        <translation>备份：点击将对当前程序文件进行备份。</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="77"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="100"/>
        <source>Restore: Restore to the most recent backup program files.</source>
        <translation>恢复：恢复到最近一次备份的程序文件。</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="82"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="110"/>
        <source>Click to restart.</source>
        <translation>点击后将进行重启。</translation>
    </message>
    <message>
        <source>Previous Page</source>
        <translation type="vanished">上一页</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="87"/>
        <source>Baud Rate</source>
        <translation>波特率</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="88"/>
        <source>Baud Rate: Default is 500k and cannot be modified.</source>
        <translation>波特率：默认500k，不可修改。</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="104"/>
        <source>DSP Upgrade: Insert the u disk and check if there is a DSP upgrade program called &apos;DSPUpdate.hex&apos;. Click to upgrade the DSP.                                
(Note: Press the EPO button before upgrading.))</source>
        <translation>DSP升级：插入U盘并检查到有DSP升级程序&apos;DSPUpdate.hex&apos;后，点击‘DSP升级’后，将升级DSP软件.
(注：升级前需要按下EPO.）</translation>
    </message>
    <message>
        <source>This is the baud rate setting, there are 125k and 500k two baud rate options, the default 500k.</source>
        <translation type="vanished">这是波特率设置，有125k后500k两种波特率选择，默认500k。</translation>
    </message>
    <message>
        <source>After inserting the USB flash drive and checking that there is DCAC update program DSPUpdate.hex, click to upgrade DSP.
You need to press the EPO during the upgrade.</source>
        <translation type="vanished">在插入U盘并检查到有DCAC升级程序DSPUpdate.hex后，点击将升级DSP。
升级过程中需要按下EPO。</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="116"/>
        <source>This is the name of the monitoring upgrade program.</source>
        <translation>这是监控升级程序名称。</translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="120"/>
        <source>This is the DSP upgrade program name.</source>
        <translation>这是DSP升级程序名称。</translation>
    </message>
</context>
</TS>
