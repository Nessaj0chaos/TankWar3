#pragma once

//颜色设置
#define		COLOR_BLUE_FOR			0x0001	//蓝色 前
#define		COLOR_GREEN_FOR			0x0002	//绿色 前
#define		COLOR_BLACK_FOR			0x0000	//黑色 前
#define		COLOR_RED_FOR			0x0004	//红色 前
#define		COLOR_PURPLE_FOR		0x0005	//紫色 前
#define		COLOR_YELLOW_FOR		0x0006	//黄色 前
#define		COLOR_WHITE_FOR			0x0007	//白色 前
#define		COLOR_HIGHTLIGHT_FOR	0x0008  //高亮 前
#define		WINDOWS_WIDTH			120 //窗口宽度
#define		WINDOWS_HIGH			40	//窗口高度
#define		PMAP_WIDTH				60  //编辑地图是的宽度
#define		MAP_WIDTH				40	//地图宽度
#define		MAP_HIGH				40  //地图高度
#define		WALL_NULL         0x0  // 空道						默认
#define		WALL_A1           0x2  // ▓  土墙（可破坏）		默认
#define		WALL_A2           0x1  // 卍  土墙（可破坏,破坏形态）
#define		WALL_B            0x4  // 〓  铁墙 (可破坏){
#define		WALL_C            0x5  // ≈  河流（减速）public:
#define		WALL_D            0x6  // ∷  路障（无敌,不可穿过）默认:	CData();
#define		WALL_E            0x7  // ≡  丛林（隐身）	~CData();
#define		WALL_F            0x8  // ※  高速路(加速)
#define		WALL_G            0x9  // ☆  箱子（随机加BUff）
#define		TANK_B			  0xA
#define		TANK_BODY		  "■" //坦克身体
#define		WALL_A1_PC        "▓"	
#define		WALL_A2_PC        "卍"
#define		WALL_B_PC         "〓"
#define		WALL_C_PC         "≈"
#define		WALL_D_PC         "∷"
#define		WALL_E_PC         "≡"
#define		WALL_F_PC         "※"
#define		WALL_G_PC         "☆"
#define		MISSILETYPE_1_PC   "☉" 
#define		MISSILETYPE_3_PC   "¤" 
#define		MISSILETYPE_7_PC   "◎"

#define KEYDOWN(vk_code)((GetAsyncKeyState(vk_code)&0X1)?1:0)
#define KEYUP(vk_code)((GetAsyncKeySate(vk_code)&0X1)?0:1)
