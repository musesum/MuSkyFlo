model {
    canvas {
        tile  {
            mirror (x 0…1=0, y 0…1=0) >> shader.render˚mirror
            repeat (x -1…1=0, y -1…1=0) >> shader.render˚repeat
            shift (x 0…1=0.5, y 0…1=0.5) <> shader.compute.draw
        }
        color {
            fade  (val 0…1=0.5) <> sky.color.xfade
            plane (val 0…1=0.1) <> shader.compute.color
            fill_0 (tap 0…1)   <> sky.draw.screen.fill(0)
            fill_1 (tap 0…1)   <> sky.draw.screen.fill(1)
        }
        speed {
            fps (seg 0…60=60)  <> sky.main.fps
            run (tog 0…1=1 )   <> sky.main.run
            anim(val 0…1=0.24) <> sky.main.anim
        }
    }
    brush {
        size  (val 0…1=0.5) <> sky.draw.brush.size
        press (tog 0…1=1  ) <> sky.draw.brush.press
        tilt  (tog 0…1=0) <> sky.input.tilt
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
        stream (tog 0…1=0  ) <> shader.compute.camera.on
        facing (tog 0…1=1  ) <> shader.compute.camera.flip
        mask   (tog 0…1=1  ) 
        mix    (val 0…1=0.5) <> shader.compute.camix.mix
    }
    network (symbol "network") {
        bonjour (peer "bonjour") <> sky.main.peer.bonjour
        follow  (tog 0…1=1) <> sky.main.peer.follow
        midi    (tog 0…1=1) <> sky.main.peer.midi
    }
}
model.canvas {
    cube  {
        motion (tog 0…1=1)
        rotate (x -1…1=0, y -1…1=0)
        back (tog 0…1=1)
        show (tog 0…1=1) <> shader.render.cubemap.on
    }
    plato {
        shade {
            colors (x 0…1=0, y 0…1=0)
            wire   (tog 0…1)
            shadow (tog 0…1=1)
            invert (tog 0…1=1)
            style  (seg 0…2=1)
        }
        morph (tog 0…1=1)
        phase (x 0…1, y 0…1)
        zoom  (val 0…1=1)
        show  (tog 0…1=1)  <> shader.render.plato.on
    }
}
