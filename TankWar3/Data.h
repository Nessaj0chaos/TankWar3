#pragma once

//��ɫ����
#define		COLOR_BLUE_FOR			0x0001	//��ɫ ǰ
#define		COLOR_GREEN_FOR			0x0002	//��ɫ ǰ
#define		COLOR_BLACK_FOR			0x0000	//��ɫ ǰ
#define		COLOR_RED_FOR			0x0004	//��ɫ ǰ
#define		COLOR_PURPLE_FOR		0x0005	//��ɫ ǰ
#define		COLOR_YELLOW_FOR		0x0006	//��ɫ ǰ
#define		COLOR_WHITE_FOR			0x0007	//��ɫ ǰ
#define		COLOR_HIGHTLIGHT_FOR	0x0008  //���� ǰ
#define		WINDOWS_WIDTH			120 //���ڿ��
#define		WINDOWS_HIGH			40	//���ڸ߶�
#define		PMAP_WIDTH				60  //�༭��ͼ�ǵĿ��
#define		MAP_WIDTH				40	//��ͼ���
#define		MAP_HIGH				40  //��ͼ�߶�
#define		WALL_NULL         0x0  // �յ�						Ĭ��
#define		WALL_A1           0x2  // ��  ��ǽ�����ƻ���		Ĭ��
#define		WALL_A2           0x1  // �d  ��ǽ�����ƻ�,�ƻ���̬��
#define		WALL_B            0x4  // ��  ��ǽ (���ƻ�){
#define		WALL_C            0x5  // ��  ���������٣�public:
#define		WALL_D            0x6  // ��  ·�ϣ��޵�,���ɴ�����Ĭ��:	CData();
#define		WALL_E            0x7  // ��  ���֣�����	~CData();
#define		WALL_F            0x8  // ��  ����·(����)
#define		WALL_G            0x9  // ��  ���ӣ������BUff��
#define		TANK_B			  0xA
#define		TANK_BODY		  "��" //̹������
#define		WALL_A1_PC        "��"	
#define		WALL_A2_PC        "�d"
#define		WALL_B_PC         "��"
#define		WALL_C_PC         "��"
#define		WALL_D_PC         "��"
#define		WALL_E_PC         "��"
#define		WALL_F_PC         "��"
#define		WALL_G_PC         "��"
#define		MISSILETYPE_1_PC   "��" 
#define		MISSILETYPE_3_PC   "��" 
#define		MISSILETYPE_7_PC   "��"

#define KEYDOWN(vk_code)((GetAsyncKeyState(vk_code)&0X1)?1:0)
#define KEYUP(vk_code)((GetAsyncKeySate(vk_code)&0X1)?0:1)
