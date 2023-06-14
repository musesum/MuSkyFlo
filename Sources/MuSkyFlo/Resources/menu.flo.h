_menu  {
    canvas (svg "icon.canvas") {
        tile (svg "icon.tile") {
            mirror (svg "icon.mirror")
            repeat (svg "icon.repeat.arrows")
            shift  (svg "icon.direction")
        }
        color(img "icon.pal.main") {
            fade   (svg "icon.gradient")
            fill_0 (sym "drop")
            fill_1 (sym "drop.fill")
        }
        speed (img "icon.speed") {
            fps  (sym "speedometer")
            run  (sym "goforward")
            anim (sym "bolt.fill")
        }
    }
    brush (svg "icon.brush") {
        size  (svg "icon.size.dot")
        press (sym "scribble.variable")
        tilt  (sym "angle")
        index (sym "calendar.day.timeline.left")
    }
    cell (svg "icon.ca.grid") {
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
        facing (svg "icon.camera.facing")
        mask   (svg "icon.face")
        mix    (sym "camera.filters")
    }
    network (sym "network") {
        bonjour (sym "bonjour")
        follow  (sym "shared.with.you")
        midi    (sym "pianokeys.inverse")
    }
}
