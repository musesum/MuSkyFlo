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
        mix    (symbol "camera.filters")
    }
    network (symbol "network") {
        bonjour (symbol "bonjour")
        follow  (symbol "shared.with.you")
        midi    (symbol "pianokeys.inverse")
    }
}
_menu.canvas {
    cube (svg "icon.plato.cube") {
        wire    (svg "icon.wireframe")
        motion  (symbol "gyroscope")
        rotate  (svg "icon.direction")
        zoom    (svg "icon.zoom")
        show    (svg "icon.plato.cube")
    }
    plato(svg "icon.plato.dodec") {
        reflect (svg "icon.reflect")
        counter (symbol "calendar.day.timeline.left")
        coloriz (svg "icon.peacock")
        morping (svg "icon.counter")
        rotate  (svg "icon.direction")
        show(svg "icon.plato.dodec")

    }
}
menu {
    SW @ _menu
    SE @ _menu
    NE @ _menu
    NW @ _menu
}
