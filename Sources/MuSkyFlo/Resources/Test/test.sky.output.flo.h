sky { // visual music synth
    main { // main controls
        fps(1…60=60) // frames per second
        run(1) // currently running
    }
    pipeline { // default metal pipeline at atartup
        draw // drawing layer
        ave // compute layer
        color // colorizing layer
        render // render layer al
    }
    color { // false color mapping palette
        pal0("roygbik") // palette 0: (r)ed (o)range (y)ellow …
        pal1("wKZ") // palette 1: (w)hite blac(K) fractali(Z)e
        xfade(val 0…1=0.5)
    }
    input { // phone and tablet pencil input
        azimuth(x -0.2…0.2, y -0.2…0.2)>>shader.pipe.draw
        accel(x -0.3…0.3, y -0.3…0.3, z -0.3…0.3) { // accelerometer
            on(0…1)
        }
        radius(1…92=9) // finger silhouette
        tilt(0…1) // use tilt
        force(0…0.5)>>sky.draw.brush.size // pen pressure
    }
    draw { // draw on metal layer
        screen { // fill 32 bit universe
            fill(0) // all zeros 0x00000000
        }
        brush { // type of brush and range
            size(1…64=10) // range of radius
            press(0…1=1) // pressure changes size
            index(1…255=127) // index in 256 color palette
                             // <<(osc.tuio.z osc.manos˚z) // redirect from OSC
        }
        line { // place holder for line drawing
            prev(x 0…1, y 0…1) // staring point of segment
            next(x 0…1, y 0…1) // endint point of segment
        }
        dot(x, y, z)
    }
}
menu {
    SW {
        view {
            canvas(sym "photo.artframe") {
                tile(img "icon.shader.tile.png") {
                    mirror(sym "arrowtriangle.left.and.line.vertical.and.arrowtriangle.right")
                    repeat(sym "rectangle.grid.2x2")
                    shift(img "icon.cell.scroll")
                    tilt(img "icon.pen.tilt")
                }
                color(img "icon.pal.main") {
                    fade(sym "slider.horizontal.below.rectangle")
                    plane(sym "square.3.layers.3d.down.right")
                    zero(sym "drop")
                    one(sym "drop.fill")
                }
                speed(img "icon.speed") {
                    fps(sym "speedometer")
                    run(sym "goforward")
                }
            }
            brush(sym "paintbrush.pointed") {
                size(sym "circle.circle")
                press(img "icon.pen.press")
                tilt(img "icon.pen.tilt") //(sym "angle")
            }
            cell(sym "circle.grid.3x3") {
                fade(img "icon.cell.fade")
                ave(img "icon.cell.ave")
                melt(img "icon.cell.melt")
                tunl(img "icon.cell.tunl")
                zha(img "icon.cell.zha")
                slide(img "icon.cell.slide")
                fred(img "icon.cell.fred")
            }
            cam(sym "camera") {
                snap(sym "camera.shutter.button")
                fake(sym "face.dashed")
                real(sym "face.smiling")
                face(sym "arrow.triangle.2.circlepath.camera")
                mix(sym "slider.horizontal.below.rectangle")
            }
        }
        model {
            canvas {
                tile {
                    mirror(x 0…1=0, y 0…1=0)<>shader.pipe.render.mirror
                    repeat(x -1…1=0, y -1…1=0)<>shader.pipe.render.repeat
                    shift(x 0…1=0.5, y 0…1=0.5)//<>shader.pipe.draw
                    tilt(tog 0…1=0)<>sky.input.tilt
                }
                color {
                    fade(val 0…1=0)<>sky.color.xfade
                    plane(val 0…1=0)<>shader.pipe.color
                    zero(tap 0…1=0)>>sky.draw.screen.fill(0)
                    one(tap 0…1=0)>>sky.draw.screen.fill(1)
                }
                speed {
                    fps(seg 0…60=60)<>sky.main.fps
                    run(tog 0…1=1)<>sky.main.run
                }
            }
            brush {
                size(val 0…1=0.5)<>(sky.draw.brush.size, menu.SW.model.brush.press(0))
                press(tog 0…1=1)<>sky.draw.brush.press
                tilt(tog 0…1=1)<>sky.input.tilt
            }
            cell {
                fade(val 2…3=2.2)>>shader.cell.fade
                ave(val 0…1=0.5)>>shader.cell.ave
                melt(val 0…1=0.5)>>shader.cell.melt
                tunl(seg 0…5=1)>>shader.cell.tunl
                zha(seg 0…6=2)>>shader.cell.zha
                slide(seg 0…7=3)>>shader.cell.slide
                fred(seg 0…4=4)>>shader.cell.fred
            }
            cam {
                snap(tap 0…1=0)
                fake(tog 0…1=0)<>shader.pipe.camix.on
                real(tog 0…1=1)<>shader.pipe.camera.on
                face(tog 0…1=1)<>shader.pipe.camera.flip
                mix(val 0…1=0.5)<>shader.pipe.camix.mix
            }
        }
    }
    SE { // copy southwest corner to southeast corner
        view {
            canvas(sym "photo.artframe") {
                tile(img "icon.shader.tile.png") {
                    mirror(sym "arrowtriangle.left.and.line.vertical.and.arrowtriangle.right")
                    repeat(sym "rectangle.grid.2x2")
                    shift(img "icon.cell.scroll")
                    tilt(img "icon.pen.tilt")
                }
                color(img "icon.pal.main") {
                    fade(sym "slider.horizontal.below.rectangle")
                    plane(sym "square.3.layers.3d.down.right")
                    zero(sym "drop")
                    one(sym "drop.fill")
                }
                speed(img "icon.speed") {
                    fps(sym "speedometer")
                    run(sym "goforward")
                }
            }
            brush(sym "paintbrush.pointed") {
                size(sym "circle.circle")
                press(img "icon.pen.press")
                tilt(img "icon.pen.tilt") //(sym "angle")
            }
            cell(sym "circle.grid.3x3") {
                fade(img "icon.cell.fade")
                ave(img "icon.cell.ave")
                melt(img "icon.cell.melt")
                tunl(img "icon.cell.tunl")
                zha(img "icon.cell.zha")
                slide(img "icon.cell.slide")
                fred(img "icon.cell.fred")
            }
            cam(sym "camera") {
                snap(sym "camera.shutter.button")
                fake(sym "face.dashed")
                real(sym "face.smiling")
                face(sym "arrow.triangle.2.circlepath.camera")
                mix(sym "slider.horizontal.below.rectangle")
            }
        }
        model {
            canvas {
                tile {
                    mirror(x 0…1=0, y 0…1=0)<>shader.pipe.render.mirror
                    repeat(x -1…1=0, y -1…1=0)<>shader.pipe.render.repeat
                    shift(x 0…1=0.5, y 0…1=0.5)<>shader.pipe.draw
                    tilt(tog 0…1=0)<>sky.input.tilt
                }
                color {
                    fade(val 0…1=0)<>sky.color.xfade
                    plane(val 0…1=0)<>shader.pipe.color
                    zero(tap 0…1=0)>>sky.draw.screen.fill(0)
                    one(tap 0…1=0)>>sky.draw.screen.fill(1)
                }
                speed {
                    fps(seg 0…60=60)<>sky.main.fps
                    run(tog 0…1=1)<>sky.main.run
                }
            }
            brush {
                size(val 0…1=0.5)<>(sky.draw.brush.size, menu.SE.model.brush.press(0))
                press(tog 0…1=1)<>sky.draw.brush.press
                tilt(tog 0…1=1)<>sky.input.tilt
            }
            cell {
                fade(val 2…3=2.2)>>shader.cell.fade
                ave(val 0…1=0.5)>>shader.cell.ave
                melt(val 0…1=0.5)>>shader.cell.melt
                tunl(seg 0…5=1)>>shader.cell.tunl
                zha(seg 0…6=2)>>shader.cell.zha
                slide(seg 0…7=3)>>shader.cell.slide
                fred(seg 0…4=4)>>shader.cell.fred
            }
            cam {
                snap(tap 0…1=0)
                fake(tog 0…1=0)<>shader.pipe.camix.on
                real(tog 0…1=1)<>shader.pipe.camera.on
                face(tog 0…1=1)<>shader.pipe.camera.flip
                mix(val 0…1=0.5)<>shader.pipe.camix.mix
            }
        }
    }
}
shader {
    model {
        cell {
            fade(0…1=0.5) {
                on(0…1=0)>>(shader.cell.fade.on(0), shader.cell.ave.on(0), shader.cell.melt.on(0), shader.cell.tunl.on(0), shader.cell.slide.on(0), shader.cell.fred.on(0), shader.cell.zha.on(0))<<shader.cell.fade
            }
            ave(0…1=0.5) {
                on(0…1=1)>>(shader.cell.fade.on(0), shader.cell.ave.on(0), shader.cell.melt.on(0), shader.cell.tunl.on(0), shader.cell.slide.on(0), shader.cell.fred.on(0), shader.cell.zha.on(0))<<shader.cell.ave
            }
            melt(0…1=0.5) {
                on(0…1=0)>>(shader.cell.fade.on(0), shader.cell.ave.on(0), shader.cell.melt.on(0), shader.cell.tunl.on(0), shader.cell.slide.on(0), shader.cell.fred.on(0), shader.cell.zha.on(0))<<shader.cell.melt
            }
            tunl(0…5=1) {
                on(0…1=0)>>(shader.cell.fade.on(0), shader.cell.ave.on(0), shader.cell.melt.on(0), shader.cell.tunl.on(0), shader.cell.slide.on(0), shader.cell.fred.on(0), shader.cell.zha.on(0))<<shader.cell.tunl
            }
            slide(0…7=3) {
                on(0…1=0)>>(shader.cell.fade.on(0), shader.cell.ave.on(0), shader.cell.melt.on(0), shader.cell.tunl.on(0), shader.cell.slide.on(0), shader.cell.fred.on(0), shader.cell.zha.on(0))<<shader.cell.slide
            }
            fred(0…4=4) {
                on(0…1=0)>>(shader.cell.fade.on(0), shader.cell.ave.on(0), shader.cell.melt.on(0), shader.cell.tunl.on(0), shader.cell.slide.on(0), shader.cell.fred.on(0), shader.cell.zha.on(0))<<shader.cell.fred
            }
            zha(0…6=2) {
                on(0…1=0)>>(shader.cell.fade.on(0), shader.cell.ave.on(0), shader.cell.melt.on(0), shader.cell.tunl.on(0), shader.cell.slide.on(0), shader.cell.fred.on(0), shader.cell.zha.on(0))<<shader.cell.zha
                bits(2…4=3)
                loops(11)
            }
        }
        pipe {
            draw(x 0…1=0.5, y 0…1=0.5) {
                on(0…1=0)
            }
            record {
                on(0…1=0)
            }
            camera {
                on(0…1=0)
                flip(0)
            }
            camix {
                on(0…1=0)
                mix(val 0…1=0.5)
            }
            color(val 0…1=0.1) // bitplane
            render {
                frame(x 0, y 0, w 1080, h 1920)
                repeat(x -1…1=0, y -1…1=0)
                mirror(x 0…1, y 0…1)
            }
        }
    }
    file {
        cell {
            fade("cell.fader.metal")
            ave("cell.ave.metal")
            melt("cell.melt.metal")
            tunl("cell.tunl.metal")
            slide("cell.slide.metal")
            fred("cell.fred.metal")
            zha("cell.zha.metal")
        }
        pipe {
            record camera("cell.camera.metal")
            camix("cell.camix.metal")
            draw("pipe.draw.metal")
            render("pipe.render.metal")
            color("pipe.color.metal")
        }
    }
}
