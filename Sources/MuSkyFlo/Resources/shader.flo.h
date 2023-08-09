shader {
    pipeline {
        draw
        slide
        color
        flatmap
        plato
    }
    cell {
        fade  (1.2…3  ) >> on(1) { on(%2) }
        ave   (0…1=0.5) >> on(1) { on(%2) }
        melt  (0…1=0.5) >> on(1) { on(%2) }
        tunl  (0…5=1  ) >> on(1) { on(%2) }
        slide (0…7=3  ) >> on(1) { on(%2) }
        fred  (0…4=4  ) >> on(1) { on(%2) }
        zha   (0…6=2  ) >> on(1) { on(%2) bits(2…4=3) loops(11) }
        cell˚on >> cell˚on(0)
    }
    compute {
        draw (x 0…1~0.5, y 0…1~0.5) { on(0…1~1) }
        record { on(0…1~0) }
        camera { on(0…1~0) front (%2~1) }
        camix  { mix(0…1~0.5) }
        color (y 0…1~0.1)

    }
    render {
        flatmap {
            frame(x 0, y 0, w 1080, h 1920)
            repeat(x -1…1~0, y -1…1~0)
            mirror(x  0…1~0, y  0…1~0)
        }
        cubemap {
            frame(x 0, y 0, w 1080, h 1920)
            repeat(x -1…1~0, y -1…1~0)
            mirror(x  0…1~0, y  0…1~0)
            gravity(0…2~0)
            rotate(x -1…1~0, y -1…1~0)
            on(%2~0)
        }
        plato { on(%2~0) }
    }
}
