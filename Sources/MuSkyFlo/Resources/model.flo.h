model {
    canvas {
        tile  {
            mirror (x  0…1~0,   y  0…1~0)   <> shader.render˚mirror ^ sky.main.anim
            repeat (x -1…1~0,   y -1…1~0)   <> shader.render˚repeat ^ sky.main.anim
            shift  (x  0…1~0.5, y  0…1~0.5) <> shader.compute.draw ^ sky.main.anim
        }
        color {
            fade (x 0…1~0.5,
                  y 0…1~0.1)
            >> shader.compute.color
            >> sky.color.xfade
            ^ sky.main.anim

            fill_0 (%1) <> sky.draw.screen.fill(0)
            fill_1 (%1) <> sky.draw.screen.fill(1)
        }
        speed {
            fps (0_60~60)  <> sky.main.fps
            run (%2~1 )    <> sky.main.run
            anim(0…1~0.24) <> sky.main.anim
        }
    }
    brush {
        size  (0…1~0.5)   <> sky.draw.brush.size
        press (%2~1)      <> sky.draw.brush.press
        tilt  (%2~0)      <> sky.input.tilt
        index (1_255~127) <> sky.draw.brush.index
    }
    cell {
        fade  (1.61…3~1.61) <> shader.cell.fade
        ave   (0…1~0.5)     <> shader.cell.ave
        melt  (0…1~0.5)     <> shader.cell.melt
        tunl  (0_5~1)       <> shader.cell.tunl
        zha   (0_6~2)       <> shader.cell.zha
        slide (0_7~3)       <> shader.cell.slide
        fred  (0_4~4)       <> shader.cell.fred
    }
    camera {
        stream (%2~0)      <> shader.compute.camera.on
        facing (%2~1)      <> shader.compute.camera.flip
        mask   (%2~1)
        mix    (0…1~0.5)   <> shader.compute.camix.mix
    }
    network {
        bonjour (peer "bonjour") <> sky.main.peer.bonjour
        follow  (%2~1) <> sky.main.peer.follow
        midi    (%2~1) <> sky.main.peer.midi
    }
}
