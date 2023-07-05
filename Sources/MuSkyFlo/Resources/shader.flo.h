shader {
    pipeline {
        draw
        slide
        color
        flatmap
    }
    cell {
        fade  (1.62…3~1.62) >> on { on(%2~0) >> cell˚on(0) }
        ave   (0…1~0.5    ) >> on { on(%2~1) >> cell˚on(0) }
        melt  (0…1~0.5    ) >> on { on(%2~0) >> cell˚on(0) }
        tunl  (0…5~1      ) >> on { on(%2~0) >> cell˚on(0) }
        slide (0…7~3      ) >> on { on(%2~0) >> cell˚on(0) }
        fred  (0…4~4      ) >> on { on(%2~0) >> cell˚on(0) }
        zha   (0…6~2      ) >> on { on(%2~0) >> cell˚on(0) bits(2…4~3) loops(11)  }
    }
    compute {
        draw (x 0…1~0.5, y 0…1~0.5) { on(0…1~1) }
        record { on(0…1~0) }
        camera { on(0…1~0) front (%2~1) }
        camix  { mix(0…1~0.5) }
        color (y 0…1~0.1)
        tile { 
            repeat(x -1…1~0, y -1…1~0)
            mirror(x 0…1~0, y 0…1~0)
        }
    }
    render {
        flatmap {
            frame(x 0, y 0, w 1080, h 1920)
            repeat(x -1…1~0, y -1…1~0)
            mirror(x  0…1~0, y  0…1~0)
        }
    }
    render_ {
        cubemap {
            frame(x 0, y 0, w 1080, h 1920)
            repeat(x -1…1~0, y -1…1~0)
            mirror(x  0…1~0, y  0…1~0)
            gravity(0…2~0)
            on(%2~0)
        }
        plato { on(%2~0) }
    }
}
