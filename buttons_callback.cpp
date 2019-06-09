#include "buttons_callback.h"


void but_play_cb(Fl_Widget* w, void* v)
{
	std::cout << std::endl << "Button play/stop callback!" << std::endl;
	((Music*)v)->playSoud();
}

void but_pause_cb(Fl_Widget* w, void* v)
{
	//music.pauseSound();
	((Music*)v)->pauseSound();
	std::cout << std::endl << "Button pause callback!" << std::endl;
}

void but_loop_cb(Fl_Widget* w, void* v)
{
	//music.loopSound();
	((Music*)v)->loopSound();
	std::cout << std::endl << "Button loop callback!" << std::endl;
}

void but_stop_cb(Fl_Widget* w, void* v)
{
	//music.stopSound();
	((Music*)v)->stopSound();
	std::cout << std::endl << "Button stop callback!" << std::endl;
}

void but_rewind_cb(Fl_Widget* w, void* v)
{
	//music.rewindSound();
	((Music*)v)->rewindSound();
	std::cout << std::endl << "Button rewind callback!" << std::endl;
}

void but_forward_cb(Fl_Widget* w, void* v)
{
	//music.forwardSound();
	((Music*)v)->forwardSound();
	std::cout << std::endl << "Button forward callback!" << std::endl;
}


void but_speedPlus_cb(Fl_Widget* w, void* v)
{
	//music.speedPlus();
	((Music*)v)->speedPlus();
	std::cout << std::endl << "Button speed plus callback!" << std::endl;
}

void but_speedMinus_cb(Fl_Widget* w, void* v)
{
	//music.speedMinus();
	((Music*)v)->speedMinus();
	std::cout << std::endl << "Button slow callback!" << std::endl;
}

//########################################
//CLOSE WINDOW
void but_exit_cb(Fl_Widget *w, void* v)
{
	if (fl_ask("Do you want to exit without save new music?"))
	{
		((Fl_Window*)v)->hide();//zamkniecie okna glownego win, przy pomocy wskaznika
	}
}




//void but_loadSound_cb(Fl_Widget* w, void*v)
//{
//	//((Fl_Window*)v)->hide()
//	((Music*)v)->loadSound();
//	//music.loadSound();
//	std::cout << std::endl << "Button loadSound callback!" << std::endl;
//}
//
//////void but_play_cb(Fl_Widget* w, void* v)
//////{
//////	std::cout << std::endl << "Button play/stop callback!" << std::endl;
//////	((Music*)v)->playSoud();
//////}


//
//void but_pause_cb(Fl_Widget* w, void* v)
//{
//	((Music*)v)->pauseSound();
//	std::cout << std::endl << "Button pause callback!" << std::endl;
//}




//void but_loadSound_cb(Fl_Widget* w, void*v)
//{
//	//((Fl_Window*)v)->hide()
//	music.loadSound();
//	std::cout << std::endl << "Button loadSound callback!" << std::endl;
//}

//void but_play_cb(Fl_Widget* w, void* v)
//{
//	music.playSoud();
//	std::cout << std::endl << "Button play callback!" << std::endl;
//}
//
//void but_pause_cb(Fl_Widget* w, void* v)
//{
//	music.pauseSound();
//	std::cout << std::endl << "Button pause callback!" << std::endl;
//}
//
//void but_loop_cb(Fl_Widget* w, void* v)
//{
//	music.loopSound();
//	std::cout << std::endl << "Button loop callback!" << std::endl;
//}
//
//void but_stop_cb(Fl_Widget* w, void* v)
//{
//	music.stopSound();
//	std::cout << std::endl << "Button stop callback!" << std::endl;
//}
//
//void but_rewind_cb(Fl_Widget* w, void* v)
//{
//	music.rewindSound();
//	std::cout << std::endl << "Button rewind callback!" << std::endl;
//}
//
//void but_forward_cb(Fl_Widget* w, void* v)
//{
//	music.forwardSound();
//	std::cout << std::endl << "Button forward callback!" << std::endl;
//}
//
////slider
//void but_volume_set_cb(Fl_Widget *w, void *v)
//{
//	music.setVolume(((Fl_Value_Slider*)v)->value());
//	//((Fl_Window*)v)->hide()
//}
//
//
//void but_volumePlus_cb(Fl_Widget *w, void* v)
//{
//	music.volumePlus();
//	std::cout << std::endl << "Button volume plus callback!" << std::endl;
//}
//
//void but_volumeMinus_cb(Fl_Widget *w, void* v)
//{
//	music.volumeMinus();
//	std::cout << std::endl << "Button volume minus callback!" << std::endl;
//}
//
//void but_speedPlus_cb(Fl_Widget* w, void* v)
//{
//	music.speedPlus();
//	std::cout << std::endl << "Button speed plus callback!" << std::endl;
//}
//
//void but_speedMinus_cb(Fl_Widget* w, void* v)
//{
//	music.speedMinus();
//	std::cout << std::endl << "Button slow callback!" << std::endl;
//}
//
//// ########################################
//// CLOSE WINDOW
//
//
//void but_exit_cb(Fl_Widget *w, void* v)
//{
//	if (fl_ask("Do you want to exit?"))
//	{
//		((Fl_Window*)v)->hide();//zamkniecie okna glownego win, przy pomocy wskaznika
//	}
//}




//
//void but_echo_cb(Fl_Widget *w, void* v)
//{
//	std::cout << std::endl << "Button echo callback!" << std::endl;
//	//((Echo*)v)->setEcho(music);
//	std::vector<sf::Int16> samples = ((Music*)v)->getSamples();
//	std::vector<sf::Int16> samples2;
//	Music m;
//	m.loadSamples(samples, m.fs);
//	EffectHandle efect(EffectHandle::EffectType::ECHO);
//	samples2 = efect.effect(m);
//	music.loadSamples(samples2, music.fs);
//}


////////void but_loadSound_cb(Fl_Widget* w, void*v)
////////{
////////	//((Fl_Window*)v)->hide()
////////	((Music*)v)->loadSound();
////////	//music.loadSound();
////////	std::cout << std::endl << "Button loadSound callback!" << std::endl;
////////}
////////
////////
////////void but_play_cb(Fl_Widget* w, void* v)
////////{
////////	((Music*)v)->playSoud();
////////	std::cout << std::endl << "Button play callback!" << std::endl;
////////}
////////
////////void but_pause_cb(Fl_Widget* w, void* v)
////////{
////////	((Music*)v)->pauseSound();
////////	std::cout << std::endl << "Button pause callback!" << std::endl;
////////}
////////
////////void but_loop_cb(Fl_Widget* w, void* v)
////////{
////////	((Music*)v)->loopSound();
////////	std::cout << std::endl << "Button loop callback!" << std::endl;
////////}
////////
////////void but_stop_cb(Fl_Widget* w, void* v)
////////{
////////	((Music*)v)->stopSound();
////////	std::cout << std::endl << "Button stop callback!" << std::endl;
////////}
////////
////////void but_rewind_cb(Fl_Widget* w, void* v)
////////{
////////	((Music*)v)->rewindSound();
////////	std::cout << std::endl << "Button rewind callback!" << std::endl;
////////}
////////
////////void but_forward_cb(Fl_Widget* w, void* v)
////////{
////////	((Music*)v)->forwardSound();
////////	std::cout << std::endl << "Button forward callback!" << std::endl;
////////}
////////
