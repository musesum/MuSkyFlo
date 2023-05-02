_menu  {
    canvas (svg "icon.canvas") {
        tile (svg "icon.tile") {
            mirror (svg "icon.mirror")
            repeat (svg "icon.repeat.arrows")
            shift  (svg "icon.direction")
        }
        color(image "icon.pal.main") {
            fade  (svg "icon.gradient")
            plane (svg "icon.layers")
            fill_0  (symbol "drop")
            fill_1  (symbol "drop.fill")
        }
        speed (image "icon.speed") {
            fps (symbol "speedometer")
            run (symbol "goforward")
            anim (symbol "bolt.fill")
        }
    }
    brush (svg "icon.brush") {
        size  (svg "icon.size.dot")
        press (symbol "scribble.variable")
        tilt  (symbol "angle")
        index (symbol "calendar.day.timeline.left")
    }
    cell (svg "icon.ca.grid") {
        fade  (image "icon.cell.fade" )
        ave   (image "icon.cell.ave"  )
        melt  (image "icon.cell.melt" )
        tunl  (image "icon.cell.tunl" )
        zha   (image "icon.cell.zha"  )
        slide (image "icon.cell.slide")
        fred  (image "icon.cell.fred" )
    }
    camera (symbol "camera") {
        stream (symbol "video")
        facing (svg "icon.camera.facing")
        mask   (svg "icon.face")
        mix    (symbol "camera.filters")
    }
    network (symbol "network") {
        bonjour (symbol "bonjour")
        follow  (symbol "shared.with.you")
        midi    (symbol "pianokeys.inverse")
    }
}
_menu.canvas {
    cube (symbol "cube") {
        motion  (symbol "gyroscope")
        rotate  (svg "icon.direction")
        back    (symbol "cube")
        show    (symbol "cube.fill")
    } 
    plato(svg "icon.plato.wire") {
        shade (svg "icon.peacock") {
            colors (symbol "figure.stair.stepper")
            wire   (svg "icon.wireframe")
            shadow (symbol "shadow")
            style (svg "icon.peacock")
        }
        morph (svg "icon.counter")
        phase (symbol "calendar.day.timeline.left")
        zoom  (svg "icon.zoom")
        show (svg "icon.plato.show")
    }
}

menu {
    SW @ _menu
    SE @ _menu
    NE @ _menu
    NW @ _menu
}
