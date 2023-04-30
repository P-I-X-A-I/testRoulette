#include "stdafx.h"
#include "mainController.h"


void mainController::message_from_GUI(UINT message, int ID, int EVENT, LPARAM param)
{
	int hi_word = HIWORD(param);
	int lo_word = LOWORD(param);
	NMHDR* temp_handler = (NMHDR*)param;

	if (message == WM_LBUTTONDOWN)
	{
	
	}
	// WM_LBUTTONDBLCLK
	// WM_RBUTTONUP......
	//

	switch (ID)
	{
	case 1001:// roulette button

		printf("roulette button pushed.\n");
		this->roulette_button();
		break;

	case 1003: // allow same selection checkbox
		printf("allow same selection\n");
		is_allow_same_selection = gui_manager_obj->get_checkbox_state(allow_same_hwd);
		
		break;
	
	case 1004:// popup
		if (EVENT == CBN_SELCHANGE)
		{
			printf("popup\n");
			this->popup_selected();
		}
		break;




	case 3000:
		if (EVENT == BN_CLICKED)
		{
			this->language_button();
		}
		break;
	}

	// check box
	if (ID >= 1500 && ID < 1509 && EVENT == BN_CLICKED)
	{
		for (int i = 0; i < 9; i++)
		{
			bool yn = gui_manager_obj->get_checkbox_state(weapon_check_hwd[i]);
			is_weapon_type[i] = yn;
			printf("weapon check %d\n", yn);

		}
	}


	if (ID >= 1600 && ID < 1613 && EVENT == BN_CLICKED)
	{
		for( int i = 0 ; i < 13 ; i++ )
		{
			bool yn = gui_manager_obj->get_checkbox_state(sub_check_hwd[i]);
			is_sub_type[i] = yn;
			printf("sub type %d\n", yn);
		}
	}

	if (ID >= 1700 && ID < 1715 && EVENT == BN_CLICKED)
	{
		for (int i = 0; i < 15; i++)
		{
			bool yn = gui_manager_obj->get_checkbox_state(special_check_hwd[i]);
			is_special_type[i] = yn;
			printf("special type %d\n", yn);
		}
	}

}


void mainController::enter_key()
{
	this->roulette_button();
}

void mainController::roulette_button()
{
	int COUNT = 0;

	for (int i = 0; i < BUKI_NUM; i++)
	{
		int SHURUI = attr_weapon[i];
		int BOMB = attr_bomb[i];
		int SP = attr_special[i];

		if (is_weapon_type[SHURUI])
		{
			if (is_sub_type[BOMB])
			{
				if (is_special_type[SP])
				{
					COUNT++;
				}
			}
		}
	}
	printf("num of target weapon %d\n", COUNT);


	if (is_allow_same_selection )
	{
		if (COUNT == 0)
		{
			// alert
			if (is_Japanese)
			{
				MessageBox(NULL, L"ブキが少なすぎます。", L"alert", MB_OK);
			}
			else
			{
				MessageBox(NULL, L"Target weapons are less to run the roulette.", L"alert", MB_OK);

			}
			return;
		}
	}
	else
	{
		if (COUNT < 8)
		{
			// alert
						// alert
			if (is_Japanese)
			{
				MessageBox(NULL, L"ブキが少なすぎます。", L"alert", MB_OK);
			}
			else
			{
				MessageBox(NULL, L"Target weapons are less to run the roulette.", L"alert", MB_OK);

			}
			return;
		}
	}




	if (is_Roulette == false)
	{
	
		srand(time(NULL));

		// play sound

		//PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound(L"roulette.wav", NULL, SND_FILENAME | SND_ASYNC);

		PlaySound(NULL, NULL, SND_RESOURCE | SND_ASYNC);
		PlaySound(MAKEINTRESOURCE(380), mainInst, SND_RESOURCE | SND_ASYNC);

		// set variables
		is_Roulette = true;
		ROULETTE_COUNTER = 0;

		this->all_gui_enable(false);
	}

}



void mainController::popup_selected()
{
	int selected = gui_manager_obj->get_combobox_selected_index(popup_hwd);
	printf("%d\n", selected);

	// hide all checkbox
	for (int i = 0; i < 9; i++)
	{
		gui_manager_obj->set_hidden(weapon_check_hwd[i], true);
	}

	for (int i = 0; i < 13; i++)
	{
		gui_manager_obj->set_hidden(sub_check_hwd[i], true);
	}

	for (int i = 0; i < 15; i++)
	{
		gui_manager_obj->set_hidden(special_check_hwd[i], true);
	}


	switch (selected)
	
	{
	case 0:
		for (int i = 0; i < 9; i++)
		{
			gui_manager_obj->set_hidden(weapon_check_hwd[i], false);
		}
		break;
	case 1:
		for (int i = 0; i < 13; i++)
		{
			gui_manager_obj->set_hidden(sub_check_hwd[i], false);
		}
		break;
	case 2:
		for (int i = 0; i < 15; i++)
		{
			gui_manager_obj->set_hidden(special_check_hwd[i], false);
		}
		break;
	default:
		break;
	}

}


void mainController::language_button()
{
	is_Japanese = !is_Japanese;

	if (is_Japanese)
	{
		// text field
		gui_manager_obj->set_textfield_string(filter_text_hwd, L"条件を設定する", FONT_NORMAL);

		// same selection
		gui_manager_obj->set_checkbox_string(allow_same_hwd, L"ブキかぶり有り", FONT_NORMAL);


		// check box
		for (int i = 0; i < 9; i++)
		{
			gui_manager_obj->set_checkbox_string(weapon_check_hwd[i], weapon_w_str_JP[i], FONT_NORMAL);
		}
		for (int i = 0; i < 13; i++)
		{
			gui_manager_obj->set_checkbox_string(sub_check_hwd[i], sub_w_str_JP[i], FONT_NORMAL);
		}
		for (int i = 0; i < 15; i++)
		{
			gui_manager_obj->set_checkbox_string(special_check_hwd[i], special_w_str_JP[i], FONT_NORMAL);
		}


		// language button
		gui_manager_obj->set_button_string(language_button_hwd, L"English", FONT_NORMAL);
	}
	else
	{
		gui_manager_obj->set_textfield_string(filter_text_hwd, L"Set filters", FONT_NORMAL);

		gui_manager_obj->set_checkbox_string(allow_same_hwd, L"Allow same selection", FONT_NORMAL);

		
		for (int i = 0; i < 9; i++)
		{
			gui_manager_obj->set_checkbox_string(weapon_check_hwd[i], weapon_w_str_EN[i], FONT_NORMAL);
		}
		for (int i = 0; i < 13; i++)
		{
			gui_manager_obj->set_checkbox_string(sub_check_hwd[i], sub_w_str_EN[i], FONT_NORMAL);
		}
		for (int i = 0; i < 15; i++)
		{
			gui_manager_obj->set_checkbox_string(special_check_hwd[i], special_w_str_EN[i], FONT_NORMAL);
		}

		gui_manager_obj->set_button_string(language_button_hwd, L"日本語", FONT_NORMAL);

	}
}