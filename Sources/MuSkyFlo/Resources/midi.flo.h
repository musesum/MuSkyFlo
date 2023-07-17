midi { // musical instrument device interface
    input { // midi input
        note { // note on/off from 0 thru 127
            on  (num 0_127, velo 0_127, chan 1_32, port 1_16, time)
            off (num 0_127, velo 0_127, chan 1_32, port 1_16, time)
        }
        controller (cc 0_127, val 0_127, chan 1_32, port 1_16, time)
        afterTouch (num 0_127, val 0_127, chan 1_32, port 1_16, time)
        pitchBend  (val 0_16384~8192, chan 1_32, port 1_16, time)
        program (num 0_255, chan 1_32, port 1_16, time)
        nrpn (num 0_16383, val 0…1, chan, time)
    }

    output @ input

    skypad {
        plane(num == 129, val 0…1, chan, time) <> model.canvas.color.fade(x val)
        fade (num == 130, val 0…1, chan, time) <> model.canvas.color.fade(y val)
    }
    input.nrpn >> skypad˚.

    cc.skypad {

        zoom    (cc ==  4, val 0_127) <> model.canvas.plato.zoom
        convex  (cc ==  5, val 0_127) <> model.canvas.plato.shade.convex
        colorY  (cc ==  6, val 0_127) <> model.canvas.plato.shade.colors(y val)
        camix   (cc ==  9, val 0_127) <> model.camix.mix(val)
        fade    (cc == 10, val 0_127) <> model.canvas.color.fade(x val)
        plane   (cc == 11, val 0_127) <> model.canvas.color.fade(y val)
        shiftX  (cc == 12, val 0_127) <> model.canvas.tile.shift(x val)
        shiftY  (cc == 13, val 0_127) <> model.canvas.tile.shift(y val)
        repeatX (cc == 14, val 0_127) <> model.canvas.tile.repeat(x val)
        repeatY (cc == 15, val 0_127) <> model.canvas.tile.repeat(y val)
    }
    input.controller >> cc˚.
    output.controller << cc.skypad˚.

    roli {
        lightpad {
            x (cc == 114, val 0_127)
            y (cc == 113, val 0_127)
            z (cc == 115, val 0_127)
        }
        loopblock {
            mode   (cc == 102, val 0_127)
            mute   (cc == 103, val 0_127)
            metro  (cc == 104, val 0_127)
            skip   (cc == 105, val 0_127)
            back   (cc == 106, val 0_127)
            play   (cc == 107, val 0_127)
            record (cc == 108, val 0_127)
            learn  (cc == 109, val 0_127)
            prev   (cc == 110, val 0_127)
            next   (cc == 111, val 0_127)
        }
    }

    notes {
        dot.on (x num % 12, y num / 12, z velo) >> sky.draw.dot.on
        dot.off(x num % 12, y num / 12, z velo) >> sky.draw.dot.off
    }
    input.note.on  >> (notes.dot.on,  output.note.on)
    input.note.off >> (notes.dot.off, output.note.off)

    _cc {
        main {
            modWheel    (num == 1, val, chan, time)
            volume      (num == 7, val, chan, time)
            balance     (num == 8, val, chan, time)
            panPosition (num == 10, val, chan, time)
            expression  (num == 11, val, chan, time)
            controller  (num in 32_63, val, chan, time)
            portamento {
                time   (num ==  5, val, chan, time)
                amount (num == 84, val, chan, time)
            }
        }
        pedal {
            hold    (num == 64, val, chan, time)
            porta   (num == 65, val, chan, time)
            sosta   (num == 66, val, chan, time)
            _soft   (num == 67, val, chan, time)
            _legato (num == 68, val, chan, time)
            _hold2  (num == 69, val, chan, time)
        }

        _main2 {
            bankSelect  (num == 0, val, chan, time)
            breathCtrl  (num == 2, val, chan, time)
            footPedal   (num == 4, val, chan, time)
            dataEntry   (num == 6, val, chan, time)
            effectCtrl1 (num == 12, val, chan, time)
            effectCtrl2 (num == 13, val, chan, time)
        }
        _sound {
            soundVariation  (num == 70, val, chan, time)
            resonance       (num == 71, val, chan, time)
            soundReleaseTime(num == 72, val, chan, time)
            soundAttackTime (num == 73, val, chan, time)
            frequencyCutoff (num == 74, val, chan, time)

            timbre          (num == 71, val, chan, time)
            brightness      (num == 74, val, chan, time)
        }
        _button {
            button1 (num == 80, val, chan, time)
            button2 (num == 81, val, chan, time)
            button3 (num == 82, val, chan, time)
            button4 (num == 83, val, chan, time)

            decayor          (num == 80, val, chan, time)
            hiPassFilter     (num == 81, val, chan, time)
            generalPurpose82 (num == 82, val, chan, time)
            generalPurpose83 (num == 83, val, chan, time)
        }
        _roland {
            rolandToneLevel1 (num == 80, val, chan, time)
            rolandToneLevel2 (num == 81, val, chan, time)
            rolandToneLevel3 (num == 82, val, chan, time)
            rolandToneLevel4 (num == 83, val, chan, time)
        }
        _level {
            reverbLevel  (num == 91, val, chan, time)
            tremoloLevel (num == 92, val, chan, time)
            chorusLevel  (num == 93, val, chan, time)
            detuneLevel  (num == 94, val, chan, time)
            phaserLevel  (num == 95, val, chan, time)
        }
        _parameter {
            dataButtonIncrement       (num ==  96, val, chan, time)
            dataButtonDecrement       (num ==  97, val, chan, time)
            nonregisteredParameterLSB (num ==  98, val, chan, time)
            nonregisteredParameterMSB (num ==  99, val, chan, time)
            registeredParameterLSB    (num == 100, val, chan, time)
            registeredParameterMSB    (num == 101, val, chan, time)
        }
        _soundControl {
            soundControl6  (num == 75, val, chan, time)
            soundControl7  (num == 76, val, chan, time)
            soundControl8  (num == 77, val, chan, time)
            soundControl9  (num == 78, val, chan, time)
            soundControl10 (num == 79, val, chan, time)
        }
        _undefined {
            undefined_3       (num == 3      , val, chan, time)
            undefined_9       (num == 9      , val, chan, time)
            undefined_14_31   (num in 14_31  , val, chan, time)
            undefined_85_90   (num in 85_90  , val, chan, time)
            undefined_102_119 (num in 102_119, val, chan, time)
        }
        _mode {
            allSoundOff       (num == 120, val, chan, time)
            allControllersOff (num == 121, val, chan, time)
            localKeyboard     (num == 122, val, chan, time)
            allNotesOff       (num == 123, val, chan, time)
            monoOperation     (num == 126, val, chan, time)
            polyMode          (num == 127, val, chan, time)
        }
        _omni {
            omniModeOff       (num == 124, val, chan, time)
            omniModeOn        (num == 125, val, chan, time)
            omniMode(0_1) << (omniModeOff(0), omniModeOn(1))
        }
    }
}


