menu  {
    SW {
        view {
            canvas (symbol "photo.artframe") {
                tile (image "icon.shader.tile.png") {
                    mirror (symbol "arrowtriangle.left.and.line.vertical.and.arrowtriangle.right")
                    repeat (symbol "rectangle.grid.2x2" )
                    shift (image "icon.cell.scroll")
                    tilt  (symbol "angle")
                }
                color(image "icon.pal.main") {
                    fade  (symbol "slider.horizontal.below.rectangle")
                    plane (symbol "square.3.layers.3d.down.right")
                    fill  (symbol "drop.fill")
                }
                speed (image "icon.speed") {
                    fps (symbol "speedometer")
                    run (symbol "goforward")
                    anim (symbol "bolt.fill")
                }
            }
            brush (symbol "paintbrush.pointed") {
                size  (symbol "circle.circle")
                press (symbol "scribble.variable")
                index (symbol "calendar.day.timeline.left")
            }
            cell (symbol "circle.grid.3x3") {
                fade  (image "icon.cell.fade" )
                ave   (image "icon.cell.ave"  )
                melt  (image "icon.cell.melt" )
                tunl  (image "icon.cell.tunl" )
                zha   (image "icon.cell.zha"  )
                slide (image "icon.cell.slide")
                fred  (image "icon.cell.fred" )
            }
            cam (symbol "camera") {
                snap  (symbol "camera.shutter.button")
                fake  (symbol "face.dashed")
                real  (symbol "face.smiling")
                face  (symbol "arrow.triangle.2.circlepath.camera")
                mix   (symbol "camera.filters")
            }
            net (symbol "network") {
                bonjour (symbol "bonjour")
                follow (symbol "shared.with.you")
                midi (symbol "pianokeys.inverse")
            }
        }
    }
    SE @ SW // copy southwest to other corners
    NE @ SW
    NW @ SW
}
