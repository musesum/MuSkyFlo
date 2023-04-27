shader {

    pipeline {
        draw
        slide
        color
        flatmap
    }

    anim(0…1=0.5) << sky.main.anim
    render.plato.on(0…1=0)
    cell {
        fade  (1.62…3=1.62) { on(0…1=0) >> cell˚on(0) << .. }
        ave   (0…1=0.5) { on(0…1=1) >> cell˚on(0) << .. }
        melt  (0…1=0.5) { on(0…1=0) >> cell˚on(0) << .. }
        tunl  (0…5=1  ) { on(0…1=0) >> cell˚on(0) << .. }
        slide (0…7=3  ) { on(0…1=0) >> cell˚on(0) << .. }
        fred  (0…4=4  ) { on(0…1=0) >> cell˚on(0) << .. }
        zha   (0…6=2  ) { on(0…1=0) >> cell˚on(0) << .. bits(2…4=3) loops(11)  }
    }
    compute {
        draw (x 0…1=0.5, y 0…1=0.5) { on(0…1=1) }
        record { on(0…1=0) }
        camera { on(0…1=0) flip (0) }
        camix  { mix(val 0…1=0.5) <~ anim }
        color(val 0…1=0.1) <~ anim // bitplane
        tile {
            repeat(x -1…1=0, y -1…1=0)  <~ anim
            mirror(x 0…1, y 0…1) <~ anim
        }
    }
    render {
        flatmap {
            frame(x 0, y 0, w 1080, h 1920)
            repeat(x -1…1=0, y -1…1=0) //<~ anim
            mirror(x 0…1, y 0…1) //<~ anim
        }
        cubemap {
            frame(x 0, y 0, w 1080, h 1920)
            repeat(x -1…1=0, y -1…1=0)  <~ anim
            mirror(x 0…1, y 0…1) <~ anim
            gravity(0…2)
            on(0…1=0)
        }
        plato { on(0…1=0) }
    }
}
