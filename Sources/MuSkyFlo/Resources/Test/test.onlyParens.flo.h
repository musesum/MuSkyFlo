
// here is a faild rewrite of sky syntax using only ()
model
(canvas
 (tile
  (
   mirror (vxy, x 0…1~0, y 0…1~0) <> shader.render˚mirror ^ sky.main.anim
   repeat (vxy, x -1…1~0, y -1…1~0) <> shader.render˚repeat ^ sky.main.anim
   shift  (vxy, x 0…1~0.5, y 0…1~0.5) <> shader.compute.draw ^ sky.main.anim
   )
  color
  (
   fade (val, 0…1~0.5) <> sky.color.xfade ^ sky.main.anim
   plane (val, 0…1~0.1) <> shader.compute.color ^ sky.main.anim
   fill_0 (tap, 0…1) <> sky.draw.screen.fill(0)
   fill_1 (tap, 0…1) <> sky.draw.screen.fill(1)
   )
  speed
  (
   fps  (seg, 0…60~60 ) <> sky.main.fps
   run  (tog, 0…1~1   ) <> sky.main.run
   anim (val, 0…1~0.24) <> sky.main.anim
   )
  )
 brush
 (
  size  (val, 0…1~0.5)   <> sky.draw.brush.size
  press (tog, 0…1~1)     <> sky.draw.brush.press
  tilt  (tog, 0…1~0)     <> sky.input.tilt
  index (seg, 1…255~127) <> sky.draw.brush.index
  )
 cell
 (
  fade  (val, 1.61…3~1.61) <> shader.cell.fade
  ave   (val, 0…1~0.5    ) <> shader.cell.ave
  melt  (val, 0…1~0.5    ) <> shader.cell.melt
  tunl  (seg, 0…5~1      ) <> shader.cell.tunl
  zha   (seg, 0…6~2      ) <> shader.cell.zha
  slide (seg, 0…7~3      ) <> shader.cell.slide
  fred  (seg, 0…4~4      ) <> shader.cell.fred
  )
 camera
 (
  stream (tog, 0…1~0) <> shader.compute.camera.on
  facing (tog, 0…1~1) <> shader.compute.camera.flip
  mask   (tog, 0…1~1)
  mix    (val, 0…1~0.5) <> shader.compute.camix.mix
  )
 network
 (
  bonjour (peer, "bonjour") <> sky.main.peer.bonjour
  follow  (tog, 0…1~1) <> sky.main.peer.follow
  midi    (tog, 0…1~1) <> sky.main.peer.midi
  )
 )
c   n % 12 in major
c♯ (n-1)%12 in major
c♭ (n+1)%12 in major


_dorian     ( 2 1 2 2 2 1 2           )
_phrygian   (   1 2 2 2 1 2 2         )
_lydian     (     2 2 2 1 2 2 1       ) fgabcde
_mixolydian (       2 2 1 2 2 1 2     ) cdefgab
_aeolian    (         2 1 2 2 1 2 2   )
_locrian    (           1 2 2 1 2 2 2 )

dorian     (0 2 3 5 7 9 10 12           )
phrygian   (0   1 3 5 7 8 10 12         )
lydian     (0     2 4 5 7 9 11 12       )
mixolydian (0       2 4 5 7 9 10 12     )
aeolian    (0         2 3 5 7 8 10 12   )
locrian    (0           1 3 5 6 8 10 12 )






_natural_minor  (2, 1, 2, 2, 1, 2, 2)
_harmonic_minor (2, 1, 2, 2, 1, 3, 1)
_melodic_minor  (2, 1, 2, 2, 2, 2, 1)

_major          (2 2 1 2 2 2 1 )
major          (0 2 4 5 7 9 11)


model.canvas
(cube
 (motion (tog, 0…1~1)
  rotate (vxy, x -1…1~0, y -1…1~0)
  back   (tog, 0…1~1)
  show   (tog, 0…1~0) <> shader.render.cubemap.on
  )
 )
_menu.canvas
(cube ("cube.sf")
 (motion ("gyroscope.sf")
  rotate ("icon.direction.svg")
  back   ("cube.sf")
  show   ("cube.fill.sf")
  )
 )

model
(
 canvas
 (
  tile
  (
   mirror (vxy, x 0…1~0, y 0…1~0)
   <> shader.render˚mirror
   ^ sky.main.anim

   repeat (vxy, x -1…1~0, y -1…1~0)
   <> shader.render˚repeat
   ^ sky.main.anim

   shift (vxy, x 0…1~0.5, y 0…1~0.5)
   <> shader.compute.draw
   ^ sky.main.anim
   )
  color
  (
   fade (val, 0…1~0.5) <> sky.color.xfade ^ sky.main.anim
   plane (val, 0…1~0.1) <> shader.compute.color ^ sky.main.anim
   fill_0 (tap, 0…1) <> sky.draw.screen.fill(0)
   fill_1 (tap, 0…1) <> sky.draw.screen.fill(1)
   )
  speed
  (
   fps  (seg, 0…60~60 ) <> sky.main.fps
   run  (tog, 0…1~1   ) <> sky.main.run
   anim (val, 0…1~0.24) <> sky.main.anim
   )
  )
 brush
 (
  size  (val, 0…1~0.5)   <> sky.draw.brush.size
  press (tog, 0…1~1  )   <> sky.draw.brush.press
  tilt  (tog, 0…1~0)     <> sky.input.tilt
  index (seg, 1…255~127) <> sky.draw.brush.index
  )
 cell
 (
  fade  (val, 1.61…3~1.61) <> shader.cell.fade
  ave   (val, 0…1~0.5    ) <> shader.cell.ave
  melt  (val, 0…1~0.5    ) <> shader.cell.melt
  tunl  (seg, 0…5~1      ) <> shader.cell.tunl
  zha   (seg, 0…6~2      ) <> shader.cell.zha
  slide (seg, 0…7~3      ) <> shader.cell.slide
  fred  (seg, 0…4~4      ) <> shader.cell.fred
  )
 camera
 (
  stream (tog, 0…1~0  ) <> shader.compute.camera.on
  facing (tog, 0…1~1  ) <> shader.compute.camera.flip
  mask   (tog, 0…1~1  )
  mix    (val, 0…1~0.5) <> shader.compute.camix.mix
  )
 network
 (
  bonjour (peer, "bonjour") <> sky.main.peer.bonjour
  follow  (tog, 0…1~1) <> sky.main.peer.follow
  midi    (tog, 0…1~1) <> sky.main.peer.midi
  )
 )
_menu.canvas ("icon.canvas.svg")
(
 tile ("icon.tile.svg")
 (
  mirror ("icon.mirror.svg")
  repeat ("icon.repeat.arrows.svg")
  shift  ("icon.direction.svg")
  )
 color("icon.pal.main.png")
 (
  fade   ("icon.gradient.svg")
  plane  ("icon.layers.svg")
  fill_0 ("drop.sf")
  fill_1 ("drop.fill.sf")
  )
 speed ("icon.speed.png")
 (
  fps  ("speedometer.sf")
  run  ("goforward.sf")
  anim ("bolt.fill.sf")
  )
 brush ("icon.brush.svg")
 (
  size  ("icon.size.dot.svg")
  press ("scribble.variable.sf")
  tilt  ("angle.sf")
  index ("calendar.day.timeline.left.sf")
  )
 cell ("icon.ca.grid.svg")
 (
  fade  ("icon.cell.fade.png" )
  ave   ("icon.cell.ave.png"  )
  melt  ("icon.cell.melt.png" )
  tunl  ("icon.cell.tunl.png" )
  zha   ("icon.cell.zha.png"  )
  slide ("icon.cell.slide.png")
  fred  ("icon.cell.fred.png" )
  )
 camera ("camera.sf")
 (
  stream ("video.sf")
  facing ("icon.camera.facing.svg")
  mask   ("icon.face.svg")
  mix    ("camera.filters.sf")
  )
 network ("network.sf")
 (
  bonjour ("bonjour.sf")
  follow  ("shared.with.you.sf")
  midi    ("pianokeys.inverse.sf")
  )

 model.canvas.plato
 (
  shade
  (
   phase  (vxy, x 0…1, y 0.9…1.1)
   convex (var, 0.9…1.1~1) ^ sky.main.anim
   colors (vxy, x 0…255~0, y 0…1~0)
   shadow (vxy, x 0…1~0, y 0…1~0)
   invert (val, 0…1~1)
   )
  zoom  (val, 0…1~1) ^ sky.main.anim
  wire  (tog, 0…1~0)
  morph (tog, 0…1~1)
  show  (tog, 0…1~0) <> shader.render.plato.on
  )
 _menu.canvas.plato("icon.plato.wire.svg")
 (
  shade ("icon.peacock.svg")
  (
   phase  ("calendar.day.timeline.left.sf")
   convex ("icon.convex.svg")
   colors ("figure.stair.stepper.sf")
   shadow ("shadow.sf")
   invert ("circle.lefthalf.filled.sf")
   )
  zoom  ("icon.zoom.svg")
  morph ("icon.counter.svg")
  wire  ("icon.wireframe.svg")
  show  ("icon.plato.show.svg")
  )

 midi.cc.skypad
 (
  zoom    (cc ≈  4, chan, time, val 0_127 <> model.canvas.plato.zoom)
  convex  (cc ≈  5, chan, time, val 0_127 <> model.canvas.plato.shade.convex)
  colorY  (cc ≈  6, chan, time, val 0_127 <> model.canvas.plato.shade.colors.y)
  camix   (cc ≈  9, chan, time, val 0_127 <> model.camix.mix)
  fade    (cc ≈ 10, chan, time, val 0_127 <> model.canvas.color.fade)
  plane   (cc ≈ 11, chan, time, val 0_127 <> model.canvas.color.plane)
  shift.x (cc ≈ 12, chan, time, val 0_127 <> model.canvas.tile.shift.x)
  shift.y (cc ≈ 13, chan, time, val 0_127 <> model.canvas.tile.shift.y)
  repeat.x(cc ≈ 14, chan, time, val 0_127 <> model.canvas.tile.repeat.x)
  repeat.y(cc ≈ 15, chan, time, val 0_127 <> model.canvas.tile.repeat.y)
  )
 sky 'visual music synth'
 (
  main 'main controls'
  (
   fps   1…60~60 'frames per second'
    run   0…1~1   'currently running'
    anim  0…1~0.9 'animation transition speed'
    )
   network
   (
    bonjour         'bonjour status'
    (
     follow 0…1~1  'follow remote events'
     midi   0…1~1  'follow midi events'
     )
    color 'false color mapping palette'
    (pal0"roygbik", pal1"wKZ", xfade 0…1~0.5)
    input 'phone and tablet pencil input'
    (
     azimuth  (x -0.2…0.2, y -0.2…0.2)  >> shader.compute.draw
     accel    (x -0.3…0.3, y -0.3…0.3, z -0.3…0.3, on 0…1~1)  'accelerometer'
     radius   1…92~9     'finger silhouette'
     tilt     0…1~1
     force    0…0.5  >> draw.brush.size
     )
    draw                   'draw on metal layer'
    (
     screen.fill 0…1~0   'fill cellular automata universe'
     brush               'type of brush and range'
     (
      size  1…64~10     'range of radius'
      press 0…1~1       'pressure changes size'
      index 1…255~127   'index in 256 color palette'
      )
     line                  'place holder for line drawing'
     (
      prev (x 0…1, y 0…1) 'staring point of segment
      next (x 0…1, y 0…1) 'endint point of segment
      )
     dot
     (
      on (x, y, z)
      off (x, y, z)
      )
     )
    )
   shader
   (
    pipeline(draw, slide, color, flatmap)
    cell
    (
     fade  (1.62…3~1.62 >> on(1), on %2~0 >> cell˚on(0))
     ave   (0…1~0.5     >> on(1), on %2~1 >> cell˚on(0))
     melt  (0…1~0.5     >> on(1), on %2~0 >> cell˚on(0))
     tunl  (0…5~1       >> on(1), on %2~0 >> cell˚on(0))
     slide (0…7~3       >> on(1), on %2~0 >> cell˚on(0))
     fred  (0…4~4       >> on(1), on %2~0 >> cell˚on(0))
     zha   (0…6~2       >> on(1), on %2~0 >> cell˚on(0), bit 2…4~3, loops 11)
     )
    compute
    (
     draw (x 0…1~0.5, y 0…1~0.5, on 0…1~1)
     record (on 0…1~0)
     camera (on 0…1~0, flip 0)
     camix  (mix 0…1~0.5)
     color (0…1~0.1)
     tile
     (
      repeat(x -1…1~0, y -1…1~0)
      mirror(x 0…1~0, y 0…1~0)
      )
     )
    render
    (
     flatmap
     (
      frame(x 0, y 0, w 1080, h 1920)
      repeat(x -1…1~0, y -1…1~0)
      mirror(x  0…1~0, y  0…1~0)
      )
     cubemap
     (
      frame(x 0, y 0, w 1080, h 1920)
      repeat(x -1…1~0, y -1…1~0)
      mirror(x 0…1~0, y 0…1~0)
      gravity(0…2~0)
      on(0…1~0)
      )
     plato
     ( on(0…1~0) )
     )
    )

   body(left, right)
   .(shoulder.elbow.wrist
     (thumb, index, middle, ring, pinky)
     .(meta, prox, dist)
     hip.knee.ankle.toes)
   ˚˚ (joint(x, y, z) )

   skeleton
   (left
    (shoulder
     (elbow
      (wrist
       (thumb
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        index
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        middle
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        ring
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        pinky
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
       bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
      bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
     hip
     (knee
      (ankle
       (toes.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
        bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
       bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
      bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
     bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
     )
    right
    (shoulder
     (elbow
      (wrist
       (thumb
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        index
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        middle
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        ring
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        pinky
        (meta.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         prox.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         dist.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
         bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
        bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
       bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
      bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
      )
     hip
     (knee
      (ankle
       (toes.bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
        bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
       bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
      bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
     bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000))
    bone (x 0…1, y 0…1, z 0…1, roll %360, pitch %360, yaw %360, mm 0…1000)
    )
   ˚˚ <> ..
