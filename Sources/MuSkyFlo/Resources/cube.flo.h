model.canvas {
    cube {
        motion (tog 0…1~1)
        rotate (x -1…1~0, y -1…1~0)
        back (tog 0…1~1)
        show (tog 0…1~0) <> shader.render.cubemap.on
    }
}
_menu.canvas {
    cube (sym "cube") {
        motion (sym "gyroscope")
        rotate (svg "icon.direction")
        back   (sym "cube")
        show   (sym "cube.fill")
    }
}
