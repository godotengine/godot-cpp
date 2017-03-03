#ifndef INPUTEVENT_H
#define INPUTEVENT_H

#include <cstdint>

#include "String.h"

namespace godot {


enum {
	BUTTON_LEFT=1,
	BUTTON_RIGHT=2,
	BUTTON_MIDDLE=3,
	BUTTON_WHEEL_UP=4,
	BUTTON_WHEEL_DOWN=5,
	BUTTON_WHEEL_LEFT=6,
	BUTTON_WHEEL_RIGHT=7,
	BUTTON_MASK_LEFT=(1<<(BUTTON_LEFT-1)),
	BUTTON_MASK_RIGHT=(1<<(BUTTON_RIGHT-1)),
	BUTTON_MASK_MIDDLE=(1<<(BUTTON_MIDDLE-1)),

};

enum {

	JOY_BUTTON_0 = 0,
	JOY_BUTTON_1 = 1,
	JOY_BUTTON_2 = 2,
	JOY_BUTTON_3 = 3,
	JOY_BUTTON_4 = 4,
	JOY_BUTTON_5 = 5,
	JOY_BUTTON_6 = 6,
	JOY_BUTTON_7 = 7,
	JOY_BUTTON_8 = 8,
	JOY_BUTTON_9 = 9,
	JOY_BUTTON_10 = 10,
	JOY_BUTTON_11 = 11,
	JOY_BUTTON_12 = 12,
	JOY_BUTTON_13 = 13,
	JOY_BUTTON_14 = 14,
	JOY_BUTTON_15 = 15,
	JOY_BUTTON_MAX = 16,

	JOY_L = JOY_BUTTON_4,
	JOY_R = JOY_BUTTON_5,
	JOY_L2 = JOY_BUTTON_6,
	JOY_R2 = JOY_BUTTON_7,
	JOY_L3 = JOY_BUTTON_8,
	JOY_R3 = JOY_BUTTON_9,
	JOY_SELECT = JOY_BUTTON_10,
	JOY_START = JOY_BUTTON_11,
	JOY_DPAD_UP = JOY_BUTTON_12,
	JOY_DPAD_DOWN = JOY_BUTTON_13,
	JOY_DPAD_LEFT = JOY_BUTTON_14,
	JOY_DPAD_RIGHT = JOY_BUTTON_15,

	// a little history about game controllers (who copied who)

	JOY_SNES_B = JOY_BUTTON_0,
	JOY_SNES_A = JOY_BUTTON_1,
	JOY_SNES_Y = JOY_BUTTON_2,
	JOY_SNES_X = JOY_BUTTON_3,

	JOY_SONY_CIRCLE=JOY_SNES_A,
	JOY_SONY_X=JOY_SNES_B,
	JOY_SONY_SQUARE=JOY_SNES_Y,
	JOY_SONY_TRIANGLE=JOY_SNES_X,

	JOY_SEGA_B=JOY_SNES_A,
	JOY_SEGA_A=JOY_SNES_B,
	JOY_SEGA_X=JOY_SNES_Y,
	JOY_SEGA_Y=JOY_SNES_X,

	JOY_XBOX_B=JOY_SEGA_B,
	JOY_XBOX_A=JOY_SEGA_A,
	JOY_XBOX_X=JOY_SEGA_X,
	JOY_XBOX_Y=JOY_SEGA_Y,

	JOY_DS_A = JOY_SNES_A,
	JOY_DS_B = JOY_SNES_B,
	JOY_DS_X = JOY_SNES_X,
	JOY_DS_Y = JOY_SNES_Y,

	JOY_WII_C = JOY_BUTTON_5,
	JOY_WII_Z = JOY_BUTTON_6,

	JOY_WII_MINUS = JOY_BUTTON_9,
	JOY_WII_PLUS = JOY_BUTTON_10,

	// end of history

	JOY_AXIS_0=0,
	JOY_AXIS_1=1,
	JOY_AXIS_2=2,
	JOY_AXIS_3=3,
	JOY_AXIS_4=4,
	JOY_AXIS_5=5,
	JOY_AXIS_6=6,
	JOY_AXIS_7=7,
	JOY_AXIS_MAX=8,

	JOY_ANALOG_0_X = JOY_AXIS_0,
	JOY_ANALOG_0_Y = JOY_AXIS_1,

	JOY_ANALOG_1_X = JOY_AXIS_2,
	JOY_ANALOG_1_Y = JOY_AXIS_3,

	JOY_ANALOG_2_X = JOY_AXIS_4,
	JOY_ANALOG_2_Y = JOY_AXIS_5,

	JOY_ANALOG_L2 = JOY_AXIS_6,
	JOY_ANALOG_R2 = JOY_AXIS_7,
};


/**
 * Input Modifier Status
 * for keyboard/mouse events.
 */
struct InputModifierState {

	bool shift;
	bool alt;
#ifdef APPLE_STYLE_KEYS
	union {
	bool command;
	bool meta; //< windows/mac key
	};

	bool control;
#else
	union {
	bool command; //< windows/mac key
	bool control;
	};
	bool meta; //< windows/mac key

#endif

	bool operator==(const InputModifierState& rvalue) const {

		return ( (shift==rvalue.shift) && (alt==rvalue.alt) && (control==rvalue.control) && (meta==rvalue.meta));
	}
};






struct InputEventKey  {

	InputModifierState mod;

	bool pressed; /// otherwise release

	uint32_t scancode; ///< check keyboard.h , KeyCode enum, without modifier masks
	uint32_t unicode; ///unicode

	bool echo; /// true if this is an echo key
};


struct InputEventMouse  {

	InputModifierState mod;
	int button_mask;
	float x,y;
	float global_x,global_y;
	int pointer_index;
};

struct InputEventMouseButton : public InputEventMouse {


	int button_index;
	bool pressed; //otherwise released
	bool doubleclick; //last even less than doubleclick time

};

struct InputEventMouseMotion : public InputEventMouse {

	float relative_x,relative_y;
	float speed_x,speed_y;
};

struct InputEventJoypadMotion  {

	int axis; ///< Joypad axis
	float axis_value; ///< -1 to 1
};

struct InputEventJoypadButton  {

	int button_index;
	bool pressed;
	float pressure; //0 to 1
};

struct InputEventScreenTouch  {

	int index;
	float x,y;
	bool pressed;
};
struct InputEventScreenDrag  {

	int index;
	float x,y;
	float relative_x,relative_y;
	float speed_x,speed_y;
};

struct InputEventAction  {

	int action;
	bool pressed;
};



struct InputEvent {

	enum Type {
		NONE,
		KEY,
		MOUSE_MOTION,
		MOUSE_BUTTON,
		JOYPAD_MOTION,
		JOYPAD_BUTTON,
		SCREEN_TOUCH,
		SCREEN_DRAG,
		ACTION,
		TYPE_MAX
	};

	uint32_t ID;
	int type;
	int device;

	union {
		InputEventMouseMotion mouse_motion;
		InputEventMouseButton mouse_button;
		InputEventJoypadMotion joy_motion;
		InputEventJoypadButton joy_button;
		InputEventKey key;
		InputEventScreenTouch screen_touch;
		InputEventScreenDrag screen_drag;
		InputEventAction action;
	};

	bool is_pressed() const;
	bool is_action(const String& p_action) const;
	bool is_action_pressed(const String& p_action) const;
	bool is_action_released(const String& p_action) const;
	bool is_echo() const;
	void set_as_action(const String& p_action, bool p_pressed);


	InputEvent xform_by(const Transform2D& p_xform) const;
	bool operator==(const InputEvent &p_event) const;
	operator String() const;
	InputEvent() { memset(this,0,sizeof(InputEvent)); }
};



bool InputEvent::operator==(const InputEvent &p_event) const {
	if (type != p_event.type){
		return false;
	}

	switch(type) {
		/** Current clang-format style doesn't play well with the aligned return values of that switch. */
		/* clang-format off */
		case NONE:
			return true;
		case KEY:
			return key.unicode == p_event.key.unicode
				&& key.scancode == p_event.key.scancode
				&& key.echo == p_event.key.echo
				&& key.pressed == p_event.key.pressed
				&& key.mod == p_event.key.mod;
		case MOUSE_MOTION:
			return mouse_motion.x == p_event.mouse_motion.x
				&& mouse_motion.y == p_event.mouse_motion.y
				&& mouse_motion.relative_x == p_event.mouse_motion.relative_x
				&& mouse_motion.relative_y == p_event.mouse_motion.relative_y
				&& mouse_motion.button_mask == p_event.mouse_motion.button_mask
				&& key.mod == p_event.key.mod;
		case MOUSE_BUTTON:
			return mouse_button.pressed == p_event.mouse_button.pressed
				&& mouse_button.x == p_event.mouse_button.x
				&& mouse_button.y == p_event.mouse_button.y
				&& mouse_button.button_index == p_event.mouse_button.button_index
				&& mouse_button.button_mask == p_event.mouse_button.button_mask
				&& key.mod == p_event.key.mod;
		case JOYPAD_MOTION:
			return joy_motion.axis == p_event.joy_motion.axis
				&& joy_motion.axis_value == p_event.joy_motion.axis_value;
		case JOYPAD_BUTTON:
			return joy_button.pressed == p_event.joy_button.pressed
				&& joy_button.button_index == p_event.joy_button.button_index
				&& joy_button.pressure == p_event.joy_button.pressure;
		case SCREEN_TOUCH:
			return screen_touch.pressed == p_event.screen_touch.pressed
				&& screen_touch.index == p_event.screen_touch.index
				&& screen_touch.x == p_event.screen_touch.x
				&& screen_touch.y == p_event.screen_touch.y;
		case SCREEN_DRAG:
			return screen_drag.index == p_event.screen_drag.index
				&& screen_drag.x == p_event.screen_drag.x
				&& screen_drag.y == p_event.screen_drag.y;
		case ACTION:
			return action.action == p_event.action.action
				&& action.pressed == p_event.action.pressed;
		/* clang-format on */
		default:
			ERR_PRINT("No logic to compare InputEvents of this type, this shouldn't happen.");
	}

	return false;
}
InputEvent::operator String() const {
	/*
	String str ="Device "+itos(device)+" ID "+itos(ID)+" ";

	switch(type) {

		case NONE: {

			return "Event: None";
		} break;
		case KEY: {

			str+= "Event: Key ";
			str=str+"Unicode: "+String::chr(key.unicode)+" Scan: "+itos( key.scancode )+" Echo: "+String(key.echo?"True":"False")+" Pressed"+String(key.pressed?"True":"False")+" Mod: ";
			if (key.mod.shift)
				str+="S";
			if (key.mod.control)
				str+="C";
			if (key.mod.alt)
				str+="A";
			if (key.mod.meta)
				str+="M";

			return str;
		} break;
		case MOUSE_MOTION: {

			str+= "Event: Motion ";
			str=str+" Pos: " +itos(mouse_motion.x)+","+itos(mouse_motion.y)+" Rel: "+itos(mouse_motion.relative_x)+","+itos(mouse_motion.relative_y)+" Mask: ";
			for (int i=0;i<8;i++) {

				if ((1<<i)&mouse_motion.button_mask)
					str+=itos(i+1);
			}
			str+=" Mod: ";
			if (key.mod.shift)
				str+="S";
			if (key.mod.control)
				str+="C";
			if (key.mod.alt)
				str+="A";
			if (key.mod.meta)
				str+="M";

			return str;
		} break;
		case MOUSE_BUTTON: {
			str+= "Event: Button ";
			str=str+"Pressed: "+itos(mouse_button.pressed)+" Pos: " +itos(mouse_button.x)+","+itos(mouse_button.y)+" Button: "+itos(mouse_button.button_index)+" Mask: ";
			for (int i=0;i<8;i++) {

				if ((1<<i)&mouse_button.button_mask)
					str+=itos(i+1);
			}
			str+=" Mod: ";
			if (key.mod.shift)
				str+="S";
			if (key.mod.control)
				str+="C";
			if (key.mod.alt)
				str+="A";
			if (key.mod.meta)
				str+="M";

			str+=String(" DoubleClick: ")+(mouse_button.doubleclick?"Yes":"No");

			return str;

		} break;
		case JOYPAD_MOTION: {
			str+= "Event: JoypadMotion ";
			str=str+"Axis: "+itos(joy_motion.axis)+" Value: " +rtos(joy_motion.axis_value);
			return str;

		} break;
		case JOYPAD_BUTTON: {
			str+= "Event: JoypadButton ";
			str=str+"Pressed: "+itos(joy_button.pressed)+" Index: " +itos(joy_button.button_index)+" pressure "+rtos(joy_button.pressure);
			return str;

		} break;
		case SCREEN_TOUCH: {
			str+= "Event: ScreenTouch ";
			str=str+"Pressed: "+itos(screen_touch.pressed)+" Index: " +itos(screen_touch.index)+" pos "+rtos(screen_touch.x)+","+rtos(screen_touch.y);
			return str;

		} break;
		case SCREEN_DRAG: {
			str+= "Event: ScreenDrag ";
			str=str+" Index: " +itos(screen_drag.index)+" pos "+rtos(screen_drag.x)+","+rtos(screen_drag.y);
			return str;

		} break;
		case ACTION: {
			str+= "Event: Action: "+InputMap::get_singleton()->get_action_from_id(action.action)+" Pressed: "+itos(action.pressed);
			return str;

		} break;

	}
	*/

	return "";
}

void InputEvent::set_as_action(const String& p_action, bool p_pressed) {

	godot_input_event_set_as_action((godot_input_event *) this, (godot_string*) &p_action, p_pressed);
}

bool InputEvent::is_pressed() const {

	switch(type) {

		case KEY: return key.pressed;
		case MOUSE_BUTTON: return mouse_button.pressed;
		case JOYPAD_BUTTON: return joy_button.pressed;
		case SCREEN_TOUCH: return screen_touch.pressed;
		case JOYPAD_MOTION: return ::fabs(joy_motion.axis_value) > 0.5;
		case ACTION: return action.pressed;
		default: {}
	}

	return false;
}

bool InputEvent::is_echo() const {

	return (type==KEY && key.echo);
}

bool InputEvent::is_action(const String& p_action) const {

	return godot_input_event_is_action((godot_input_event *) this, (godot_string *) &p_action);
}

bool InputEvent::is_action_pressed(const String& p_action) const {

	return is_action(p_action) && is_pressed() && !is_echo();
}

bool InputEvent::is_action_released(const String& p_action) const {

	return is_action(p_action) && !is_pressed();
}


InputEvent InputEvent::xform_by(const Transform2D& p_xform) const {


	InputEvent ev=*this;

	switch(ev.type) {

		case InputEvent::MOUSE_BUTTON: {

			Vector2 g = p_xform.xform(Vector2(ev.mouse_button.global_x,ev.mouse_button.global_y));
			Vector2 l = p_xform.xform(Vector2(ev.mouse_button.x,ev.mouse_button.y));
			ev.mouse_button.x=l.x;
			ev.mouse_button.y=l.y;
			ev.mouse_button.global_x=g.x;
			ev.mouse_button.global_y=g.y;

		} break;
		case InputEvent::MOUSE_MOTION: {

			Vector2 g = p_xform.xform(Vector2(ev.mouse_motion.global_x,ev.mouse_motion.global_y));
			Vector2 l = p_xform.xform(Vector2(ev.mouse_motion.x,ev.mouse_motion.y));
			Vector2 r = p_xform.basis_xform(Vector2(ev.mouse_motion.relative_x,ev.mouse_motion.relative_y));
			Vector2 s = p_xform.basis_xform(Vector2(ev.mouse_motion.speed_x,ev.mouse_motion.speed_y));
			ev.mouse_motion.x=l.x;
			ev.mouse_motion.y=l.y;
			ev.mouse_motion.global_x=g.x;
			ev.mouse_motion.global_y=g.y;
			ev.mouse_motion.relative_x=r.x;
			ev.mouse_motion.relative_y=r.y;
			ev.mouse_motion.speed_x=s.x;
			ev.mouse_motion.speed_y=s.y;

		} break;
		case InputEvent::SCREEN_TOUCH: {


			Vector2 t = p_xform.xform(Vector2(ev.screen_touch.x,ev.screen_touch.y));
			ev.screen_touch.x=t.x;
			ev.screen_touch.y=t.y;

		} break;
		case InputEvent::SCREEN_DRAG: {


			Vector2 t = p_xform.xform(Vector2(ev.screen_drag.x,ev.screen_drag.y));
			Vector2 r = p_xform.basis_xform(Vector2(ev.screen_drag.relative_x,ev.screen_drag.relative_y));
			Vector2 s = p_xform.basis_xform(Vector2(ev.screen_drag.speed_x,ev.screen_drag.speed_y));
			ev.screen_drag.x=t.x;
			ev.screen_drag.y=t.y;
			ev.screen_drag.relative_x=r.x;
			ev.screen_drag.relative_y=r.y;
			ev.screen_drag.speed_x=s.x;
			ev.screen_drag.speed_y=s.y;
		} break;
	}

	return ev;
}


}

#endif // INPUTEVENT_H
