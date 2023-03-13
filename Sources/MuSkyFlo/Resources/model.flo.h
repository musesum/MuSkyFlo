model {
    canvas {
        tile  {
            mirror (x 0…1=0,
                    y 0…1=0) <> shader.pipe.render.mirror

            repeat (x -1…1=0,
                    y -1…1=0) <> shader.pipe.render.repeat

            shift (x 0…1=0.5,
                   y 0…1=0.5) <> shader.pipe.draw 

            tilt  (tog 0…1=0) <> sky.input.tilt
        }
        color {
            fade  (val 0…1=0.5) <> sky.color.xfade
            plane (val 0…1=0.1) <> shader.pipe.color
            fill  (seg 0…1=0)   <> sky.draw.screen.fill
        }
        speed {
            fps (seg 0…60=60)  <> sky.main.fps
            run (seg 0…1=1 )   <> sky.main.run
            anim(val 0…1=0.24) <> sky.main.anim
        }
    }
    brush {
        size  (val 0…1=0.5) <> sky.draw.brush.size
        press (tog 0…1=1  ) <> sky.draw.brush.press
        index (seg 1…255=127) <> sky.draw.brush.index
    }
    cell {
        fade  (val 1.61…3=1.61) <> shader.cell.fade
        ave   (val 0…1=0.5) <> shader.cell.ave
        melt  (val 0…1=0.5) <> shader.cell.melt
        tunl  (seg 0…5=1  ) <> shader.cell.tunl 
        zha   (seg 0…6=2  ) <> shader.cell.zha
        slide (seg 0…7=3  ) <> shader.cell.slide
        fred  (seg 0…4=4  ) <> shader.cell.fred
    }
    camera {
        stream (tog 0…1=0  ) <> shader.pipe.camera.on
        facing (tog 0…1=1  ) <> shader.pipe.camera.flip
        mix    (val 0…1=0.5) <> shader.pipe.camix.mix
    }
    network (symbol "network") {
        bonjour (peer "bonjour") <> sky.main.peer.bonjour
        follow  (tog 0…1=1) <> sky.main.peer.follow
        midi    (tog 0…1=1) <> sky.main.peer.midi
    }
}
