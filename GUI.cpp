#include "GUI.h"


//GUI::GUI(Music &music) {};


GUI::GUI(Music &music) 
{
};


int GUI::draw(Music &music)
{
	Fl_Window win(300, 200);
	win.color(148);

	win.begin();

	Fl_Button but_loadSound(10, 10, 110, 30, "@filenew Load Sound");
	but_loadSound.shortcut('l');
	//but_loadSound.callback(but_loadSound_cb);
	but_loadSound.color2(156);
	but_loadSound.color(156);

	Fl_Button but_saveSound(10, 130, 110, 30, "@filenew Save Sound");
	//but_loadSound.shortcut('s');
	//but_saveSound.callback(but_saveSound_cb, &music);
	but_saveSound.color2(156);
	but_saveSound.color(156);


	// slider volume
	Fl_Slider slider_volume(130, 10, 90, 15, "volume");
	slider_volume.type(FL_HOR_NICE_SLIDER);
	slider_volume.maximum(100);
	slider_volume.minimum(5);
	slider_volume.scrollvalue(100, 10, 0, 100);
	//slider_volume.callback(but_volume_set_cb, &slider_volume);
	slider_volume.color(156);
	slider_volume.color2(2); //GREEN

	//Fl_Button but_volumePlus(170, 10, 30, 30, "+");
	//but_volumePlus.callback(but_volumePlus_cb);

	//Fl_Button but_volumeMinus(130, 10, 30, 30, "-");
	//but_volumeMinus.callback(but_volumeMinus_cb);
	//

	Fl_Button but_speedMinus(230, 10, 30, 30, "@<<");
	but_speedMinus.shortcut('z');
	//but_speedMinus.callback(but_speedMinus_cb);
	but_speedMinus.color2(Fl_Color(157));
	but_speedMinus.color(Fl_Color(157));

	Fl_Button but_speedPlus(275, 10, 30, 30, "@>>");
	but_speedPlus.shortcut('x');
	//but_speedPlus.callback(but_speedPlus_cb);
	but_speedPlus.color2(Fl_Color(157));
	but_speedPlus.color(Fl_Color(157));

	Fl_Button but_exit(320, 10, 50, 30, "Exit");
	but_exit.shortcut(FL_Escape);
	but_exit.callback(but_exit_cb());
	but_exit.color2(Fl_Color(157));
	but_exit.color(Fl_Color(157));


	Fl_Button but_play(50, 50, 30, 30, "@>");
	but_play.shortcut('s');
	//but_play.callback(but_play_cb);
	but_play.color(Fl_Color(157));
	but_play.color2(Fl_Color(157));

	Fl_Button but_pause(10, 50, 30, 30, "||");
	but_pause.shortcut('p');
	//but_pause.callback(but_pause_cb);
	but_pause.color2(Fl_Color(157));
	but_pause.color(Fl_Color(157));

	Fl_Light_Button but_loop(90, 50, 30, 30, "@refresh");
	but_loop.shortcut('i');
	//but_loop.callback(but_loop_cb);
	but_loop.color2(Fl_Color(171));
	but_loop.color(Fl_Color(157));

	Fl_Button but_stop(50, 90, 30, 30, "@square");
	but_stop.shortcut('o');
	//but_stop.callback(but_stop_cb);
	but_stop.color2(Fl_Color(157));
	but_stop.color(Fl_Color(157));

	Fl_Button but_rewind(10, 90, 30, 30, "@|<");
	but_rewind.shortcut('a');
	//but_rewind.callback(but_rewind_cb);
	but_rewind.color2(Fl_Color(157));
	but_rewind.color(Fl_Color(157));

	Fl_Button but_forward(90, 90, 30, 30, "@>|");
	but_forward.shortcut('d');
	//but_forward.callback(but_forward_cb);
	but_forward.color2(Fl_Color(157));
	but_forward.color(Fl_Color(157));


	// Effects Buttons
	Echo echo;

	Fl_Check_Button but_echo(230, 60, 100, 30, "Echo");
	//but_echo.callback(but_echo_cb, &music);
	but_echo.color2(Fl_Color(58));
	but_echo.color(Fl_Color(157));

	// Sliders for effects
	//Echo
	Fl_Value_Slider slider_echo_force(230, 90, 140, 15, "Force [%]");
	slider_echo_force.type(FL_HOR_NICE_SLIDER);
	slider_echo_force.maximum(200);
	slider_echo_force.minimum(5);
	slider_echo_force.scrollvalue(100, 1, 0, 200);
	//slider_echo_force.callback(but_volume_set_cb, &slider_echo_force);
	slider_echo_force.color(156);
	slider_echo_force.color2(2); //GREEN


	// Sliders for effects
	Fl_Value_Slider slider_echo_delay(230, 130, 140, 15, "Delay [ms]");
	slider_echo_delay.type(FL_HOR_NICE_SLIDER);
	slider_echo_delay.maximum(5000);
	slider_echo_delay.minimum(10);
	slider_echo_delay.scrollvalue(100, 10, 0, 5000);
	//slider_echo_delay.callback(but_volume_set_cb, &slider_echo_delay);
	slider_echo_delay.color(156);
	slider_echo_delay.color2(2); //GREEN

	// Distortion
	Fl_Check_Button but_distortion(230, 190, 100, 30, "Distortion");
	//but_loop.callback(but_loop_cb);
	but_distortion.color2(Fl_Color(58));
	but_distortion.color(Fl_Color(157));

	Fl_Value_Slider slider_distortion(230, 220, 140, 15, "Level of amplitude");
	slider_distortion.type(FL_HOR_NICE_SLIDER);
	slider_distortion.maximum(100);
	slider_distortion.minimum(5);
	slider_distortion.scrollvalue(100, 10, 0, 100);
	//slider_distortion.callback(but_volume_set_cb, &slider_distortion);
	slider_distortion.color(156);
	slider_distortion.color2(2); //GREEN

	//Wah-Wah
	Fl_Check_Button but_wah_wah(230, 270, 100, 30, "Wah-Wah");
	//but_loop.callback(but_loop_cb);
	but_wah_wah.color2(Fl_Color(58));
	but_wah_wah.color(Fl_Color(157));

	Fl_Value_Slider slider_wah_wah(230, 300, 140, 15, "Wah-Wah");
	slider_wah_wah.type(FL_HOR_NICE_SLIDER);
	slider_wah_wah.maximum(100);
	slider_wah_wah.minimum(5);
	slider_wah_wah.scrollvalue(100, 10, 0, 100);
	//slider_wah_wah.callback(but_volume_set_cb, &slider_wah_wah);
	slider_wah_wah.color(156);
	slider_wah_wah.color2(2); //GREEN



	win.end();
	win.show();
	return(Fl::run());
}

void GUI::but_loadSound_cb(Fl_Widget* w, void*v)
{
	//((Fl_Window*)v)->hide()
	((Music*)v)->loadSound();
	//music.loadSound();
	std::cout << std::endl << "Button loadSound callback!" << std::endl;
}

void GUI::but_play_cb(Fl_Widget* w, void* v)
{
	((Music*)v)->playSoud();
	std::cout << std::endl << "Button play callback!" << std::endl;
}

void GUI::but_pause_cb(Fl_Widget* w, void* v)
{
	((Music*)v)->pauseSound();
	std::cout << std::endl << "Button pause callback!" << std::endl;
}

// ########################################
// CLOSE WINDOW


void GUI::but_exit_cb()//(Fl_Widget *w, void* v)
{
	if (fl_ask("Do you want to exit?"))
	{
		((Fl_Window*)v)->hide();//zamkniecie okna glownego win, przy pomocy wskaznika
	}
}
