
KEYS = []


class Key:
    """

    Arguments:
        code (str): QMK keycode.
        config (str): x360kb key name.

    Example:
        Key('KC_PAUS', 'Pause')

    """

    def __init__(self, code, config):
        KEYS.append(self)
        self.qmk = code
        self.x360kb = config

    def __repr__(self):
        return '<Key qmk={}, x360kb={}>'.format(self.qmk, self.x360kb)


F1 = Key('KC_F1', 'F1')
F2 = Key('KC_F2', 'F2')
F3 = Key('KC_F3', 'F3')
F4 = Key('KC_F4', 'F4')
F5 = Key('KC_F5', 'F5')
F6 = Key('KC_F6', 'F6')
F7 = Key('KC_F7', 'F7')
F8 = Key('KC_F8', 'F8')
F9 = Key('KC_F9', 'F9')
F10 = Key('KC_F10', 'F10')
F11 = Key('KC_F11', 'F11')
F12 = Key('KC_F12', 'F12')
L9 = Key('KC_9', '9')
L8 = Key('KC_8', '8')
L7 = Key('KC_7', '7')
L6 = Key('KC_6', '6')
L5 = Key('KC_5', '5')
L4 = Key('KC_4', '4')
L3 = Key('KC_3', '3')
L2 = Key('KC_2', '2')
L1 = Key('KC_1', '1')
L0 = Key('KC_0', '0')
LZ = Key('KC_Z', 'Z')
LW = Key('KC_W', 'W')
LV = Key('KC_V', 'V')
LU = Key('KC_U', 'U')
LT = Key('KC_T', 'T')
LS = Key('KC_S', 'S')
LR = Key('KC_R', 'R')
LQ = Key('KC_Q', 'Q')
LP = Key('KC_P', 'P')
LO = Key('KC_O', 'O')
LN = Key('KC_N', 'N')
LM = Key('KC_M', 'M')
LL = Key('KC_L', 'L')
LK = Key('KC_K', 'K')
LJ = Key('KC_J', 'J')
LI = Key('KC_I', 'I')
LH = Key('KC_H', 'H')
LG = Key('KC_G', 'G')
LF = Key('KC_F', 'F')
LE = Key('KC_E', 'E')
LD = Key('KC_D', 'D')
LC = Key('KC_C', 'C')
Pause = Key('KC_PAUS', 'Pause')
Scroll_Lock = Key('KC_SLCK', 'Scroll Lock')
SysRq = Key('KC_SYSRQ', 'SysRq')
Space = Key('KC_SPC', 'Space')
PgDn = Key('KC_PGDN', 'PgDn')
PgUp = Key('KC_PGUP', 'PgUp')
Home = Key('KC_HOME', 'Home')
Delete = Key('KC_DEL', 'Delete')
Insert = Key('KC_INS', 'Insert')
Right_Alt = Key('KC_RALT', 'Right Alt')
Left_Alt = Key('KC_LALT', 'Left Alt')
Right_Control = Key('KC_RCTL', 'Right Control')
Left_Control = Key('KC_LCTL', 'Left Control')
Slash = Key('KC_SLSH', 'Slash')
Period = Key('KC_DOT', 'Period')
Comma = Key('KC_COMM', 'Comma')
Right_Shift = Key('KC_RSHIFT', 'Right Shift')
Left_Shift = Key('KC_LSHIFT', 'Left Shift')
Return = Key('KC_ENT', 'Return')
Backslash = Key('KC_BSLS', 'Backslash')
Apostrophe = Key('KC_QUOTE', 'Apostrophe')
Semicolon = Key('KC_SCLN', 'Semicolon')
CapsLock = Key('KC_CAPS', 'CapsLock')
Right_Bracket = Key('KC_RBRC', 'Right Bracket')
Left_Bracket = Key('KC_LBRC', 'Left Bracket')
Backspace = Key('KC_BSPC', 'Backspace')
Equals = Key('KC_EQL', 'Equals')
Minus = Key('KC_MINS', 'Minus')
Grave = Key('KC_GRAVE', 'Grave')
Right = Key('KC_RIGHT', 'Right')
Left = Key('KC_LEFT', 'Left')
Down = Key('KC_DOWN', 'Down')
Up = Key('KC_UP', 'Up')
NumStar = Key('KC_PAST', 'NumStar')
NumSlash = Key('KC_PSLS', 'NumSlash')
NumPlus = Key('KC_PPLS', 'NumPlus')
NumPeriod = Key('KC_PDOT', 'NumPeriod')
NumMinus = Key('KC_PMNS', 'NumMinus')
NumEnter = Key('KC_PENT', 'NumEnter')
NumLock = Key('KC_NLCK', 'NumLock')
Num9 = Key('KC_P9', 'Num9')
Num8 = Key('KC_P8', 'Num8')
Num7 = Key('KC_P7', 'Num7')
Num6 = Key('KC_P6', 'Num6')
Num5 = Key('KC_P5', 'Num5')
Num4 = Key('KC_P4', 'Num4')
Num3 = Key('KC_P3', 'Num3')
Num2 = Key('KC_P2', 'Num2')
Num1 = Key('KC_P1', 'Num1')
Num0 = Key('KC_P0', 'Num0')


class KeyConfig:

    def __init__(self, name, key=None):
        self.name = name
        self.key = key

    @property
    def x360kb(self):
        if not self.key:
            return ''
        return '{self.name}={self.key.x360kb}'.format(self=self)

    @property
    def qmk(self):
        if not self.key or not self.key.qmk:
            return 'KC_NO'
        return self.key.qmk


class Pad:
    """

    Arguments:
          start:
          select: "Back"
          a:
          b:
          x:
          y:
          dp_lt: DPad left. Heal.
          dp_dn: DPad down. Ability 1.
          dp_up: DPad up. Ability 2.
          dp_rt: DPad right. Repair.
          ls_lt: Left Stick left. Strafe left.
          ls_up: Left Stick up. Move forward.
          ls_dn: Left Stick down. Move Back.
          ls_rt: Left Stick right. Strafe right.
          ltrig: Left Trigger. Alternate attack.
          rs_lt: Right Stick left. Camera left.
          rs_dn: Right Stick down. Camera down.
          rs_up: Right Stick up. Camera down.
          rs_rt: Right Stick right. Camera right.
          rs_btn: Right Stick button ("Right Thumb"). Toggle zoom.
          rshldr: Right Shoulder. Primary attack.

        pad_number,
        right_trigger=None,
        left_trigger=None,
        right_analog_down=None,
        right_analog_up=None,
        right_analog_left=None,
        right_analog_right=None,
        left_analog_down=None,
        left_analog_up=None,
        left_analog_left=None,
        left_analog_right=None,
        dpad_right=None,
        dpad_left=None,
        dpad_down=None,
        dpad_up=None,
        right_thumb=None,
        left_thumb=None,
        start=None,
        back=None,
        right_shoulder=None,
        left_shoulder=None
    """

    def __init__(
        self,
        pad_number,
        a=None,
        b=None,
        x=None,
        y=None,
        right_trigger=None,
        left_trigger=None,
        right_analog_down=None,
        right_analog_up=None,
        right_analog_left=None,
        right_analog_right=None,
        left_analog_down=None,
        left_analog_up=None,
        left_analog_left=None,
        left_analog_right=None,
        dpad_right=None,
        dpad_left=None,
        dpad_down=None,
        dpad_up=None,
        right_thumb=None,
        left_thumb=None,
        start=None,
        back=None,
        right_shoulder=None,
        left_shoulder=None
    ):
        self.pad_number = pad_number
        self.a = KeyConfig('A', a)
        self.b = KeyConfig('B', b)
        self.x = KeyConfig('X', x)
        self.y = KeyConfig('Y', y)
        self.right_trigger = KeyConfig('Right Trigger', right_trigger)
        self.left_trigger = KeyConfig('Left Trigger', left_trigger)
        self.right_analog_down = KeyConfig('Right Analog Down', right_analog_down)
        self.right_analog_up = KeyConfig('Right Analog Up', right_analog_up)
        self.right_analog_left = KeyConfig('Right Analog Left', right_analog_left)
        self.right_analog_right = KeyConfig('Right Analog Right', right_analog_right)
        self.left_analog_down = KeyConfig('Left Analog Down', left_analog_down)
        self.left_analog_up = KeyConfig('Left Analog Up', left_analog_up)
        self.left_analog_left = KeyConfig('Left Analog Left', left_analog_left)
        self.left_analog_right = KeyConfig('Left Analog Right', left_analog_right)
        self.dpad_right = KeyConfig('D-Pad Right', dpad_right)
        self.dpad_left = KeyConfig('D-Pad Left', dpad_left)
        self.dpad_down = KeyConfig('D-Pad Down', dpad_down)
        self.dpad_up = KeyConfig('D-Pad Up', dpad_up)
        self.right_thumb = KeyConfig('Right Thumb', right_thumb)
        self.left_thumb = KeyConfig('Left Thumb', left_thumb)
        self.start = KeyConfig('Start', start)
        self.back = KeyConfig('Back', back)
        self.right_shoulder = KeyConfig('Right Shoulder', right_shoulder)
        self.left_shoulder = KeyConfig('Left Shoulder', left_shoulder)

    @property
    def qmk(self):
        '''QMK config for Dungeon Defenders emulated game pad.
        For use with Plane's three file emulator.

        Layout:
          Left Hand:
           +-------+-----+-----+-----+-----+-----+------+
           | Abil 2|LS Lt|LS Up|     |     |     |Start |
           +-------+-----+-----+-----+-----+-----+------+
           | Abil 1|     |LS Dn|LS Rt|     |     |Select|
           +-------+-----+-----+-----+-----+-----+      |
           | Heal  |     |     |     |     |     +------+
           +-------+-----+-----+-----+-----+-----+      |
           | Heal  |     |     |     |     |     |      |
           +-+-----+-----+-----+-----+-----+-----+------+
             |     |     |     |     |     |
             +-----+-----+-----+-----+-----+   +-----+-----+
                                               |  X  |     |
                                         +-----+-----+-----+
                                         |     |     |     |
                                         |  A  |     +-----+
                                         |     |     |     |
                                         +-----+-----+-----+
          Right Hand:
               +-----+-----+-----+-----+-----+-----+-------+
               |     |     |     |     |     |     |       |
               +-----+-----+-----+-----+-----+-----+-------+
               |     |     |     |     |     |     |       |
               |     +-----+-----+-----+-----+-----+-------+
               +-----+     |     |     |     |     |       |
               |     +-----+-----+-----+-----+-----+-------+
               |     |     |     |     |     |     |       |
               +-----+-----+-----+-----+-----+-----+-----+-+
                           |CamLt|CamDn|CamUp|CamRt|     |
           +-------+-----+ +-----+-----+-----+-----+-----+
           |       |  Y  |
           +-------+-----+-----+
           | Zoom  |     |     |
           +-------+ Att |  B  |
           |Alt Att|     |     |
           +-------+-----+-----+

         '''
        return '''LAYOUT_ergodox(
    {self.dpad_up.qmk}, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      {self.start.qmk},
    {self.dpad_down.qmk}, {self.left_analog_left.qmk}, {self.left_analog_up.qmk}, KC_NO,   KC_NO,   KC_NO,      {self.back.qmk},
    {self.dpad_left.qmk}, KC_NO,   {self.left_analog_down.qmk}, {self.left_analog_right.qmk}, KC_NO,   KC_NO,
    {self.dpad_left.qmk}, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_TRNS,
    KC_NO,   KC_NO,   KC_NO,   KC_TRNS, {self.dpad_right.qmk},
                                        KC_NO,      {self.x.qmk},
                                                    KC_NO,
                                        {self.a.qmk}, KC_TRNS, KC_NO,

    KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
    KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
             KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
    KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
             {self.right_analog_left.qmk}, {self.right_analog_down.qmk},  {self.right_analog_up.qmk}, {self.right_analog_right.qmk}, KC_NO,
    KC_NO,   {self.y.qmk},
    {self.right_thumb.qmk},
    {self.left_trigger.qmk},  {self.right_shoulder.qmk}, {self.b.qmk}
  ),'''.format(self=self)

    @property
    def x360kb(self):
        entries = []
        for conf in self:
            if conf.x360kb:
                entries.append(conf.x360kb)

        return '[PAD{}]\n{}'.format(self.pad_number, '\n'.join(entries))

    def __iter__(self):
        return iter((
            self.a,
            self.b,
            self.x,
            self.y,
            self.right_trigger,
            self.left_trigger,
            self.right_analog_down,
            self.right_analog_up,
            self.right_analog_left,
            self.right_analog_right,
            self.left_analog_down,
            self.left_analog_up,
            self.left_analog_left,
            self.left_analog_right,
            self.dpad_right,
            self.dpad_left,
            self.dpad_down,
            self.dpad_up,
            self.right_thumb,
            self.left_thumb,
            self.start,
            self.back,
            self.right_shoulder,
            self.left_shoulder
            ))


def used(*pads):
    used_keys = []
    for pad in pads:
        for kc in pad:
            if kc.key is not None and kc.key in [k.key for k in used_keys]:
                print('Found multiple uses of', kc.key)
                print('\t', kc.name)
                for k in used_keys:
                    if k.key == kc.key:
                        print('\t', k.name)
            used_keys.append(kc)
    return [k.key for k in used_keys]


def unused(*pads):
    unused_keys = []
    used_keys = used(*pads)
    for key in KEYS:
        if key not in used_keys:
            unused_keys.append(key)
    return unused_keys


common_entries = dict(
        back=Home,
        a=Insert, b=PgUp,
        dpad_left=NumMinus,
        right_thumb=Pause
    )

PAD1 = Pad(1,
        start=Right_Alt,
        dpad_down=Num0, dpad_up=NumPeriod,
        left_analog_left=Left, left_analog_down=Down, left_analog_up=Up, left_analog_right=Right, left_trigger=Grave,
        right_analog_left=Slash, right_analog_right=Backslash, right_shoulder=NumPlus,
        **common_entries
      )

PAD2 = Pad(2,
        start=NumEnter,
        x=Semicolon, y=Apostrophe,
        dpad_down=NumLock, dpad_up=NumStar,
        left_analog_left=Num7, left_analog_down=Num8, left_analog_up=NumSlash, left_analog_right=Num9, left_trigger=Delete,
        right_analog_left=Minus, right_analog_right=Equals, right_shoulder=Left_Bracket,
        **common_entries
      )

PAD3 = Pad(3,
        start=Right_Control,
        dpad_down=Num4, dpad_up=Num6,
        left_analog_left=Num1, left_analog_down=Num2, left_analog_up=Num5, left_analog_right=Num3, left_trigger=Backspace,
        right_analog_left=Period, right_analog_right=Comma, right_shoulder=Right_Bracket,
        **common_entries
      )

print('  [LDDP1] =', PAD1.qmk)
print('  [LDDP2] =', PAD2.qmk)
print('  [LDDP3] =', PAD3.qmk)
print('\n\n\nx360kb.ini\n')
print(PAD1.x360kb)
print()
print(PAD2.x360kb)
print()
print(PAD3.x360kb)
