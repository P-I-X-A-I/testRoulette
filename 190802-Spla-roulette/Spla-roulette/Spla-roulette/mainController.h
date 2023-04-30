#pragma once
/*
#include "glew.h"
#include "wglew.h"

#include <gl\GL.h> // in system folder
#include <gl\GLU.h>// in system folder

#pragma comment (lib, "opengl32.lib") // in system folder
#pragma comment (lib, "glew32.lib") // in own folder

*/
// for PNG image




#include "GUI_ManagerClass.h"
#include "OpenGLInitializerClass.h"
#include "matrixClass.h"
#include "shaderLoaderClass.h"
#include "WindowManagerClass.h"

#define BUKI_NUM 129

class mainController
{
public:

	HINSTANCE mainInst;

	// variables
	int winWidth = 0;
	int winHeight = 0;
	int viewWidth = 0;
	int viewHeight = 0;
	int guiWidth = 0;

	GUI_ManagerClass* gui_manager_obj;
	OpenGLInitializerClass* openGL_initializer_obj;
	matrixClass* mvp_matrix_obj;
	shaderLoaderClass* shaderloader_obj;
	WindowManagerClass* window_manager_obj;

	// window handler
	HWND main_window_obj;
	HWND openGL_view_wnd;

	// GUI handler
	HWND roulette_button_hwd;
	HWND filter_text_hwd;
	HWND allow_same_hwd;
	HWND popup_hwd;

	HWND weapon_check_hwd[9];
	HWND sub_check_hwd[13];
	HWND special_check_hwd[15];

	HWND language_button_hwd;

	const wchar_t* weapon_w_str_JP[9];
	const wchar_t* sub_w_str_JP[13];
	const wchar_t* special_w_str_JP[15];
	const wchar_t* weapon_w_str_EN[9];
	const wchar_t* sub_w_str_EN[13];
	const wchar_t* special_w_str_EN[15];

	int attr_weapon[BUKI_NUM];
	int attr_bomb[BUKI_NUM];
	int attr_special[BUKI_NUM];

	bool is_Japanese = true;
	bool is_Roulette = false;
	bool is_allow_same_selection = true;
	bool is_weapon_type[9];
	bool is_sub_type[13];
	bool is_special_type[15];
	int ROULETTE_COUNTER = 0;

	int buki_index[8];

	LPTSTR hSound; // sound

	float act_anim_scale = 1.0;

	// shader
	const GLchar* simple_vs_ptr;
	const GLchar* simple_fs_ptr;
	GLuint SIMPLE_PRG;
	GLuint SIMPLE_VS;
	GLuint SIMPLE_FS;
	GLint UNF_SIMPLE_mvpMatrix;
	GLint UNF_SIMPLE_color;

	const char* tex_vs_ptr;
	const char* tex_fs_ptr;
	GLuint TEX_PRG;
	GLuint TEX_FS;
	GLuint TEX_VS;
	GLint UNF_TEX_mvpMatrix;
	GLint UNF_TEX_texImage;


	// VAO VBO
	GLuint VAO_SIMPLE_name;
	GLuint VBO_SIMPLE_name;

	GLuint VAO_TEX_name;
	GLuint VBO_TEX_name[3];


	// texture
	GLuint Sampler_name;
	GLuint BUKI_TEX_name[BUKI_NUM];
	unsigned char* pngPtr[BUKI_NUM];
	unsigned long pngDataSize[BUKI_NUM];
	unsigned char* pixPtr[BUKI_NUM];


	mainController();
	~mainController();


	void setup();
	void drawGL();

	void loadPNG(unsigned char* pointer, unsigned long dataSize, unsigned char** toPtr);

	void select_buki_shurui();
	void decide_buki();

	void set_buki_vertex(GLfloat* vptr, int index, float scale);
	//
	void setup_gui();

	// from GUI
	void message_from_GUI(UINT message, int ID, int EVENT, LPARAM param);
	void roulette_button();
	void popup_selected();
	void language_button();
	void enter_key();
	void all_gui_enable(bool yn);
};

