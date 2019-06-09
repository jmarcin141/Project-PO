#pragma once

//########## Global variables, global classes, declarations, global ... ###########################
Music music;
Music oryginalMusic;
Music effectsMusic;


//########## Effects Handle ... ###########################
EffectHandle echoEffect(EffectHandle::EffectType::ECHO);
EffectHandle distortionEffect(EffectHandle::EffectType::DISTORTION);
EffectHandle bitCrusherEffect(EffectHandle::EffectType::BITCRUSHER);
EffectHandle ringModulatorEffect(EffectHandle::EffectType::RINGMODULATOR);
EffectHandle reverseEffect(EffectHandle::EffectType::REVERSE);
EffectHandle tremoloEffect(EffectHandle::EffectType::TREMOLO);

//########## Global variables, pointers, ... ###########################
std::vector <Fl_Widget*> widgetsPtr;
std::vector <Fl_Widget*> boxesWidget;
bool loadedFiles = false;


//########## GUI ... ###########################
int initGUI(Music &mMusic, Music &mOryginal, Music &mEffectsMusic, bool openedFiles);


//########## BUTTONS ... ###########################
void but_loadSound_cb(Fl_Widget* w, void*v);
void but_saveSound_cb(Fl_Widget* w, void*v);
//void but_play_cb(Fl_Widget* w, void* v);
//void but_pause_cb(Fl_Widget* w, void* v);
//void but_loop_cb(Fl_Widget* w, void* v);
//void but_stop_cb(Fl_Widget* w, void* v);
//void but_rewind_cb(Fl_Widget* w, void* v);
//void but_forward_cb(Fl_Widget* w, void* v);
//void but_speedPlus_cb(Fl_Widget* w, void* v);
//void but_speedMinus_cb(Fl_Widget* w, void* v);
void but_changeSound_cb(Fl_Widget *w, void* v);



//########################################
//CLOSE WINDOW
//void but_exit_cb(Fl_Widget *w, void* v);


//########################################
//SLIDERS
void but_volume_set_cb(Fl_Widget *w, void *v);



//########################################
//EFFECTS
void but_resetEffects_cb(Fl_Widget *w, void* v);
void but_echo_cb(Fl_Widget *w, void* v);
void but_echo_force_set_cb(Fl_Widget *w, void* v);
void but_echo_delay_set_cb(Fl_Widget *w, void* v);
void but_distortion_cb(Fl_Widget *w, void* v);
void but_distortion_set_cb(Fl_Widget *w, void* v);
void but_bitCrusher_cb(Fl_Widget *w, void* v);
void but_bitCrusher_set_cb(Fl_Widget *w, void* v);
void but_ringModulator_cb(Fl_Widget *w, void* v);
void but_ringModulatorForce_set_cb(Fl_Widget *w, void* v);
void but_ringModulatorFreq_set_cb(Fl_Widget *w, void* v);
void but_reverse_cb(Fl_Widget *w, void* v);
void but_tremolo_cb(Fl_Widget *w, void* v);
void but_tremolo_set_cb(Fl_Widget *w, void* v);













////OLDER/////////////////////

//#define _CRT_SECURE_NO_DEPRECATE // odczyt fstream , 
//Music music;
//Music oryginalMusic;
//Music effectsMusic;

////std::unique_ptr<Music> musicPtr(new Music());
////std::vector <Fl_Widget*> effectsWidgetPtr;

//EffectHandle echoEffect(EffectHandle::EffectType::ECHO);
//EffectHandle distortionEffect(EffectHandle::EffectType::DISTORTION);
//EffectHandle bitCrusherEffect(EffectHandle::EffectType::BITCRUSHER);
//EffectHandle ringModulatorEffect(EffectHandle::EffectType::RINGMODULATOR);
//EffectHandle reverseEffect(EffectHandle::EffectType::REVERSE);
//EffectHandle tremoloEffect(EffectHandle::EffectType::TREMOLO);



//std::vector <Fl_Widget*> widgetsPtr;
//std::vector <Fl_Widget*> boxesWidget;
//bool loadedFiles = false;



////########################################
////BUTTONS 
//void but_loadSound_cb(Fl_Widget* w, void*v);
//void but_saveSound_cb(Fl_Widget* w, void*v);
////void but_play_cb(Fl_Widget* w, void* v);
////void but_pause_cb(Fl_Widget* w, void* v);
////void but_loop_cb(Fl_Widget* w, void* v);
////void but_stop_cb(Fl_Widget* w, void* v);
////void but_rewind_cb(Fl_Widget* w, void* v);
////void but_forward_cb(Fl_Widget* w, void* v);
////void but_speedPlus_cb(Fl_Widget* w, void* v);
////void but_speedMinus_cb(Fl_Widget* w, void* v);
//void but_changeSound_cb(Fl_Widget *w, void* v);
//
//
//
////########################################
////CLOSE WINDOW
////void but_exit_cb(Fl_Widget *w, void* v);
//
//
////########################################
////SLIDERS
//void but_volume_set_cb(Fl_Widget *w, void *v);
//
//
//
////########################################
////EFFECTS
//void but_resetEffects_cb(Fl_Widget *w, void* v);
//void but_echo_cb(Fl_Widget *w, void* v);
//void but_echo_force_set_cb(Fl_Widget *w, void* v);
//void but_echo_delay_set_cb(Fl_Widget *w, void* v);
//void but_distortion_cb(Fl_Widget *w, void* v);
//void but_distortion_set_cb(Fl_Widget *w, void* v);
//void but_bitCrusher_cb(Fl_Widget *w, void* v);
//void but_bitCrusher_set_cb(Fl_Widget *w, void* v);
//void but_ringModulator_cb(Fl_Widget *w, void* v);
//void but_ringModulatorForce_set_cb(Fl_Widget *w, void* v);
//void but_ringModulatorFreq_set_cb(Fl_Widget *w, void* v);
//void but_reverse_cb(Fl_Widget *w, void* v);
//void but_tremolo_cb(Fl_Widget *w, void* v);
//void but_tremolo_set_cb(Fl_Widget *w, void* v);



////########################################
////GUI
//int initGUI(Music &mMusic, Music &mOryginal, Music &mEffectsMusic, bool openedFiles);




