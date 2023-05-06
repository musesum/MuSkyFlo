_menu  {
    canvas (svg "icon.canvas") {
        tile (svg "icon.tile") {
            mirror (svg "icon.mirror")
            repeat (svg "icon.repeat.arrows")
            shift  (svg "icon.direction")
        }
        color(img "icon.pal.main") {
            fade   (svg "icon.gradient")
            plane  (svg "icon.layers")
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
_menu.canvas {
    cube (sym "cube") {
        motion (sym "gyroscope")
        rotate (svg "icon.direction")
        back   (sym "cube")
        show   (sym "cube.fill")
    } 
    plato(svg "icon.plato.wire") {
        shade (svg "icon.peacock") {
            phase  (sym "calendar.day.timeline.left")
            convex (svg "icon.convex")
            colors (sym "figure.stair.stepper")
            shadow (sym "shadow")
            invert (sym "circle.lefthalf.filled")
        }
        zoom  (svg "icon.zoom")
        morph (svg "icon.counter")
        wire  (svg "icon.wireframe")
        show  (svg "icon.plato.show")
    }
}

menu {
    SW @ _menu
    SE @ _menu
    NE @ _menu
    NW @ _menu
}
