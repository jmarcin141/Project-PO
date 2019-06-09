/*class GUI
{
public:

	GUI() {};
	
	void my_callback(Fl_Widget *);
	static void my_static_callback(Fl_Widget *w, void *userData) 
	{ 
		GUI *g = (GUI*)userData;
		g->my_callback(w);
	}


	void but_play_cb(Fl_Widget* w, void* v)
	{
		std::cout << std::endl << "Button play/stop callback!" << std::endl;
		((Music*)v)->playSoud();
	}
	~GUI();
};*/













//#pragma once
//
//#include "headers.h"
//
//class GUI// : public Fl_Widget, Fl_Button
//{
//public:
//	GUI();
//
//
//	void my_callback(Fl_Widget *w);
//	static void my_static_callback(Fl_Widget *w, void *f);// { ((GUI*)f)->my_callback(w); };
//
//	void but_play_cb(Fl_Widget* w, void* v);
//
//	w->callback(my_static_callback, (void*)this);
//	//void but_pause_cb(Fl_Widget* w, void* v);
//	//void but_loop_cb(Fl_Widget* w, void* v);
//	//void but_stop_cb(Fl_Widget* w, void* v);
//	//void but_rewind_cb(Fl_Widget* w, void* v);
//	//void but_forward_cb(Fl_Widget* w, void* v);
//	//void but_speedPlus_cb(Fl_Widget* w, void* v);
//	//void but_speedMinus_cb(Fl_Widget* w, void* v);
//
//	//########################################
//	//CLOSE WINDOW
//	//void but_exit_cb(Fl_Widget *w, void* v);
//
//	~GUI();
//};








////#pragma once
////#include "headers.h"
////
////#include "deactivateAllWidgetsInVectorOfPointers.h"
////
////#include "printTimeMusic.h"
////#include "printMusicList.h"
////
//////#include "buttons_callback.h"
////
////class GUI : public Fl_Widget, Fl_Input, Fl_Box, Fl_Button
////{
////private:
////	//Fl_Window win;
////	Music music; 
////	Music oryginalMusic;
////	Music effectsMusic;
////	bool openedFiles;
////
////	
////public:
////
////	//EffectHandle echoEffect;
////	//EffectHandle distortionEffect;
////	//EffectHandle bitCrusherEffect;
////	//EffectHandle ringModulatorEffect;
////	//EffectHandle reverseEffect;
////	//EffectHandle tremoloEffect;
////
////	std::vector <Fl_Widget*> widgetsPtr;
////	std::vector <Fl_Widget*> boxesWidget;
////	bool loadedFiles = false;
////
////
////
////
////
////	//GUI(Music &music);
////	GUI(int x, int y, int w, int h, const char *label, Music &mMusic, Music &mOryginal, Music &mEffectsMusic, bool mOpenedFiles);
////
////
////	//int draw(Music &music);
////
////	//########################################
////	//DEFINITIONS OF FUNCTIONS
////	int initGUI();
////
////
////	//definitions of functions for sound
////	void but_loadSound_cb(Fl_Widget* w, void* v);
////
////	void but_saveSound_cb(Fl_Widget* w, void*v);
////
////	void but_play_cb(Fl_Widget* w, void* v);
////
////	void but_pause_cb(Fl_Widget* w, void* v);
////
////	void but_loop_cb(Fl_Widget* w, void* v);
////
////	void but_stop_cb(Fl_Widget* w, void* v);
////
////	void but_rewind_cb(Fl_Widget* w, void* v);
////
////	void but_forward_cb(Fl_Widget* w, void* v);
////
////
////	//slider
////	void but_volume_set_cb(Fl_Widget *w, void *v);
////
////	void but_speedPlus_cb(Fl_Widget* w, void* v);
////
////	void but_speedMinus_cb(Fl_Widget* w, void* v);
////
////	//########################################
////	//CLOSE WINDOW
////	void but_exit_cb(Fl_Widget *w, void* v);
////
////
////	void but_changeSound_cb(Fl_Widget *w, void* v);
////
////	void but_resetEffects_cb(Fl_Widget *w, void* v);
////
////	void but_echo_cb(Fl_Widget *w, void* v);
////
////	void but_echo_force_set_cb(Fl_Widget *w, void* v);
////
////	void but_echo_delay_set_cb(Fl_Widget *w, void* v);
////
////	void but_distortion_cb(Fl_Widget *w, void* v);
////
////	void but_distortion_set_cb(Fl_Widget *w, void* v);
////
////	void but_bitCrusher_cb(Fl_Widget *w, void* v);
////
////	void but_bitCrusher_set_cb(Fl_Widget *w, void* v);
////
////	void but_ringModulator_cb(Fl_Widget *w, void* v);
////
////	void but_ringModulatorForce_set_cb(Fl_Widget *w, void* v);
////
////	void but_ringModulatorFreq_set_cb(Fl_Widget *w, void* v);
////
////	void but_reverse_cb(Fl_Widget *w, void* v);
////
////
////	void but_tremolo_cb(Fl_Widget *w, void* v);
////
////	void but_tremolo_set_cb(Fl_Widget *w, void* v);
////
////	//~GUI();
////};