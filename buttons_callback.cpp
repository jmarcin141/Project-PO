////////#include "buttons_callback.h"
////////
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
