model {
    canvas {
        tile  {
            mirror (x 0…1=0,
                    y 0…1=0) <> shader.model.pipe.render.mirror

            repeat (x -1…1=0,
                    y -1…1=0) <> shader.model.pipe.render.repeat

            shift (x 0…1=0.5,
                   y 0…1=0.5) <> shader.model.pipe.draw

            tilt  (tog 0…1=0) <> sky.input.tilt
        }
        color {
            fade  (val 0…1=0.5) <> sky.color.xfade
            plane (val 0…1=0.1) <> shader.model.pipe.color
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
        fade  (val 1.61…3=1.61) <> shader.model.cell.fade
        ave   (val 0…1=0.5) <> shader.model.cell.ave
        melt  (val 0…1=0.5) <> shader.model.cell.melt
        tunl  (seg 0…5=1  ) <> shader.model.cell.tunl
        zha   (seg 0…6=2  ) <> shader.model.cell.zha
        slide (seg 0…7=3  ) <> shader.model.cell.slide
        fred  (seg 0…4=4  ) <> shader.model.cell.fred
    }
    cam {
        snap  (tap 0…1=0  )
        fake  (tog 0…1=0  ) <> shader.model.pipe.camix.on
        real  (tog 0…1=1  ) <> shader.model.pipe.camera.on
        face  (tog 0…1=1  ) <> shader.model.pipe.camera.flip
        mix   (val 0…1=0.5) <> shader.model.pipe.camix.mix
    }
    net (symbol "network") {
        bonjour (peer "bonjour") <> sky.main.peer.bonjour
        follow  (tog 0…1=1) <> sky.main.peer.follow
        midi    (tog 0…1=1) <> sky.main.peer.midi
    }
}
