_menu  {
    canvas (svg "icon.canvas") {

        mirror (svg "icon.mirror")
        repeat (svg "icon.repeat.arrows")
        shift  (svg "icon.direction")

        color (img "icon.pal.main") {
            fade   (svg "icon.gradient")
            fill_0 (sym "drop")
            fill_1 (sym "drop.fill")
        }
        brush (svg "icon.brush") {
            size  (svg "icon.size.dot")
            press (sym "scribble.variable")
            tilt  (sym "angle")
            index (sym "calendar.day.timeline.left")
        }
    }
    plato (svg "icon.plato.icosa") {
        more (svg "icon.more") {
            wire     (svg "icon.wireframe")
            phase    (svg "icon.plato.phase")
            harmonic (svg "icon.subtriangle")
            show     (sym "eye")
            run      (svg "icon.counter")
        }
        reflect  (svg "icon.opacity")
        shadow   (sym "shadow")
        invert   (svg "icon.invert")
        zoom     (svg "icon.zoom")
        convex   (svg "icon.convex")
    }
    cell (svg "icon.cellular.automata") {
        fade  (img "icon.cell.fade" )
        ave   (img "icon.cell.ave"  )
        melt  (img "icon.cell.melt" )
        tunl  (img "icon.cell.tunl" )
        zha   (img "icon.cell.zha"  )
        slide (img "icon.cell.slide")
        fred  (img "icon.cell.fred" )
    }
    camera (sym "camera") {
        stream (sym "video")
        front  (svg "icon.camera.facing")
        mask   (svg "icon.face")
        mix    (sym "camera.filters")
        fade   (svg "icon.gradient")
    }
    more (svg "icon.more") {
        speed (img "icon.speed") {
            fps  (sym "speedometer")
            run  (sym "goforward")
            anim (sym "bolt.fill")
        }
        network (sym "bonjour") {
            bonjour (sym "network")
            follow  (sym "app.connected.to.app.below.fill")
            midi    (sym "pianokeys.inverse")
        }
        motion (sym "gyroscope")
        rotate (svg "icon.rotate")
        show (sym "eye") {
            cubemap (sym "cube")
            canvas  (svg "icon.canvas")
            plato   (svg "icon.dodec")
        }
    }
}
