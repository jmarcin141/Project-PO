#pragma once
#include "headers.h"
//#include "buttons_callback.h"

class GUI
{
private:
	//Fl_Window win;
	
public:

	//GUI(Music &music);
	GUI(Music &music);

	int draw(Music &music);

	void but_loadSound_cb(Fl_Widget* w, void*v);

	void but_play_cb(Fl_Widget* w, void* v);

	void but_pause_cb(Fl_Widget* w, void* v);

	void but_loop_cb(Fl_Widget* w, void* v);

	void but_stop_cb(Fl_Widget* w, void* v);

	void but_rewind_cb(Fl_Widget* w, void* v);

	void but_forward_cb(Fl_Widget* w, void* v);


	//slider
	void but_volume_set_cb(Fl_Widget *w, void *v);


	void but_volumePlus_cb(Fl_Widget *w, void* v);

	void but_volumeMinus_cb(Fl_Widget *w, void* v);

	void but_speedPlus_cb(Fl_Widget* w, void* v);

	void but_speedMinus_cb(Fl_Widget* w, void* v);

	// ########################################
	// CLOSE WINDOW


	void but_exit_cb(Fl_Widget *w, void* v);


	//~GUI();
};