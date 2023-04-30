#include "stdafx.h"
#include "mainController.h"




mainController::mainController()
{
	printf("mainController constructed.\n");

	mvp_matrix_obj = new matrixClass();
	shaderloader_obj = new shaderLoaderClass();
	gui_manager_obj = new GUI_ManagerClass();
	window_manager_obj = new WindowManagerClass();

	srand(time(NULL));
	for (int i = 0; i < 8; i++)
	{
		buki_index[i] = rand() % BUKI_NUM;
	}

	for (int i = 0; i < 9; i++)
	{
		is_weapon_type[i] = true;
	}

	for (int i = 0; i < 13; i++)
	{
		is_sub_type[i] = true;
	}

	for (int i = 0; i < 15; i++)
	{
		is_special_type[i] = true;
	}

	attr_weapon[0] = 1;     attr_bomb[0] = 6;       attr_special[0] = 4; // dual custom
	attr_weapon[1] = 1;     attr_bomb[1] = 8;       attr_special[1] = 11; // spattary
	attr_weapon[2] = 1;     attr_bomb[2] = 10;      attr_special[2] = 4; // spattary hue
	attr_weapon[3] = 1;     attr_bomb[3] = 1;       attr_special[3] = 2; // spla manubar
	attr_weapon[4] = 1;     attr_bomb[4] = 2;       attr_special[4] = 0; // spla manubar collabo
	attr_weapon[5] = 1;     attr_bomb[5] = 9;       attr_special[5] = 6; // spla manubar bettyu
	attr_weapon[6] = 1;     attr_bomb[6] = 3;       attr_special[6] = 0; // kerbin 525
	attr_weapon[7] = 1;     attr_bomb[7] = 5;       attr_special[7] = 6; // kerbin 525 Deco
	attr_weapon[8] = 1;     attr_bomb[8] = 4;       attr_special[8] = 2; // dual sweeper
	attr_weapon[9] = 1;     attr_bomb[9] = 0;       attr_special[9] = 1; // quad black
	attr_weapon[10] = 1;     attr_bomb[10] = 7;       attr_special[10] = 13; // quad white
	attr_weapon[11] = 0;     attr_bomb[11] = 2;       attr_special[11] = 1; // bold
	attr_weapon[12] = 0;     attr_bomb[12] = 8;       attr_special[12] = 2; // bold neo
	attr_weapon[13] = 0;     attr_bomb[13] = 6;       attr_special[13] = 5; // wakaba
	attr_weapon[14] = 0;     attr_bomb[14] = 0;       attr_special[14] = 4; // momiji
	attr_weapon[15] = 0;     attr_bomb[15] = 10;       attr_special[15] = 0; // sharp
	attr_weapon[16] = 0;     attr_bomb[16] = 1;       attr_special[16] = 11; // sharp neo
	attr_weapon[17] = 0;     attr_bomb[17] = 9;       attr_special[17] = 12; // shilver modeler
	attr_weapon[18] = 0;     attr_bomb[18] = 7;       attr_special[18] = 6; // gold modeler
	attr_weapon[19] = 0;     attr_bomb[19] = 1;       attr_special[19] = 1; // spla shooter
	attr_weapon[20] = 0;     attr_bomb[20] = 6;       attr_special[20] = 0; // spla shooter collabo
	attr_weapon[21] = 0;     attr_bomb[21] = 9;       attr_special[21] = 2; // spla shooter betyu
	attr_weapon[22] = 0;     attr_bomb[22] = 4;       attr_special[22] = 6; // 52
	attr_weapon[23] = 0;     attr_bomb[23] = 2;       attr_special[23] = 3; // 52 deco
	attr_weapon[24] = 0;     attr_bomb[24] = 9;       attr_special[24] = 5; // kuro zap
	attr_weapon[25] = 0;     attr_bomb[25] = 0;       attr_special[25] = 2; // aka zap
	attr_weapon[26] = 0;     attr_bomb[26] = 4;       attr_special[26] = 4; // prime
	attr_weapon[27] = 0;     attr_bomb[27] = 9;       attr_special[27] = 7; // prime collabo
	attr_weapon[28] = 0;     attr_bomb[28] = 7;       attr_special[28] = 5; // 96
	attr_weapon[29] = 0;     attr_bomb[29] = 5;       attr_special[29] = 1; // 96 deco
	attr_weapon[30] = 0;     attr_bomb[30] = 10;       attr_special[30] = 2; // jet sweeper
	attr_weapon[31] = 0;     attr_bomb[31] = 1;       attr_special[31] = 3; // jet custom
	attr_weapon[32] = 3;     attr_bomb[32] = 6;       attr_special[32] = 6; // nova
	attr_weapon[33] = 3;     attr_bomb[33] = 3;       attr_special[33] = 11; // nova neo
	attr_weapon[34] = 3;     attr_bomb[34] = 10;       attr_special[34] = 1; // hot
	attr_weapon[35] = 3;     attr_bomb[35] = 0;       attr_special[35] = 0; // hot custom
	attr_weapon[36] = 3;     attr_bomb[36] = 9;       attr_special[36] = 4; // long
	attr_weapon[37] = 3;     attr_bomb[37] = 2;       attr_special[37] = 7; // long custom
	attr_weapon[38] = 3;     attr_bomb[38] = 6;       attr_special[38] = 3; // crush
	attr_weapon[39] = 3;     attr_bomb[39] = 2;       attr_special[39] = 2; // crush neo
	attr_weapon[40] = 3;     attr_bomb[40] = 3;       attr_special[40] = 10; // rapid
	attr_weapon[41] = 3;     attr_bomb[41] = 9;       attr_special[41] = 0; // rapid deco
	attr_weapon[42] = 3;     attr_bomb[42] = 10;       attr_special[42] = 4; // rapid elete
	attr_weapon[43] = 3;     attr_bomb[43] = 5;       attr_special[43] = 5; // rapid elete deco
	attr_weapon[44] = 0;     attr_bomb[44] = 2;       attr_special[44] = 6; // L3
	attr_weapon[45] = 0;     attr_bomb[45] = 1;       attr_special[45] = 0; // L3D
	attr_weapon[46] = 0;     attr_bomb[46] = 4;       attr_special[46] = 2; // H3
	attr_weapon[47] = 0;     attr_bomb[47] = 9;       attr_special[47] = 5; // H3D
	attr_weapon[48] = 0;     attr_bomb[48] = 5;       attr_special[48] = 3; // bottle
	attr_weapon[49] = 0;     attr_bomb[49] = 6;       attr_special[49] = 7; // bottle foil
	attr_weapon[50] = 4;     attr_bomb[50] = 0;       attr_special[50] = 4; // carbon
	attr_weapon[51] = 4;     attr_bomb[51] = 1;       attr_special[51] = 13; // carbon deco
	attr_weapon[52] = 4;     attr_bomb[52] = 2;       attr_special[52] = 1; // spla roller
	attr_weapon[53] = 4;     attr_bomb[53] = 8;       attr_special[53] = 6; // spla roller collabo
	attr_weapon[54] = 4;     attr_bomb[54] = 6;       attr_special[54] = 7; // spla roller betyu
	attr_weapon[55] = 4;     attr_bomb[55] = 3;       attr_special[55] = 3; // dynamo
	attr_weapon[56] = 4;     attr_bomb[56] = 6;       attr_special[56] = 5; // dynamo tesla
	attr_weapon[57] = 4;     attr_bomb[57] = 5;       attr_special[57] = 10; // variable
	attr_weapon[58] = 4;     attr_bomb[58] = 9;       attr_special[58] = 2; // variable foil
	attr_weapon[59] = 5;     attr_bomb[59] = 6;       attr_special[59] = 1; // pablo
	attr_weapon[60] = 5;     attr_bomb[60] = 3;       attr_special[60] = 6; // pablo hue
	attr_weapon[61] = 5;     attr_bomb[61] = 0;       attr_special[61] = 0; // hokusai
	attr_weapon[62] = 5;     attr_bomb[62] = 8;       attr_special[62] = 2; // hokusai hue
	attr_weapon[63] = 2;     attr_bomb[63] = 4;       attr_special[63] = 5; // sciccrin
	attr_weapon[64] = 2;     attr_bomb[64] = 0;       attr_special[64] = 6; // sciccrin beta
	attr_weapon[65] = 2;     attr_bomb[65] = 6;       attr_special[65] = 3; // spla charger
	attr_weapon[66] = 2;     attr_bomb[66] = 5;       attr_special[66] = 11; // spla charger collabo
	attr_weapon[67] = 2;     attr_bomb[67] = 7;       attr_special[67] = 6; // spla charget betyu
	attr_weapon[68] = 2;     attr_bomb[68] = 6;       attr_special[68] = 3; // spla scope
	attr_weapon[69] = 2;     attr_bomb[69] = 5;       attr_special[69] = 11; // spla scope collabo
	attr_weapon[70] = 2;     attr_bomb[70] = 7;       attr_special[70] = 6; // spla scope betyu
	attr_weapon[71] = 2;     attr_bomb[71] = 3;       attr_special[71] = 4; // 4K
	attr_weapon[72] = 2;     attr_bomb[72] = 8;       attr_special[72] = 7; // 4K custom
	attr_weapon[73] = 2;     attr_bomb[73] = 3;       attr_special[73] = 4; // 4K scope
	attr_weapon[74] = 2;     attr_bomb[74] = 8;       attr_special[74] = 7; // 4D scope custom
	attr_weapon[75] = 2;     attr_bomb[75] = 2;       attr_special[75] = 2; // take kou
	attr_weapon[76] = 2;     attr_bomb[76] = 10;       attr_special[76] = 14; // take otu
	attr_weapon[77] = 2;     attr_bomb[77] = 9;       attr_special[77] = 1; // soy
	attr_weapon[78] = 2;     attr_bomb[78] = 2;       attr_special[78] = 0; // soy custom
	attr_weapon[79] = 6;     attr_bomb[79] = 9;       attr_special[79] = 2; // baketu
	attr_weapon[80] = 6;     attr_bomb[80] = 7;       attr_special[80] = 6; // baketu deco
	attr_weapon[81] = 6;     attr_bomb[81] = 1;       attr_special[81] = 5; // hissen
	attr_weapon[82] = 6;     attr_bomb[82] = 6;       attr_special[82] = 4; // hissen hue
	attr_weapon[83] = 6;     attr_bomb[83] = 0;       attr_special[83] = 3; // screw
	attr_weapon[84] = 6;     attr_bomb[84] = 4;       attr_special[84] = 10; // screw neo
	attr_weapon[85] = 6;     attr_bomb[85] = 5;       attr_special[85] = 4; // furo
	attr_weapon[86] = 6;     attr_bomb[86] = 7;       attr_special[86] = 7; // exp
	attr_weapon[87] = 7;     attr_bomb[87] = 1;       attr_special[87] = 2; // spla spinner
	attr_weapon[88] = 7;     attr_bomb[88] = 2;       attr_special[88] = 4; // spla spinner collabo
	attr_weapon[89] = 7;     attr_bomb[89] = 7;       attr_special[89] = 3; // barrel
	attr_weapon[90] = 7;     attr_bomb[90] = 5;       attr_special[90] = 7; // barrel deco
	attr_weapon[91] = 7;     attr_bomb[91] = 0;       attr_special[91] = 1; // dydra
	attr_weapon[92] = 7;     attr_bomb[92] = 3;       attr_special[92] = 5; // dydra custom
	attr_weapon[93] = 7;     attr_bomb[93] = 10;       attr_special[93] = 0; // kugel
	attr_weapon[94] = 7;     attr_bomb[94] = 4;       attr_special[94] = 6; // notiras
	attr_weapon[95] = 8;     attr_bomb[95] = 7;       attr_special[95] = 4; // kasa
	attr_weapon[96] = 8;     attr_bomb[96] = 0;       attr_special[96] = 10; // kasa solera
	attr_weapon[97] = 8;     attr_bomb[97] = 8;       attr_special[97] = 7; // camp
	attr_weapon[98] = 8;     attr_bomb[98] = 5;       attr_special[98] = 12; // camp sorela
	attr_weapon[99] = 8;     attr_bomb[99] = 3;       attr_special[99] = 1; // spy
	attr_weapon[100] = 8;     attr_bomb[100] = 6;       attr_special[100] = 6; // spy solera
	attr_weapon[101] = 3;     attr_bomb[101] = 11;       attr_special[101] = 4; // nova betyu
	attr_weapon[102] = 4;     attr_bomb[102] = 7;       attr_special[102] = 8; // dynamo betu
	attr_weapon[103] = 6;     attr_bomb[103] = 11;       attr_special[103] = 1; // screw betu
	attr_weapon[104] = 0;     attr_bomb[104] = 6;       attr_special[104] = 8; // prime betu
	attr_weapon[105] = 0;     attr_bomb[105] = 12;       attr_special[105] = 7; // ochiba
	attr_weapon[106] = 0;     attr_bomb[106] = 5;       attr_special[106] = 9; // L3 betyu
	attr_weapon[107] = 5;     attr_bomb[107] = 9;       attr_special[107] = 9; // hokusai betyu
	attr_weapon[108] = 8;     attr_bomb[108] = 12;       attr_special[108] = 5; // spy betu
	attr_weapon[109] = 1;     attr_bomb[109] = 11;       attr_special[109] = 5; // kervin bety
	attr_weapon[110] = 3;     attr_bomb[110] = 12;       attr_special[110] = 6; // rapid bety
	attr_weapon[111] = 0;     attr_bomb[111] = 5;       attr_special[111] = 8; // 52 bety
	attr_weapon[112] = 6;     attr_bomb[112] = 4;       attr_special[112] = 6; // ex custom
	attr_weapon[113] = 6;     attr_bomb[113] = 7;       attr_special[113] = 11; // furo deco
	attr_weapon[114] = 7;     attr_bomb[114] = 10;       attr_special[114] = 9; // spinner bety
	attr_weapon[115] = 7;     attr_bomb[115] = 8;       attr_special[115] = 4; // kugetu hue
	attr_weapon[116] = 7;     attr_bomb[116] = 9;       attr_special[116] = 0; // notiral 79

	attr_weapon[117] = 3;     attr_bomb[117] = 1;       attr_special[117] = 2; // long necro
	attr_weapon[118] = 2;     attr_bomb[118] = 11;       attr_special[118] = 7; // take hei
	attr_weapon[119] = 7;     attr_bomb[119] = 4;       attr_special[119] = 8; // barrel remix
	attr_weapon[120] = 8;     attr_bomb[120] = 3;       attr_special[120] = 9; // camping camo
	attr_weapon[121] = 2;     attr_bomb[121] = 9;       attr_special[121] = 0; // sciccrin ganmma
	attr_weapon[122] = 5;     attr_bomb[122] = 7;       attr_special[122] = 5; // parmanent pablo
	attr_weapon[123] = 0;     attr_bomb[123] = 5;       attr_special[123] = 7; // H3 cherry
	attr_weapon[124] = 1;     attr_bomb[124] = 12;       attr_special[124] = 1; // spattary clear
	attr_weapon[125] = 0;     attr_bomb[125] = 1;       attr_special[125] = 8; // modelar copper
	attr_weapon[126] = 6;     attr_bomb[126] = 6;       attr_special[126] = 14; // baketu soda
	attr_weapon[127] = 0;     attr_bomb[127] = 6;       attr_special[127] = 9; // bold 7
	attr_weapon[128] = 0;     attr_bomb[128] = 7;       attr_special[128] = 4; // fami zap

	weapon_w_str_JP[0] = L"シューター";
	weapon_w_str_JP[1] = L"マニューバー";
	weapon_w_str_JP[2] = L"チャージャー";
	weapon_w_str_JP[3] = L"ブラスター";
	weapon_w_str_JP[4] = L"ローラー";
	weapon_w_str_JP[5] = L"フデ";
	weapon_w_str_JP[6] = L"スロッシャー";
	weapon_w_str_JP[7] = L"スピナー";
	weapon_w_str_JP[8] = L"シェルター";

	weapon_w_str_EN[0] = L"Shooter";
	weapon_w_str_EN[1] = L"Dualies";
	weapon_w_str_EN[2] = L"Charger";
	weapon_w_str_EN[3] = L"Blaster";
	weapon_w_str_EN[4] = L"Roller";
	weapon_w_str_EN[5] = L"Brush";
	weapon_w_str_EN[6] = L"Slocher";
	weapon_w_str_EN[7] = L"Splatling";
	weapon_w_str_EN[8] = L"Brella";


	sub_w_str_JP[0] = L"ロボットボム";
	sub_w_str_JP[1] = L"クイックボム";
	sub_w_str_JP[2] = L"カーリングボム";
	sub_w_str_JP[3] = L"トラップ";
	sub_w_str_JP[4] = L"ポイントセンサー";
	sub_w_str_JP[5] = L"スプラッシュシールド";
	sub_w_str_JP[6] = L"スプラッシュボム";
	sub_w_str_JP[7] = L"スプリンクラー";
	sub_w_str_JP[8] = L"ジャンプビーコン";
	sub_w_str_JP[9] = L"キューバンボム";
	sub_w_str_JP[10] = L"ポイズンミスト";
	sub_w_str_JP[11] = L"タンサンボム";
	sub_w_str_JP[12] = L"トーピード";

	sub_w_str_EN[0] = L"Autobomb";
	sub_w_str_EN[1] = L"Burst Bomb";
	sub_w_str_EN[2] = L"Curling Bomb";
	sub_w_str_EN[3] = L"Ink Mine";
	sub_w_str_EN[4] = L"Point Sensor";
	sub_w_str_EN[5] = L"Splash Wall";
	sub_w_str_EN[6] = L"Splat Bomb";
	sub_w_str_EN[7] = L"Sprinkler";
	sub_w_str_EN[8] = L"Squid Beakon";
	sub_w_str_EN[9] = L"Suction Bomb";
	sub_w_str_EN[10] = L"Toxic Mist";
	sub_w_str_EN[11] = L"Fizzy Bomb";
	sub_w_str_EN[12] = L"Torpedo";

	special_w_str_JP[0] = L"ジェットパック";
	special_w_str_JP[1] = L"スーパーチャクチ";
	special_w_str_JP[2] = L"マルチミサイル";
	special_w_str_JP[3] = L"ハイパープレッサー";
	special_w_str_JP[4] = L"アメフラシ";
	special_w_str_JP[5] = L"インクアーマー";
	special_w_str_JP[6] = L"イカスフィア";
	special_w_str_JP[7] = L"バブルランチャー";
	special_w_str_JP[8] = L"ナイスダマ";
	special_w_str_JP[9] = L"ウルトラハンコ";
	special_w_str_JP[10] = L"スプラッシュボムピッチャー";
	special_w_str_JP[11] = L"キューバンボムピッチャー";
	special_w_str_JP[12] = L"カーリングボムピッチャー";
	special_w_str_JP[13] = L"ロボボムピッチャー";
	special_w_str_JP[14] = L"クイックボムピッチャー";

	special_w_str_EN[0] = L"Inkjet";
	special_w_str_EN[1] = L"Splashdown";
	special_w_str_EN[2] = L"Tenta Missiles";
	special_w_str_EN[3] = L"Sting Ray";
	special_w_str_EN[4] = L"Ink Storm";
	special_w_str_EN[5] = L"Ink Armor";
	special_w_str_EN[6] = L"Baller";
	special_w_str_EN[7] = L"Bubble Blower";
	special_w_str_EN[8] = L"Booyah Bomb";
	special_w_str_EN[9] = L"Ultra Stamp";
	special_w_str_EN[10] = L"Splat-Bomb Launcher";
	special_w_str_EN[11] = L"Suction-Bomb Launcher";
	special_w_str_EN[12] = L"Curling-Bomb Launcher";
	special_w_str_EN[13] = L"Autobomb Launcher";
	special_w_str_EN[14] = L"Burst-Bomb Launcher";


	simple_vs_ptr = "#version 410 \nlayout(location = 0) in vec4 position; \nout vec4 color_out; \nuniform mat4 mvpMatrix; \nuniform vec4 color; \nvoid main() \n{ \ngl_Position = mvpMatrix * position; \ncolor_out = color; \n}\0";
	simple_fs_ptr = "#version 410 \nin vec4 color_out; \nlayout(location = 0) out vec4 fragColor; \nvoid main() \n{ \nfragColor = color_out; \n}";

	tex_vs_ptr = "#version 410 \nlayout(location = 0) in vec4 position; \nlayout(location = 1) in vec4 color; \nlayout(location = 2) in vec2 texCoord; \nout vec4 color_out; \nout vec2 texCoord_out; \nuniform mat4 mvpMatrix; \nvoid main() \n{ \ngl_Position = mvpMatrix * position; \ncolor_out = color; \ntexCoord_out = texCoord; \n}";
	tex_fs_ptr = "#version 410 \nin vec4 color_out; \nin vec2 texCoord_out; \nlayout(location = 0) out vec4 fragColor; \nuniform sampler2D texImage; \nvoid main() \n{ \nvec4 texColor = texture(texImage, texCoord_out); \nfragColor = vec4(color_out.r * texColor.r, \ncolor_out.g * texColor.g, \ncolor_out.b * texColor.b, \ncolor_out.a * texColor.a); \n}";
}


mainController::~mainController()
{
	printf("mainController destructed.\n");
}




void mainController::setup()
{
	openGL_initializer_obj = new OpenGLInitializerClass();
	gui_manager_obj = new GUI_ManagerClass();


	openGL_view_wnd = gui_manager_obj->create_textfield(main_window_obj,
		NULL,
		0,
		0,
		winWidth,
		winHeight-45,
		0);

	viewWidth = winWidth;
	viewHeight = winHeight - 45;

	/*
	HWND dummyWnd = gui_manager_obj->create_textfield(NULL,
		NULL,
		0,
		0,
		100,
		100,
		1234);
	*/

	HWND dummyWnd = window_manager_obj->create_borderless_window(L"dummy");
	window_manager_obj->set_window_position(dummyWnd, 0, 0);
	window_manager_obj->set_window_size(dummyWnd, 1, 1);
	window_manager_obj->set_window_level(dummyWnd, 0);


	openGL_initializer_obj->init_OpenGL_functions(dummyWnd, openGL_view_wnd);
	window_manager_obj->close_window(dummyWnd);
	openGL_initializer_obj->set_OpenGL_status();


	// setup shader
	shaderloader_obj->loadShaderSource_And_CompileShader_fromPtr(simple_vs_ptr, 0, &SIMPLE_VS);
	//shaderloader_obj->loadShaderSource_And_CompileShader("SH/Simple_VS.txt", 0, &SIMPLE_VS);
	shaderloader_obj->loadShaderSource_And_CompileShader_fromPtr(simple_fs_ptr, 2, &SIMPLE_FS);
	//shaderloader_obj->loadShaderSource_And_CompileShader("SH/Simple_FS.txt", 2, &SIMPLE_FS);
	shaderloader_obj->createProgram_And_AttachShader(&SIMPLE_PRG, &SIMPLE_VS, NULL, &SIMPLE_FS);

	shaderloader_obj->getUniformLocation(&SIMPLE_PRG, &UNF_SIMPLE_mvpMatrix, "mvpMatrix");
	shaderloader_obj->getUniformLocation(&SIMPLE_PRG, &UNF_SIMPLE_color, "color");

	////////////////////////////////
	shaderloader_obj->loadShaderSource_And_CompileShader_fromPtr(tex_vs_ptr, 0, &TEX_VS);
	//shaderloader_obj->loadShaderSource_And_CompileShader("SH/Tex_VS.txt", 0, &TEX_VS);
	shaderloader_obj->loadShaderSource_And_CompileShader_fromPtr(tex_fs_ptr, 2, &TEX_FS);
	//shaderloader_obj->loadShaderSource_And_CompileShader("SH/Tex_FS.txt", 2, &TEX_FS);
	shaderloader_obj->createProgram_And_AttachShader(&TEX_PRG, &TEX_VS, NULL, &TEX_FS);

	shaderloader_obj->getUniformLocation(&TEX_PRG, &UNF_TEX_mvpMatrix, "mvpMatrix");
	shaderloader_obj->getUniformLocation(&TEX_PRG, &UNF_TEX_texImage, "texImage");







	// VAO VBO
	glGenVertexArrays(1, &VAO_SIMPLE_name);
	glGenBuffers(1, &VBO_SIMPLE_name);

	glBindVertexArray(VAO_SIMPLE_name);
	glEnableVertexAttribArray(0); // vertex

	glBindVertexArray(0);

	////////////////////////////////////
	glGenVertexArrays(1, &VAO_TEX_name);
	glGenBuffers(3, VBO_TEX_name);

	glBindVertexArray(VAO_TEX_name);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);




	// setup buffer once

	GLfloat tempColor[4][4];
	GLfloat tempTex[4][2];

	for (int i = 0; i < 4; i++)
	{
		tempColor[i][0] = 1.0;
		tempColor[i][1] = 1.0;
		tempColor[i][2] = 1.0;
		tempColor[i][3] = 1.0;
	}

	tempTex[0][0] = 0.0;	tempTex[0][1] = 0.0;
	tempTex[1][0] = 0.0;	tempTex[1][1] = 1.0;
	tempTex[2][0] = 1.0;	tempTex[2][1] = 0.0;
	tempTex[3][0] = 1.0;	tempTex[3][1] = 1.0;

	glBindVertexArray(VAO_TEX_name);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_TEX_name[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 4 * 4, tempColor, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_TEX_name[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 4 * 2, tempTex, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);



	// set orthogonal matrix
	float viewRatio = (float)viewWidth / (float)viewHeight;
	printf("viewRatio %f", viewRatio);

	mvp_matrix_obj->lookAt(0.0, 0.0, 2.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
	mvp_matrix_obj->orthogonal(-viewRatio, viewRatio,
		-1.0, 1.0,
		0.01, 5.0);




	// setup texture
	glGenSamplers(1, &Sampler_name);
	glSamplerParameteri(Sampler_name, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glSamplerParameteri(Sampler_name, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glSamplerParameteri(Sampler_name, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glSamplerParameteri(Sampler_name, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLint tempNum;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &tempNum);
	
	for (int i = 0; i < tempNum; i++)
	{
		glBindSampler(i, Sampler_name);
	}




	//************************* PNG TEST *********************

	for (int i = 0; i < BUKI_NUM; i++)
	{
		// index of MAKEINTRESOURCEW is defined in Resource.h
		HRSRC tempSRC = FindResourceW(mainInst, MAKEINTRESOURCEW(251 + i), L"PNG");
	
		if (tempSRC == NULL)
		{
			printf("find resource %d png fail...\n");
		}
		else
		{
			// load resource
			HGLOBAL tempData = LoadResource(mainInst, tempSRC);

			if (tempData == NULL)
			{
				printf("load resource %d data fail...\n", i);
			}
			else
			{
				// alloc resouce pointer
				pngPtr[i] = (unsigned char*)LockResource(tempData);

				if (pngPtr == NULL)
				{
					printf("get resource pointer %d fail...\n", i);
				}
				else
				{
					pngDataSize[i] = SizeofResource(mainInst, tempSRC);
					//printf("get png %d pointer %luKB\n", i, pngDataSize[i]/1024);
					this->loadPNG(pngPtr[i], pngDataSize[i], &pixPtr[i]);

				}
			} // if HGLOBAL == NULL
		}  // if SRC == NULL
	} // for i



	// setup texture data

	glGenTextures(BUKI_NUM, BUKI_TEX_name);

	for (int i = 0; i < BUKI_NUM; i++)
	{
		/*
		unsigned char* tempPtr = pixPtr[i];
		for (int i = 0; i < 460 * 288; i++)
		{
			int r, g, b, a;
			r = *tempPtr;	tempPtr++;
			g = *tempPtr;	tempPtr++;
			b = *tempPtr;	tempPtr++;
			a = *tempPtr;	tempPtr++;

			if (i % 200 == 0)
			{
				printf("rgba %d : %d : %d : %d\n", r, g, b, a);
			}
		}
		*/

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, BUKI_TEX_name[i]);
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGBA,
			460,
			288,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			pixPtr[i]);

		// free memory
		free(pixPtr[i]);
	}

	// load wav resource

	/*
	HRSRC soundSRC = FindResourceW(mainInst, MAKEINTRESOURCEW(380), L"WAVE");

	if (soundSRC != NULL)
	{
		printf("find wave sound\n");

		HANDLE tempSound = LoadResource(mainInst, soundSRC);

		if (tempSound != NULL)
		{
			printf("Load Resource sound success.\n");

			hSound = (LPTSTR)LockResource(tempSound);
		}
	}
	*/

}




void mainController::loadPNG(unsigned char* pointer, unsigned long dataSize, unsigned char** toPtr)

{
	// check png header
	int isPNG = false;
	isPNG = png_check_sig((png_bytep)pointer, 8);

	//png_structp png_ptr = png_create_read_struct( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	if( !isPNG )
	{
		printf("this is not PNG. return.\n");
		return;
	}


	// init png_ptr struct
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL)
	{
		printf("png_create_read_struct fail...\n");
	}


	png_infop png_info = png_create_info_struct(png_ptr);
	if (png_info == NULL)
	{
		printf("png_create_info_struct fai...\n");
		png_destroy_read_struct(&png_ptr, NULL, NULL);
	}


	// init png_image struct
	png_image png_image;
	memset(&png_image, 0, sizeof(png_image));
	png_image.version = PNG_IMAGE_VERSION;


	// get png info
	png_image_begin_read_from_memory(&png_image,
		(png_const_voidp)pointer,
		(png_size_t)dataSize);

	if (PNG_IMAGE_FAILED(png_image))
	{
		printf("get png_image info fail....\n %s\n", png_image.message);
	}


	// get info of png
	unsigned int bytePerPix = PNG_IMAGE_PIXEL_CHANNELS(png_image.format);
	//printf("bpp:%d width:%d height:%d\n", bytePerPix, png_image.width, png_image.height);
	
	unsigned int stride = PNG_IMAGE_ROW_STRIDE(png_image);
	unsigned int bytePerRow = bytePerPix * png_image.width; // same meanings.

	// alloc memory for png pixel data
	unsigned int tempSize = PNG_IMAGE_BUFFER_SIZE(png_image, stride); // same "bytePerRow * height"
	//printf("size %d %d\n", tempSize, bytePerRow*png_image.height);

	*toPtr = (unsigned char*)malloc( bytePerRow*png_image.height );


	// get pixel data
	png_image_finish_read(&png_image, NULL, *toPtr, stride, NULL);

	png_image_free(&png_image);

}


void mainController::drawGL()
{
	// get keyboard state
	BYTE key[256];
	GetKeyboardState(key);

	if (key[VK_RETURN] & 0x80)
	{
		this->roulette_button();
	}

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// draw background
	GLfloat backColor[4] = { 1.0, 0.0, 0.0, 0.5 };
	glUseProgram(SIMPLE_PRG);
	glUniformMatrix4fv(UNF_SIMPLE_mvpMatrix, 1, GL_FALSE, mvp_matrix_obj->getMatrix());
	glUniform4fv(UNF_SIMPLE_color, 1, backColor);

	// draw 1st board ****************
	GLfloat back_v[4][4];
	for (int i = 0; i < 4; i++)
	{
		back_v[i][2] = 0.1;
		back_v[i][3] = 1.0;
	}

	float viewRatio = (float)viewWidth / (float)viewHeight;
	back_v[0][0] = -viewRatio;		back_v[0][1] = 1.0;
	back_v[1][0] = -viewRatio;		back_v[1][1] = -1.0;
	back_v[2][0] = 0.0;		back_v[2][1] = 1.0;
	back_v[3][0] = 0.0;		back_v[3][1] = -1.0;


	glBindVertexArray(VAO_SIMPLE_name);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_SIMPLE_name);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 4 * 4, back_v, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);



	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);


	// draw 2nd background
	backColor[0] = 0.0;
	backColor[1] = 1.0;
	backColor[2] = 0.0;
	backColor[3] = 0.5;

	back_v[0][0] = 0.0;
	back_v[1][0] = 0.0;
	back_v[2][0] = viewRatio;
	back_v[3][0] = viewRatio;

	glUniform4fv(UNF_SIMPLE_color, 1, backColor);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_SIMPLE_name);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 4 * 4, back_v, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);



	//////////////////////// Draw buki board
	GLfloat board_v[4][4];

	this->select_buki_shurui();

	// change shader
	glUseProgram(TEX_PRG);
	glUniformMatrix4fv(UNF_TEX_mvpMatrix, 1, GL_FALSE, mvp_matrix_obj->getMatrix());
	glUniform1i(UNF_TEX_texImage, 0); // use Texture0

	glBindVertexArray(VAO_TEX_name);

	for (int i = 0; i < 8; i++)
	{
		this->set_buki_vertex(&board_v[0][0], i, act_anim_scale);

		glBindTexture(GL_TEXTURE_2D, BUKI_TEX_name[buki_index[i]]);

		// draw
		glBindBuffer(GL_ARRAY_BUFFER, VBO_TEX_name[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 4 * 4, board_v, GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}


	act_anim_scale += (1.0 - act_anim_scale)* 0.2;

	SwapBuffers(openGL_initializer_obj->OpenGL_HDC);


	// set focus to main window
	//SetFocus(main_window_obj);
}



void mainController::set_buki_vertex(GLfloat* vptr, int index, float scale)
{
	float boardWidth = 460.0;
	float boardHeight = 288.0;
	float boardRatio = 460.0 / 288.0;
	float VIEW_RATIO = (float)viewWidth / (float)viewHeight;
	float wCoef = (VIEW_RATIO)*0.9 / boardRatio;

	// board size xy
	boardWidth = (boardRatio * wCoef) / 2.0;
	boardHeight = wCoef / 2.0;


	// calc center point of board
	float centerX;
	float centerY;

	// x
	if (index < 4)// left
	{
		centerX = -(VIEW_RATIO / 2.0);
	}
	else
	{
		centerX = VIEW_RATIO / 2.0;
	}


	// y
	switch (index % 4)
	{
	case 0:
		centerY = 0.75;
		break;

	case 1:
		centerY = 0.25;
		break;
	case 2:
		centerY = -0.25;
		break;
	case 3:
		centerY = -0.75;
		break;
	default:
		break;
	
	}


	//
	GLfloat* targetPtr = vptr;
	float addX = boardWidth * scale;
	float addY = boardHeight * scale;

	*targetPtr = centerX - addX;	targetPtr++;
	*targetPtr = centerY + addY;	targetPtr++;
	*targetPtr = 0.5;	targetPtr++;
	*targetPtr = 1.0;	targetPtr++;
		
	*targetPtr = centerX - addX;	targetPtr++;
	*targetPtr = centerY - addY;	targetPtr++;
	*targetPtr = 0.5;	targetPtr++;
	*targetPtr = 1.0;	targetPtr++;

	*targetPtr = centerX + addX;	targetPtr++;
	*targetPtr = centerY + addY;	targetPtr++;
	*targetPtr = 0.5;	targetPtr++;
	*targetPtr = 1.0;	targetPtr++;

	*targetPtr = centerX + addX;	targetPtr++;
	*targetPtr = centerY - addY;	targetPtr++;
	*targetPtr = 0.5;	targetPtr++;
	*targetPtr = 1.0;	
}


void mainController::select_buki_shurui()
{
	if (is_Roulette)
	{
		// change buki index randomly
		if (ROULETTE_COUNTER % 2 == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				buki_index[i] = rand() % BUKI_NUM;
			}
		}

		ROULETTE_COUNTER++;


		if (ROULETTE_COUNTER >= 175)
		{
			is_Roulette = false;
			act_anim_scale = 1.1;

			this->all_gui_enable(true);

			this->decide_buki();
		}


	}// if roulette
}



void mainController::decide_buki()
{
	for (int i = 0; i < 8; i++)
	{
		bool loop = true;

		while (loop)
		{
		
			printf("decide %d\n", i);
			int IDX = rand() % BUKI_NUM;
			int SHURUI = attr_weapon[IDX];
			int BOMB = attr_bomb[IDX];
			int SP = attr_special[IDX];


			if (is_weapon_type[SHURUI])
			{
				if (is_sub_type[BOMB])
				{
					if (is_special_type[SP])
					{
						if (is_allow_same_selection == false && i != 0)
						{
							bool isNotSame = true;
							// check kaburi
							for (int k = 0; k < i; k++)
							{
								if (IDX == buki_index[k])
								{
									isNotSame = false;
								}
							}

							if (isNotSame == true)
							{
								buki_index[i] = IDX;
								loop = false;
							}
						}
						else // allow same selection
						{
							buki_index[i] = IDX;
							loop = false;
						}

					}// special
				} // bomb
			}// if shurui


		}// while
	}// for i < 8
}



void mainController::all_gui_enable(bool yn)
{
	// button
	gui_manager_obj->set_enabled(roulette_button_hwd, yn);

	// pop
	gui_manager_obj->set_enabled(popup_hwd, yn);

	// check
	gui_manager_obj->set_enabled(allow_same_hwd, yn);

	for (int i = 0; i < 9; i++)
	{
		gui_manager_obj->set_enabled(weapon_check_hwd[i], yn);
	}

	for (int i = 0; i < 13; i++)
	{
		gui_manager_obj->set_enabled(sub_check_hwd[i], yn);
	}

	for (int i = 0; i < 15; i++)
	{
		gui_manager_obj->set_enabled(special_check_hwd[i], yn);
	}

	// button
	gui_manager_obj->set_enabled(language_button_hwd, yn);
}















