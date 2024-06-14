# QMK Userspace

This is my personal userspace for QMK. The keyboard I am currently using is a Kyria Rev 3, with a Colemak-DH layout with heavy [Miryoku](https://github.com/manna-harbour/miryoku) inspiration. It also makes use of Sunaku's [bilateral combination](https://sunaku.github.io/home-row-mods.html).

The keymap I use is available under [keyboards/splitkb/kyria/keymaps/tyosa](./keyboards/splitkb/kyria/keymaps/tyosa).

# Keymap
```
┌──────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬──────┐
│      │  Q   │  W   │  F   │  P   │  B   │                              │  J   │  L   │  U   │  Y   │  ;:  │      │
├──────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │ A ⊞  │ R ⎇  │ S ^  │ T ⇧  │  G   │                              │  M   │ N ⇧  │ E ^  │ I ⎇  │ O ⊞  │      │
├──────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
│      │ (^)Z │ (^)X │ (^)C │  D   │ (^)V │      │  ⟲   │  │  ⟳   │      │  K   │  H   │ ,< - │ .> _ │ /? ! │  ⌦   │
└──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
                     │      │      │  ⎋   │␣ MEH │  ↹   │  │  ⏎   │  ⌫   │ SYM  │      │      │
                     │      │      │      │      │      │  │      │      │      │      │      │
                     └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘

┌──────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬──────┐
│      │  %   │  @   │  #   │  $   │      │                              │      │  &   │  *   │  `~  │  ^   │      │
├──────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │  À   │  È   │  É   │      │      │                              │      │ [ ⇧  │ ( ^  │ ) ⎇  │ ] ⊞  │      │
├──────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │  Ç   │      │      │      │  ⟲   │  │  ⟳   │      │  '"  │  \|  │  {   │  }   │ NAV  │  ⌦   │
└──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
                     │      │      │  ⎋   │ BASE │  ↹   │  │  ⏎   │  ⌫   │ NUM  │      │      │
                     │      │      │      │      │      │  │      │      │      │      │      │
                     └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘

┌──────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬──────┐
│      │      │      │      │      │      │                              │      │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │  ⊞   │  ⎇   │  ^   │  ⇧   │      │                              │      │  ←   │  ↓   │  ↑   │  →   │      │
├──────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │      │  ⟲   │  │  ⟳   │      │      │ HOME │      │      │ END  │  ⌦   │
└──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
                     │      │      │  ⎋   │ BASE │  ↹   │  │  ⏎   │  ⌫   │ SYM  │      │      │
                     │      │      │      │      │      │  │      │      │      │      │      │
                     └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘

┌──────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬──────┐
│      │  F9  │ F10  │ F11  │ F12  │      │                              │  *   │  7   │  8   │  9   │  -_  │      │
├──────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │ F5 ⊞ │ F6 ⎇ │ F7 ^ │ F8 ⇧ │      │                              │  .   │ 4 ⇧  │ 5 ^  │ 6 ⎇  │ = ⊞  │      │
├──────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
│      │  F1  │  F2  │  F3  │  F4  │      │      │  ⟲   │  │  ⟳   │      │  0   │  1   │  2   │  3   │ NAV  │  ⌦   │
└──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
                     │      │      │  ⎋   │ BASE │  ↹   │  │  ⏎   │  ⌫   │ SYM  │      │      │
                     │      │      │      │      │      │  │      │      │      │      │      │
                     └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘
```

# To-Do

- [ ] Add caps word qmk feature
- [ ] Enhance display now that the microcontroller can handle the size
- [ ] Add mouse keys
- [ ] Add music control
- [ ] Add super quote on h tap dance
- [ ] Find where to put caps lock
- [ ] Play around with the repeat key
- [ ] Play with other type of "alt-tab" : alt esc (no popup), alt grv (between instances)
- [ ] Try out leader key
- [ ] HID ?
