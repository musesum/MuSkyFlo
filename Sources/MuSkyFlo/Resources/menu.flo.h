menu  {
    SW {
        view {

            canvas (svg "icon.canvas") {
                plato(svg "icon.plato.dodec") {
                    cube    (svg "icon.plato.cube")
                    reflect (svg "icon.reflect")
                    colorize(svg "icon.peacock")
                    wire    (svg "icon.wireframe")
                    go      (svg "icon.counter")
                }
                tile (svg "icon.tile") {
                    mirror (svg "icon.mirror")
                    repeat (svg "icon.repeat.arrows")
                    shift (svg "icon.direction")
                }
                color(image "icon.pal.main") {
                    fade  (svg "icon.gradient")
                    plane (svg "icon.layers")
                    fill  (symbol "drop.fill")
                }
                speed (image "icon.speed") {
                    fps (symbol "speedometer")
                    run (symbol "goforward")
                    anim (symbol "bolt.fill")
                }
                motion  (symbol "gyroscope")
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
    }
    SE @ SW // copy southwest to other corners
    NE @ SW
    NW @ SW
}
