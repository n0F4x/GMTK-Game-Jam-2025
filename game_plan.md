# Stuck in yesterday

## Colour codes

- Original Plans
- <span style="color: green">Suggestions</span>
- <span style="color: red">Final decision</span>
- <span style="color: cyan">Added plan</span>

## Story
Youre trying to make it past the demon waves, because you got cursed by some cigan, because youre so selfish and mean person. Each time you die, you will wake up again. Tomorrow you want to meet your daughter after a long time, but u cant because youre in loop. After all enemies defeated, youre having a boss fight with Satan, or some kind of Devil. At the end, you cant defeat him (you will still fight in the boss fight), so youre dying on purpose, but your bravery convinces the God and all holy spirits to revive you. The curse is broken just as that. Youre going to meet your daughter blah blah.

## Game idea
Time loop

## Main character
single dad that has a daughter he loves with all of his heart. (mother died of cancer)

## Theme
Basically going thru hell. After you open the doors out of your home, you will end up in hell.

## Type
small open world, waves of enemies
<p style="color: green">Small platform with spawning enemies see "Brotato" game OR</p>
<p style="color: green">Rooms with monsters (possible mixture)</p>

## Style
Undertale, pixelart

## Conversations
monolog, dialog, text window on the bottom of the screen.

## Others
if you die once, character should be confused if he hasn't done this shit yet.

## View
2D, top-down


## Plan
- Wake up in the morning
- Objective: Have to go through all levels by the end of the day without dying
- Player will probably die or time out at least a few times before beating the game, need to balance
- <span style="color: red">Roguelike</span> or roguelite?
- Boss fight at the last level, need to kill the boss, but it will not actually die
- <p style="color: green">Minibosses on some selected levels</p>
- Next morning meet with daughter back in the overworld
- Levels: start place is overworld, and as we go down each level is successively darker and more hellish
- Level elements:
  - Spawners
  - Specific spots where enemies spawn on level load
  - Some items on the ground
  - <span style="color: cyan">Enemies drop experience</span>
  - <p style="color: cyan">Power ups dropped by barrels or at level up</p>
  - <p style="color: cyan">Levelling up gives power up options</p>
  - <p style="color: green">Other variation: players acquire not just xp from slaying mobs, but some kind of token or currency as well which they can spend on upgrades (be it better weapon or power up in a shop after each level) [time consuming I think]</p>
  - Decorative stuff (crates, etc.)


- Either weapon damage is increased or you get some kind of buff
- <p style="color: green">Weapon dmg can be increased through better weapon rarities, or through acquired passive power ups</p>
- Artificial restart points at end of certain levels
- <p style="color: green">Or you scale the difficulty in order to be the game unbeatable at first attempts [rougelite feature]</p>
- Difficulty chooser at the menu
- Difficulty scales with game progress (enemies become harder and/or harder enemy types spawn)

## Weapon
- <p style="color: green">Ranged: Pistol</p>

## Monsters
- <p style="color: green">Final boss: Lucifer king of hell</p>
- <p style="color: green">Miniboss (optional): Hell knight, Flesh (made up of demons) </p>
- <p style="color: green">Enemies: Demon, Imp, Dreadfiend (sluggish, larger demon), ghost</p>

## Ideas
- You plant a bomb or unlock a shortcut that pays off in future loops
- <p style="color: green">Weapons could be made like this: </p>

  - <p style="color: green">Guns as main weapon type [left click]</p>
  - <p style="color: green">Melee weapons as secondary weapon [right click]</p>
  - <p style="color: green">passives for melee for possible playthrough with only melee</p>

## Questions
- How many levels? 5
- Draw sketch of the levels
- How many enemy types?
- <p style="color: green">Minibosses?</p>
- Plan UI (health, weapon info, character info, dialog box)

## Suggestions
- <p style="color: green">If weapon rarities, power ups for both melee and ranged not possible within the given timeframe, then we could skip weapon rarities and focus more on power ups and a few gun types/ melee types</p>

## Levels
- Level 0: Home
- Level 1: Earthlike (dirt), unsettling - brown
- Level 2: Cold yet not icy (full of gold and treasures) - gray
- Level 3: dry rocky swamp - dark green
- Level 4: vulcan, lava, fire - red
- Level 5: frozen ice - light blue
- Single wood-iron like door and trapdoor

## Power ups (buy at the end of level with xp)
- Increase Movement speed
- Increase max health
- Increase Damage
- Increase firing rate
- Increase crit chance
- Increase crit multiplier
- Increase life steal chance

## Healing
- Life steal (chance of stealing some health from enemy when killed)
- Set health to max at start of new level

## Get XP
- by killing enemies

## Needed textures
- Main character looking to the left
- Floor tile, Straight wall tile, Inner wall corner tile, Outer wall corner tile for all 5 levels
  - possibly some alternate floor tiles with small variations so it is not as repetitive
- Power up textures
- Single wood-iron like door and trapdoor

## Level.txt format
-  : nothing
- 0: floor tile
- T: top wall
- B: bottom wall
- L: left wall
- R: right wall
- 1: top-left outer wall corner
- 2: top-right outer wall corner
- 3: bottom-left outer wall corner
- 4: bottom-right outer wall corner
- 5: top-left inner wall corner
- 6: top-right inner wall corner
- 7: bottom-left inner wall corner
- 8: bottom-right inner wall corner
- D: door
- I: floor tile (player start position)
- O: trapdoor (player exit position)