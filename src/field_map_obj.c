// Includes

#include "global.h"
#include "malloc.h"
#include "sprite.h"
#include "rom4.h"
#include "data3.h"
#include "berry.h"
#include "field_player_avatar.h"
#include "event_data.h"
#include "rom_818CFC8.h"
#include "rom_81BE66C.h"
#include "field_ground_effect.h"
#include "map_obj_8097404.h"
#include "mauville_old_man.h"
#include "field_effect_helpers.h"
#include "field_map_obj.h"

#define NUM_FIELD_MAP_OBJECT_TEMPLATES 0x51

// Static struct declarations

// Static RAM declarations

// Static ROM declarations

static void sub_808D450(void);
static u8 GetFieldObjectIdByLocalId(u8);
static u8 GetFieldObjectIdByLocalIdAndMapInternal(u8, u8, u8);
static bool8 GetAvailableFieldObjectSlot(u16, u8, u8, u8 *);
static void FieldObjectHandleDynamicGraphicsId(struct MapObject *);
static void RemoveFieldObjectInternal (struct MapObject *);
/*static*/ u16 GetFieldObjectFlagIdByFieldObjectId(u8);
void sub_8096518(struct MapObject *, struct Sprite *);
static void MakeObjectTemplateFromFieldObjectTemplate(struct MapObjectTemplate *, struct SpriteTemplate *, const struct SubspriteTable **);
/*static*/ void GetFieldObjectMovingCameraOffset(s16 *, s16 *);
/*static*/ struct MapObjectTemplate *GetFieldObjectTemplateByLocalIdAndMap(u8, u8, u8);
static void sub_808E894(u16);
static void RemoveFieldObjectIfOutsideView(struct MapObject *);
static void sub_808E1B8(u8, s16, s16);
static void SetPlayerAvatarFieldObjectIdAndObjectId(u8, u8);
/*static*/ void sub_808E38C(struct MapObject *);
/*static*/ u8 sub_808E8F4(const struct SpritePalette *);
/*static*/ u16 FindFieldObjectPaletteIndexByTag(u16);

// ROM data

void (*const gUnknown_08505438[NUM_FIELD_MAP_OBJECT_TEMPLATES])(struct Sprite *);
const u8 gUnknown_0850557C[NUM_FIELD_MAP_OBJECT_TEMPLATES];
const u8 gUnknown_085055CD[NUM_FIELD_MAP_OBJECT_TEMPLATES];
const struct MapObjectGraphicsInfo *const gMauvilleOldManGraphicsInfoPointers[7];
const struct MapObjectGraphicsInfo *const gFieldObjectGraphicsInfoPointers[0xEF];

// Code

static void npc_clear_ids_and_state(struct MapObject *mapObject)
{
    *mapObject = (struct MapObject){};
    mapObject->localId = 0xFF;
    mapObject->mapNum = -1;
    mapObject->mapGroup = -1;
    mapObject->mapobj_unk_1C = -1;
}

static void npcs_clear_ids_and_state(void)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        npc_clear_ids_and_state(&gMapObjects[i]);
    }
}

void sub_808D438(void)
{
    strange_npc_table_clear();
    npcs_clear_ids_and_state();
    ClearPlayerAvatarInfo();
    sub_808D450();
}

static void sub_808D450(void)
{
    u8 spriteIdx;

    spriteIdx = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[21], 0, 0, 31);
    gSprites[spriteIdx].oam.affineMode = 1;
    InitSpriteAffineAnim(&gSprites[spriteIdx]);
    StartSpriteAffineAnim(&gSprites[spriteIdx], 0);
    gSprites[spriteIdx].invisible = TRUE;

    spriteIdx = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[21], 0, 0, 31);
    gSprites[spriteIdx].oam.affineMode = 1;
    InitSpriteAffineAnim(&gSprites[spriteIdx]);
    StartSpriteAffineAnim(&gSprites[spriteIdx], 1);
    gSprites[spriteIdx].invisible = TRUE;
}

u8 sub_808D4F4(void)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (!gMapObjects[i].active)
        {
            break;
        }
    }
    return i;
}

u8 GetFieldObjectIdByLocalIdAndMap(u8 localId, u8 mapId, u8 mapGroupId)
{
    if (localId < 0xff)
    {
        return GetFieldObjectIdByLocalIdAndMapInternal(localId, mapId, mapGroupId);
    }
    return GetFieldObjectIdByLocalId(localId);
}

bool8 TryGetFieldObjectIdByLocalIdAndMap(u8 localId, u8 mapId, u8 mapGroupId, u8 *fieldObjectId)
{
    *fieldObjectId = GetFieldObjectIdByLocalIdAndMap(localId, mapId, mapGroupId);
    if (*fieldObjectId == NUM_FIELD_OBJECTS)
    {
        return TRUE;
    }
    return FALSE;
}

u8 GetFieldObjectIdByXY(s16 x, s16 y)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (gMapObjects[i].active && gMapObjects[i].coords2.x == x && gMapObjects[i].coords2.y == y)
        {
            break;
        }
    }
    return i;
}

static u8 GetFieldObjectIdByLocalIdAndMapInternal(u8 localId, u8 mapId, u8 mapGroupId)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (gMapObjects[i].active && gMapObjects[i].localId == localId && gMapObjects[i].mapNum == mapId && gMapObjects[i].mapGroup == mapGroupId)
        {
            return i;
        }
    }
    return NUM_FIELD_OBJECTS;
}

static u8 GetFieldObjectIdByLocalId(u8 localId)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (gMapObjects[i].active && gMapObjects[i].localId == localId)
        {
            return i;
        }
    }
    return NUM_FIELD_OBJECTS;
}

// This function has the same nonmatching quirk as in Ruby/Sapphire.
#ifdef NONMATCHING
static u8 InitFieldObjectStateFromTemplate(struct MapObjectTemplate *template, u8 mapId, u8 mapGroupId)
{
    u8 slot;
    struct MapObject *mapObject;
    u16 x;
    u16 y;

    if (GetAvailableFieldObjectSlot(template->localId, mapId, mapGroupId, &slot))
    {
        return NUM_FIELD_OBJECTS;
    }
    mapObject = &gMapObjects[slot];
    npc_clear_ids_and_state(mapObject);
    x = template->x + 7;
    y = template->y + 7;
    mapObject->active = TRUE;
    mapObject->mapobj_bit_2 = TRUE;
    mapObject->graphicsId = template->graphicsId;
    mapObject->animPattern = template->movementType;
    mapObject->localId = template->localId;
    mapObject->mapNum = mapId;
    mapObject->mapGroup = mapGroupId;
    mapObject->coords1.x = x;
    mapObject->coords1.y = y;
    mapObject->coords2.x = x;
    mapObject->coords2.y = y;
    mapObject->coords3.x = x;
    mapObject->coords3.y = y;
    mapObject->mapobj_unk_0B_0 = template->elevation;
    mapObject->elevation = template->elevation;
    mapObject->mapobj_unk_19 = template->unkA_0;
    mapObject->mapobj_unk_19b = template->unkA_4;
    mapObject->trainerType = template->unkC;
    mapObject->trainerRange_berryTreeId = template->unkE;
    mapObject->mapobj_unk_20 = gUnknown_085055CD[template->movementType];
    FieldObjectSetDirection(mapObject, mapObject->mapobj_unk_20);
    FieldObjectHandleDynamicGraphicsId(mapObject);

    // This block is the culprit
    if (gUnknown_0850557C[mapObject->animPattern])
    {
        if (mapObject->mapobj_unk_19 == 0)
        {
            mapObject->mapobj_unk_19 ++;
        }
        if (mapObject->mapobj_unk_19b == 0)
        {
            mapObject->mapobj_unk_19b ++;
        }
    }
    return slot;
}
#else
static __attribute__((naked)) u8 InitFieldObjectStateFromTemplate(struct MapObjectTemplate *template, u8 mapId, u8 mapGroupId)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                "\tmov r7, r9\n"
                "\tmov r6, r8\n"
                "\tpush {r6,r7}\n"
                "\tsub sp, 0x4\n"
                "\tadds r5, r0, 0\n"
                "\tlsls r1, 24\n"
                "\tlsrs r6, r1, 24\n"
                "\tlsls r2, 24\n"
                "\tlsrs r7, r2, 24\n"
                "\tldrb r0, [r5]\n"
                "\tadds r1, r6, 0\n"
                "\tadds r2, r7, 0\n"
                "\tmov r3, sp\n"
                "\tbl GetAvailableFieldObjectSlot\n"
                "\tlsls r0, 24\n"
                "\tcmp r0, 0\n"
                "\tbeq _0808D66E\n"
                "\tmovs r0, 0x10\n"
                "\tb _0808D762\n"
                "_0808D66E:\n"
                "\tmov r0, sp\n"
                "\tldrb r1, [r0]\n"
                "\tlsls r0, r1, 3\n"
                "\tadds r0, r1\n"
                "\tlsls r0, 2\n"
                "\tldr r1, =gMapObjects\n"
                "\tadds r4, r0, r1\n"
                "\tadds r0, r4, 0\n"
                "\tbl npc_clear_ids_and_state\n"
                "\tldrh r3, [r5, 0x4]\n"
                "\tadds r3, 0x7\n"
                "\tlsls r3, 16\n"
                "\tlsrs r3, 16\n"
                "\tldrh r2, [r5, 0x6]\n"
                "\tadds r2, 0x7\n"
                "\tlsls r2, 16\n"
                "\tlsrs r2, 16\n"
                "\tldrb r0, [r4]\n"
                "\tmovs r1, 0x1\n"
                "\torrs r0, r1\n"
                "\tmovs r1, 0x4\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4]\n"
                "\tldrb r0, [r5, 0x1]\n"
                "\tstrb r0, [r4, 0x5]\n"
                "\tldrb r0, [r5, 0x9]\n"
                "\tstrb r0, [r4, 0x6]\n"
                "\tldrb r0, [r5]\n"
                "\tstrb r0, [r4, 0x8]\n"
                "\tstrb r6, [r4, 0x9]\n"
                "\tstrb r7, [r4, 0xA]\n"
                "\tstrh r3, [r4, 0xC]\n"
                "\tstrh r2, [r4, 0xE]\n"
                "\tstrh r3, [r4, 0x10]\n"
                "\tstrh r2, [r4, 0x12]\n"
                "\tstrh r3, [r4, 0x14]\n"
                "\tstrh r2, [r4, 0x16]\n"
                "\tldrb r0, [r5, 0x8]\n"
                "\tmovs r7, 0xF\n"
                "\tadds r1, r7, 0\n"
                "\tands r1, r0\n"
                "\tldrb r2, [r4, 0xB]\n"
                "\tmovs r0, 0x10\n"
                "\tnegs r0, r0\n"
                "\tmov r8, r0\n"
                "\tands r0, r2\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0xB]\n"
                "\tldrb r1, [r5, 0x8]\n"
                "\tlsls r1, 4\n"
                "\tands r0, r7\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0xB]\n"
                "\tldrb r1, [r5, 0xA]\n"
                "\tlsls r1, 28\n"
                "\tmovs r0, 0xF\n"
                "\tmov r9, r0\n"
                "\tlsrs r1, 28\n"
                "\tldrb r2, [r4, 0x19]\n"
                "\tmov r0, r8\n"
                "\tands r0, r2\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0x19]\n"
                "\tldrb r1, [r5, 0xA]\n"
                "\tlsrs r1, 4\n"
                "\tlsls r1, 4\n"
                "\tands r0, r7\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0x19]\n"
                "\tldrh r0, [r5, 0xC]\n"
                "\tstrb r0, [r4, 0x7]\n"
                "\tldrh r0, [r5, 0xE]\n"
                "\tstrb r0, [r4, 0x1D]\n"
                "\tldr r1, =gUnknown_085055CD\n"
                "\tldrb r0, [r5, 0x9]\n"
                "\tadds r0, r1\n"
                "\tldrb r1, [r0]\n"
                "\tadds r0, r4, 0\n"
                "\tadds r0, 0x20\n"
                "\tstrb r1, [r0]\n"
                "\tldrb r1, [r0]\n"
                "\tadds r0, r4, 0\n"
                "\tbl FieldObjectSetDirection\n"
                "\tadds r0, r4, 0\n"
                "\tbl FieldObjectHandleDynamicGraphicsId\n"
                "\tldr r1, =gUnknown_0850557C\n"
                "\tldrb r0, [r4, 0x6]\n"
                "\tadds r0, r1\n"
                "\tldrb r0, [r0]\n"
                "\tcmp r0, 0\n"
                "\tbeq _0808D75E\n"
                "\tldrb r2, [r4, 0x19]\n"
                "\tadds r0, r7, 0\n"
                "\tands r0, r2\n"
                "\tcmp r0, 0\n"
                "\tbne _0808D746\n"
                "\tlsls r0, r2, 28\n"
                "\tlsrs r0, 28\n"
                "\tadds r0, 0x1\n"
                "\tmov r1, r9\n"
                "\tands r0, r1\n"
                "\tmov r1, r8\n"
                "\tands r1, r2\n"
                "\torrs r1, r0\n"
                "\tstrb r1, [r4, 0x19]\n"
                "_0808D746:\n"
                "\tldrb r2, [r4, 0x19]\n"
                "\tmovs r0, 0xF0\n"
                "\tands r0, r2\n"
                "\tcmp r0, 0\n"
                "\tbne _0808D75E\n"
                "\tlsrs r1, r2, 4\n"
                "\tadds r1, 0x1\n"
                "\tlsls r1, 4\n"
                "\tadds r0, r7, 0\n"
                "\tands r0, r2\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4, 0x19]\n"
                "_0808D75E:\n"
                "\tmov r0, sp\n"
                "\tldrb r0, [r0]\n"
                "_0808D762:\n"
                "\tadd sp, 0x4\n"
                "\tpop {r3,r4}\n"
                "\tmov r8, r3\n"
                "\tmov r9, r4\n"
                "\tpop {r4-r7}\n"
                "\tpop {r1}\n"
                "\tbx r1\n"
                ".pool");
}
#endif

u8 unref_sub_808D77C(u8 localId)
{
    u8 i;
    u8 nObjects;
    struct MapObjectTemplate *template;

    if (gMapHeader.events != NULL)
    {
        if (InBattlePyramid())
        {
            nObjects = sub_81AAA40();
        }
        else if (InTrainerHill())
        {
            nObjects = 2;
        }
        else
        {
            nObjects = gMapHeader.events->mapObjectCount;
        }
        for (i = 0; i < nObjects; i ++)
        {
            template = &gSaveBlock1Ptr->mapObjectTemplates[i];
            if (template->localId == localId && !FlagGet(template->flagId))
            {
                return InitFieldObjectStateFromTemplate(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            }
        }
    }
    return NUM_FIELD_OBJECTS;
}

static bool8 GetAvailableFieldObjectSlot(u16 localId, u8 mapNum, u8 mapGroup, u8 *result)
// Looks for an empty slot.
// Returns FALSE and the location of the available slot
// in *result.
// If no slots are available, or if the object is already
// loaded, returns TRUE.
{
    u8 i = 0;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (!gMapObjects[i].active)
            break;
        if (gMapObjects[i].localId == localId && gMapObjects[i].mapNum == mapNum && gMapObjects[i].mapGroup == mapGroup)
            return TRUE;
    }
    if (i >= NUM_FIELD_OBJECTS)
        return TRUE;
    *result = i;
    do
    {
        if (gMapObjects[i].active && gMapObjects[i].localId == localId && gMapObjects[i].mapNum == mapNum && gMapObjects[i].mapGroup == mapGroup)
            return TRUE;
        i ++;
    } while (i < NUM_FIELD_OBJECTS);
    return FALSE;
}

static void RemoveFieldObject(struct MapObject *mapObject)
{
    mapObject->active = FALSE;
    RemoveFieldObjectInternal(mapObject);
}

void RemoveFieldObjectByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 index;
    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &index))
    {
        FlagSet(GetFieldObjectFlagIdByFieldObjectId(index));
        RemoveFieldObject(&gMapObjects[index]);
    }
}

static void RemoveFieldObjectInternal(struct MapObject *mapObject)
{
    struct SpriteFrameImage image;
    image.size = GetFieldObjectGraphicsInfo(mapObject->graphicsId)->size;
    gSprites[mapObject->spriteId].images = &image;
    DestroySprite(&gSprites[mapObject->spriteId]);
}

void unref_sub_808D958(void)
{
    u8 i;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (i != gPlayerAvatar.mapObjectId)
        {
            RemoveFieldObject(&gMapObjects[i]);
        }
    }
}

static u8 SpawnFieldObjectInternal(struct MapObjectTemplate *mapObjectTemplate, struct SpriteTemplate *spriteTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    struct MapObject *mapObject;
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 mapObjectId;
    u8 paletteSlot;
    u8 spriteId;

    mapObjectId = InitFieldObjectStateFromTemplate(mapObjectTemplate, mapNum, mapGroup);
    if (mapObjectId == NUM_FIELD_OBJECTS)
    {
        return NUM_FIELD_OBJECTS;
    }
    mapObject = &gMapObjects[mapObjectId];
    graphicsInfo = GetFieldObjectGraphicsInfo(mapObject->graphicsId);
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == 0)
    {
        npc_load_two_palettes__no_record(graphicsInfo->paletteTag1, 0);
    }
    else if (paletteSlot == 10)
    {
        npc_load_two_palettes__and_record(graphicsInfo->paletteTag1, 10);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        sub_808EAB0(graphicsInfo->paletteTag1, paletteSlot);
    }
    if (mapObject->animPattern == 0x4c)
    {
        mapObject->mapobj_bit_13 = TRUE;
    }
    *(u16 *)&spriteTemplate->paletteTag = 0xFFFF;
    spriteId = CreateSprite(spriteTemplate, 0, 0, 0);
    if (spriteId == MAX_SPRITES)
    {
        gMapObjects[mapObjectId].active = FALSE;
        return NUM_FIELD_OBJECTS;
    }
    sprite = &gSprites[spriteId];
    sub_8092FF0(mapObject->coords2.x + cameraX, mapObject->coords2.y + cameraY, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sprite->oam.paletteNum = paletteSlot;
    sprite->coordOffsetEnabled = TRUE;
    sprite->data0 = mapObjectId;
    mapObject->spriteId = spriteId;
    mapObject->mapobj_bit_12 = graphicsInfo->inanimate;
    if (!mapObject->mapobj_bit_12)
    {
        StartSpriteAnim(sprite, FieldObjectDirectionToImageAnimId(mapObject->mapobj_unk_18));
    }
    SetObjectSubpriorityByZCoord(mapObject->elevation, sprite, 1);
    sub_8096518(mapObject, sprite);
    return mapObjectId;
}

static u8 SpawnFieldObject(struct MapObjectTemplate *mapObjectTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct SpriteTemplate spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    struct SpriteFrameImage spriteFrameImage;
    u8 mapObjectId;

    subspriteTables = NULL;
    graphicsInfo = GetFieldObjectGraphicsInfo(mapObjectTemplate->graphicsId);
    MakeObjectTemplateFromFieldObjectTemplate(mapObjectTemplate, &spriteTemplate, &subspriteTables);
    spriteFrameImage.size = graphicsInfo->size;
    spriteTemplate.images = &spriteFrameImage;
    mapObjectId = SpawnFieldObjectInternal(mapObjectTemplate, &spriteTemplate, mapNum, mapGroup, cameraX, cameraY);
    if (mapObjectId == NUM_FIELD_OBJECTS)
    {
        return NUM_FIELD_OBJECTS;
    }
    gSprites[gMapObjects[mapObjectId].spriteId].images = graphicsInfo->images;
    if (subspriteTables != NULL)
    {
        SetSubspriteTables(&gSprites[gMapObjects[mapObjectId].spriteId], subspriteTables);
    }
    return mapObjectId;
}

u8 SpawnSpecialFieldObject(struct MapObjectTemplate *mapObjectTemplate)
{
    s16 cameraX;
    s16 cameraY;

    GetFieldObjectMovingCameraOffset(&cameraX, &cameraY);
    return SpawnFieldObject(mapObjectTemplate, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
}

u8 SpawnSpecialFieldObjectParametrized(u8 graphicsId, u8 movementBehavior, u8 localId, s16 x, s16 y, u8 z)
{
    struct MapObjectTemplate mapObjectTemplate;

    x -= 7;
    y -= 7;
    mapObjectTemplate.localId = localId;
    mapObjectTemplate.graphicsId = graphicsId;
    mapObjectTemplate.unk2 = 0;
    mapObjectTemplate.x = x;
    mapObjectTemplate.y = y;
    mapObjectTemplate.elevation = z;
    mapObjectTemplate.movementType = movementBehavior;
    mapObjectTemplate.unkA_0 = 0;
    mapObjectTemplate.unkA_4 = 0;
    mapObjectTemplate.unkC = 0;
    mapObjectTemplate.unkE = 0;
    return SpawnSpecialFieldObject(&mapObjectTemplate);
}

u8 show_sprite(u8 localId, u8 mapNum, u8 mapGroup)
{
    struct MapObjectTemplate *mapObjectTemplate;
    s16 cameraX;
    s16 cameraY;

    mapObjectTemplate = GetFieldObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup);
    if (mapObjectTemplate == NULL)
    {
        return NUM_FIELD_OBJECTS;
    }
    GetFieldObjectMovingCameraOffset(&cameraX, &cameraY);
    return SpawnFieldObject(mapObjectTemplate, mapNum, mapGroup, cameraX, cameraY);
}

static void MakeObjectTemplateFromFieldObjectGraphicsInfo(u16 graphicsId, void (*callback)(struct Sprite *), struct SpriteTemplate *sprTemplate, const struct SubspriteTable **subspriteTables)
{
    const struct MapObjectGraphicsInfo *gfxInfo = GetFieldObjectGraphicsInfo(graphicsId);

    sprTemplate->tileTag = gfxInfo->tileTag;
    sprTemplate->paletteTag = gfxInfo->paletteTag1;
    sprTemplate->oam = gfxInfo->oam;
    sprTemplate->anims = gfxInfo->anims;
    sprTemplate->images = gfxInfo->images;
    sprTemplate->affineAnims = gfxInfo->affineAnims;
    sprTemplate->callback = callback;
    *subspriteTables = gfxInfo->subspriteTables;
}

static void MakeObjectTemplateFromFieldObjectGraphicsInfoWithCallbackIndex(u16 graphicsId, u16 callbackIndex, struct SpriteTemplate *sprTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromFieldObjectGraphicsInfo(graphicsId, gUnknown_08505438[callbackIndex], sprTemplate, subspriteTables);
}

static void MakeObjectTemplateFromFieldObjectTemplate(struct MapObjectTemplate *mapObjectTemplate, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromFieldObjectGraphicsInfoWithCallbackIndex(mapObjectTemplate->graphicsId, mapObjectTemplate->movementType, spriteTemplate, subspriteTables);
}

u8 AddPseudoFieldObject(u16 graphicsId, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    struct SpriteTemplate *spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    struct Sprite *sprite;
    u8 spriteIdx;

    spriteTemplate = malloc(sizeof(struct SpriteTemplate));
    MakeObjectTemplateFromFieldObjectGraphicsInfo(graphicsId, callback, spriteTemplate, &subspriteTables);
    if (spriteTemplate->paletteTag != 0xffff)
    {
        sub_808E894(spriteTemplate->paletteTag);
    }
    spriteIdx = CreateSprite(spriteTemplate, x, y, subpriority);
    free(spriteTemplate);

    if (spriteIdx != MAX_SPRITES && subspriteTables != NULL)
    {
        sprite = &gSprites[spriteIdx];
        SetSubspriteTables(sprite, subspriteTables);
        sprite->subspriteMode = 2;
    }
    return spriteIdx;
}

u8 sprite_new(u8 graphicsId, u8 a1, s16 x, s16 y, u8 z, u8 direction)
{
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct SpriteTemplate spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    u8 spriteId;
    struct Sprite *sprite;

    graphicsInfo = GetFieldObjectGraphicsInfo(graphicsId);
    MakeObjectTemplateFromFieldObjectGraphicsInfo(graphicsId, sub_8097AC8, &spriteTemplate, &subspriteTables);
    *(u16 *)&spriteTemplate.paletteTag = 0xffff;
    x += 7;
    y += 7;
    sub_80930E0(&x, &y, 8, 16);
    spriteId = CreateSpriteAtEnd(&spriteTemplate, x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->pos1.y += sprite->centerToCornerVecY;
        sprite->oam.paletteNum = graphicsInfo->paletteSlot;
        if (sprite->oam.paletteNum >= 16)
        {
            sprite->oam.paletteNum -= 16;
        }
        sprite->coordOffsetEnabled = TRUE;
        sprite->data0 = a1;
        sprite->data1 = z;
        if (graphicsInfo->paletteSlot == 10)
        {
            npc_load_two_palettes__and_record(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
        }
        else if (graphicsInfo->paletteSlot >= 16)
        {
            sub_808EAB0(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot | 0xf0);
        }
        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
            sprite->subspriteMode = 2;
        }
        InitObjectPriorityByZCoord(sprite, z);
        SetObjectSubpriorityByZCoord(z, sprite, 1);
        StartSpriteAnim(sprite, FieldObjectDirectionToImageAnimId(direction));
    }
    return spriteId;
}

void SpawnFieldObjectsInView(s16 cameraX, s16 cameraY)
{
    u8 i;
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;
    u8 objectCount;
    s16 npcX;
    s16 npcY;

    if (gMapHeader.events != NULL)
    {
        left = gSaveBlock1Ptr->pos.x - 2;
        right = gSaveBlock1Ptr->pos.x + 17;
        top = gSaveBlock1Ptr->pos.y;
        bottom = gSaveBlock1Ptr->pos.y + 16;

        if (InBattlePyramid())
        {
            objectCount = sub_81AAA40();
        }
        else if (InTrainerHill())
        {
            objectCount = 2;
        }
        else
        {
            objectCount = gMapHeader.events->mapObjectCount;
        }

        for (i = 0; i < objectCount; i++)
        {
            struct MapObjectTemplate *template = &gSaveBlock1Ptr->mapObjectTemplates[i];
            npcX = template->x + 7;
            npcY = template->y + 7;

            if (top <= npcY && bottom >= npcY && left <= npcX && right >= npcX
                && !FlagGet(template->flagId))
                SpawnFieldObject(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
        }
    }
}

/*static*/ void RemoveFieldObjectsOutsideView(void)
{
    u8 i;
    u8 j;
    bool8 isActiveLinkPlayer;
    struct MapObject *mapObject;

    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        for (j = 0, isActiveLinkPlayer = FALSE; j < ARRAY_COUNT(gLinkPlayerMapObjects); j ++)
        {
            if (gLinkPlayerMapObjects[j].active && i == gLinkPlayerMapObjects[j].mapObjId)
                isActiveLinkPlayer = TRUE;
        }
        if (!isActiveLinkPlayer)
        {
            mapObject = &gMapObjects[i];

            if (mapObject->active && !mapObject->mapobj_bit_16)
                RemoveFieldObjectIfOutsideView(mapObject);
        }
    }
}

static void RemoveFieldObjectIfOutsideView(struct MapObject *mapObject)
{
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    left = gSaveBlock1Ptr->pos.x - 2;
    right = gSaveBlock1Ptr->pos.x + 17;
    top = gSaveBlock1Ptr->pos.y;
    bottom = gSaveBlock1Ptr->pos.y + 16;

    if (mapObject->coords2.x >= left && mapObject->coords2.x <= right
        && mapObject->coords2.y >= top && mapObject->coords2.y <= bottom)
        return;
    if (mapObject->coords1.x >= left && mapObject->coords1.x <= right
        && mapObject->coords1.y >= top && mapObject->coords1.y <= bottom)
        return;
    RemoveFieldObject(mapObject);
}

void sub_808E16C(s16 x, s16 y)
{
    u8 i;

    ClearPlayerAvatarInfo();
    for (i = 0; i < NUM_FIELD_OBJECTS; i ++)
    {
        if (gMapObjects[i].active)
        {
            sub_808E1B8(i, x, y);
        }
    }
    sub_808D450();
}

static void sub_808E1B8(u8 mapObjectId, s16 x, s16 y)
{
    u8 spriteId;
    u8 paletteSlot;
    struct MapObject *mapObject;
    const struct SubspriteTable *subspriteTables;
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct SpriteFrameImage spriteFrameImage;
    struct SpriteTemplate spriteTemplate;
    struct Sprite *sprite;

#define i spriteId
    for (i = 0; i < ARRAY_COUNT(gLinkPlayerMapObjects); i ++)
    {
        if (gLinkPlayerMapObjects[i].active && mapObjectId == gLinkPlayerMapObjects[i].mapObjId)
        {
            return;
        }
    }
#undef i

    mapObject = &gMapObjects[mapObjectId];
    subspriteTables = NULL;
    graphicsInfo = GetFieldObjectGraphicsInfo(mapObject->graphicsId);
    spriteFrameImage.size = graphicsInfo->size;
    MakeObjectTemplateFromFieldObjectGraphicsInfoWithCallbackIndex(mapObject->graphicsId, mapObject->animPattern, &spriteTemplate, &subspriteTables);
    spriteTemplate.images = &spriteFrameImage;
    *(u16 *)&spriteTemplate.paletteTag = 0xffff;
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == 0)
    {
        npc_load_two_palettes__no_record(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot == 10)
    {
        npc_load_two_palettes__and_record(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        sub_808EAB0(graphicsInfo->paletteTag1, paletteSlot);
    }
    *(u16 *)&spriteTemplate.paletteTag = 0xffff;
    spriteId = CreateSprite(&spriteTemplate, 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sub_8092FF0(x + mapObject->coords2.x, y + mapObject->coords2.y, &sprite->pos1.x, &sprite->pos1.y);
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->pos1.x += 8;
        sprite->pos1.y += 16 + sprite->centerToCornerVecY;
        sprite->images = graphicsInfo->images;
        if (mapObject->animPattern == 0x0b)
        {
            SetPlayerAvatarFieldObjectIdAndObjectId(mapObjectId, spriteId);
            mapObject->mapobj_unk_1B = sub_8154228();
        }
        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
        }
        sprite->oam.paletteNum = paletteSlot;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data0 = mapObjectId;
        mapObject->spriteId = spriteId;
        if (!mapObject->mapobj_bit_12 && mapObject->animPattern != 0x0b)
        {
            StartSpriteAnim(sprite, FieldObjectDirectionToImageAnimId(mapObject->mapobj_unk_18));
        }
        sub_808E38C(mapObject);
        SetObjectSubpriorityByZCoord(mapObject->elevation, sprite, 1);
    }
}

/*static*/ void sub_808E38C(struct MapObject *mapObject)
{
    mapObject->mapobj_bit_1 = FALSE;
    mapObject->mapobj_bit_2 = TRUE;
    mapObject->mapobj_bit_22 = FALSE;
    mapObject->mapobj_bit_17 = FALSE;
    mapObject->mapobj_bit_18 = FALSE;
    mapObject->mapobj_bit_19 = FALSE;
    mapObject->mapobj_bit_20 = FALSE;
    mapObject->mapobj_bit_21 = FALSE;
    FieldObjectClearAnim(mapObject);
}

static void SetPlayerAvatarFieldObjectIdAndObjectId(u8 mapObjectId, u8 spriteId)
{
    gPlayerAvatar.mapObjectId = mapObjectId;
    gPlayerAvatar.spriteId = spriteId;
    gPlayerAvatar.gender = GetPlayerAvatarGenderByGraphicsId(gMapObjects[mapObjectId].graphicsId);
    SetPlayerAvatarExtraStateTransition(gMapObjects[mapObjectId].graphicsId, 0x20);
}

void FieldObjectSetGraphicsId(struct MapObject *mapObject, u8 graphicsId)
{
    const struct MapObjectGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 paletteSlot;

    graphicsInfo = GetFieldObjectGraphicsInfo(graphicsId);
    sprite = &gSprites[mapObject->spriteId];
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == 0)
    {
        pal_patch_for_npc(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot == 10)
    {
        npc_load_two_palettes__and_record(graphicsInfo->paletteTag1, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        sub_808EAB0(graphicsInfo->paletteTag1, paletteSlot);
    }
    sprite->oam.shape = graphicsInfo->oam->shape;
    sprite->oam.size = graphicsInfo->oam->size;
    sprite->images = graphicsInfo->images;
    sprite->anims = graphicsInfo->anims;
    sprite->subspriteTables = graphicsInfo->subspriteTables;
    sprite->oam.paletteNum = paletteSlot;
    mapObject->mapobj_bit_12 = graphicsInfo->inanimate;
    mapObject->graphicsId = graphicsId;
    sub_8093038(mapObject->coords2.x, mapObject->coords2.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    if (mapObject->mapobj_bit_15)
    {
        CameraObjectReset1();
    }
}

void FieldObjectSetGraphicsIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 graphicsId)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        FieldObjectSetGraphicsId(&gMapObjects[mapObjectId], graphicsId);
    }
}

void FieldObjectTurn(struct MapObject *mapObject, u8 direction)
{
    FieldObjectSetDirection(mapObject, direction);
    if (!mapObject->mapobj_bit_12)
    {
        StartSpriteAnim(&gSprites[mapObject->spriteId], FieldObjectDirectionToImageAnimId(mapObject->mapobj_unk_18));
        SeekSpriteAnim(&gSprites[mapObject->spriteId], 0);
    }
}

void FieldObjectTurnByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 direction)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        FieldObjectTurn(&gMapObjects[mapObjectId], direction);
    }
}

void PlayerObjectTurn(struct PlayerAvatar *playerAvatar, u8 direction)
{
    FieldObjectTurn(&gMapObjects[playerAvatar->mapObjectId], direction);
}

/*static*/ void get_berry_tree_graphics(struct MapObject *mapObject, struct Sprite *sprite)
{
    u8 berryStage;
    u8 berryId;

    mapObject->mapobj_bit_13 = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(mapObject->trainerRange_berryTreeId);
    if (berryStage != 0)
    {
        mapObject->mapobj_bit_13 = FALSE;
        sprite->invisible = FALSE;
        berryId = GetBerryTypeByBerryTreeId(mapObject->trainerRange_berryTreeId) - 1;
        berryStage -= 1;
        if (berryId >= NUM_BERRIES)
        {
            berryId = 0;
        }
        FieldObjectSetGraphicsId(mapObject, gBerryTreeFieldObjectGraphicsIdTablePointers[berryId][berryStage]);
        sprite->images = gBerryTreePicTablePointers[berryId];
        sprite->oam.paletteNum = gBerryTreePaletteSlotTablePointers[berryId][berryStage];
        StartSpriteAnim(sprite, berryStage);
    }
}

const struct MapObjectGraphicsInfo *GetFieldObjectGraphicsInfo(u8 graphicsId)
{
    u8 bard;

    if (graphicsId >= SPRITE_VAR)
    {
        graphicsId = VarGetFieldObjectGraphicsId(graphicsId - SPRITE_VAR);
    }
    if (graphicsId == 0x45)
    {
        bard = sub_81201C8();
        return gMauvilleOldManGraphicsInfoPointers[bard];
    }
    if (graphicsId >= NUM_OBJECT_GRAPHICS_INFO)
    {
        graphicsId = 0x05; // LittleBoy1
    }
    return gFieldObjectGraphicsInfoPointers[graphicsId];
}

static void FieldObjectHandleDynamicGraphicsId(struct MapObject *mapObject)
{
    if (mapObject->graphicsId >= SPRITE_VAR)
    {
        mapObject->graphicsId = VarGetFieldObjectGraphicsId(mapObject->graphicsId - SPRITE_VAR);
    }
}

void npc_by_local_id_and_map_set_field_1_bit_x20(u8 localId, u8 mapNum, u8 mapGroup, u8 state)
{
    u8 mapObjectId;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        gMapObjects[mapObjectId].mapobj_bit_13 = state;
    }
}

void FieldObjectGetLocalIdAndMap(struct MapObject *mapObject, u8 *localId, u8 *mapNum, u8 *mapGroup)
{
    *localId = mapObject->localId;
    *mapNum = mapObject->mapNum;
    *mapGroup = mapObject->mapGroup;
}

void sub_808E75C(s16 x, s16 y)
{
    u8 mapObjectId;
    struct MapObject *mapObject;

    mapObjectId = GetFieldObjectIdByXY(x, y);
    if (mapObjectId != NUM_FIELD_OBJECTS)
    {
        mapObject = &gMapObjects[mapObjectId];
        mapObject->mapobj_bit_2 = TRUE;
    }
}

void sub_808E78C(u8 localId, u8 mapNum, u8 mapGroup, u8 subpriority)
{
    u8 mapObjectId;
    struct MapObject *mapObject;
    struct Sprite *sprite;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        mapObject = &gMapObjects[mapObjectId];
        sprite = &gSprites[mapObject->spriteId];
        mapObject->mapobj_bit_26 = TRUE;
        sprite->subpriority = subpriority;
    }
}

void sub_808E7E4(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 mapObjectId;
    struct MapObject *mapObject;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        mapObject = &gMapObjects[mapObjectId];
        mapObject->mapobj_bit_26 = FALSE;
        mapObject->mapobj_bit_2 = TRUE;
    }
}

void sub_808E82C(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 mapObjectId;
    struct Sprite *sprite;

    if (!TryGetFieldObjectIdByLocalIdAndMap(localId, mapNum, mapGroup, &mapObjectId))
    {
        sprite = &gSprites[gMapObjects[mapObjectId].spriteId];
        sprite->pos2.x = x;
        sprite->pos2.y = y;
    }
}

void gpu_pal_allocator_reset__manage_upper_four(void)
{
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 12;
}

static void sub_808E894(u16 paletteTag)
{
    u16 paletteSlot;

    paletteSlot = (u8)FindFieldObjectPaletteIndexByTag(paletteTag);
    if (paletteSlot != 0x11ff) // always true
    {
        sub_808E8F4(&gUnknown_0850BBC8[paletteSlot]);
    }
}

void sub_808E8C0(u16 *paletteTags)
{
    u8 i;

    for (i = 0; paletteTags[i] != 0x11ff; i ++)
    {
        sub_808E894(paletteTags[i]);
    }
}

u8 sub_808E8F4(const struct SpritePalette *spritePalette)
{
    if (IndexOfSpritePaletteTag(spritePalette->tag) != 0xff)
    {
        return 0xff;
    }
    return LoadSpritePalette(spritePalette);
}
