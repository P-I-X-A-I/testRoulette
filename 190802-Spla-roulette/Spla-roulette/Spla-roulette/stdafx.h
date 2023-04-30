// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、
// または、参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
// Windows ヘッダー ファイル
#include <windows.h>

// C ランタイム ヘッダー ファイル
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// プログラムに必要な追加ヘッダーをここで参照してください
// for C
#include "stdio.h"
#include "time.h"
#include "math.h"


#include "glew.h"
#include "wglew.h"

#include <gl\GL.h> // in system folder
#include <gl\GLU.h>// in system folder

#pragma comment (lib, "opengl32.lib") // in system folder
#pragma comment (lib, "glew32.lib") // in own folder

#include "png.h"
#pragma comment (lib, "libpng16.lib")
//#pragma comment (lib, "zlib.lib")
#include "mmsystem.h"
#pragma comment (lib, "winmm.lib") // playsound
