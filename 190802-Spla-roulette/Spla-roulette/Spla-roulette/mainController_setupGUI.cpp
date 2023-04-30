#include "stdafx.h"
#include "mainController.h"

void mainController::setup_gui()
{
	int LEFT = viewWidth + 10;
	int WIDTH = guiWidth - 40;

	// set button
	roulette_button_hwd = gui_manager_obj->create_button(main_window_obj,
		L"ルーレット！ ( Roulette! )",
		LEFT,
		10,
		WIDTH,
		40,
		1001);


	// set text
	filter_text_hwd = gui_manager_obj->create_textfield(main_window_obj,
		L"条件を設定する",
		LEFT, 80,
		WIDTH, 20,
		1002);


	// set checkbox
	allow_same_hwd = gui_manager_obj->create_checkbox(main_window_obj,
		L"ブキかぶり有り",
		LEFT, 100,
		WIDTH, 20,
		1003);
	gui_manager_obj->set_checkbox_state(allow_same_hwd, true);


	// popup
	popup_hwd = gui_manager_obj->create_combobox(main_window_obj,
		LEFT, 150,
		WIDTH, 120,
		1004);

	gui_manager_obj->delete_combobox_all(popup_hwd);
	gui_manager_obj->add_combobox_item(popup_hwd, L"weapon");
	gui_manager_obj->add_combobox_item(popup_hwd, L"sub weapon");
	gui_manager_obj->add_combobox_item(popup_hwd, L"special");
	gui_manager_obj->set_combobox_selected_item_at_index(popup_hwd, 0);


	// view
	
	for (int i = 0; i < 9; i++)
	{
		weapon_check_hwd[i] = gui_manager_obj->create_checkbox(main_window_obj,
			weapon_w_str_JP[i],
			LEFT, i * 20 + 180,
			WIDTH, 20,
			1500 + i);

		gui_manager_obj->set_checkbox_state(weapon_check_hwd[i], true);
	}
	


	for (int i = 0; i < 13; i++)
	{
		sub_check_hwd[i] = gui_manager_obj->create_checkbox(main_window_obj,
			sub_w_str_JP[i],
			LEFT, i * 20 + 180,
			WIDTH, 20,
			1600 + i);

		gui_manager_obj->set_checkbox_state(sub_check_hwd[i], true);
		ShowWindow(sub_check_hwd[i], SW_HIDE);
	}


	for (int i = 0; i < 15; i++)
	{
		special_check_hwd[i] = gui_manager_obj->create_checkbox(main_window_obj,
			special_w_str_JP[i],
			LEFT, i * 20 + 180,
			WIDTH, 20,
			1700 + i);

		gui_manager_obj->set_checkbox_state(special_check_hwd[i], true);
		ShowWindow(special_check_hwd[i], SW_HIDE);
	}


	// language button
	language_button_hwd = gui_manager_obj->create_button(main_window_obj,
		L"English",
		LEFT + 20, winHeight - 100,
		guiWidth - 75, 35,
		3000);
}