
/* 
 * Byte 3 - BMCFW Entity Type 
 * Byte 2 - BMCFW Component Type
 * Byte 1 - BMCFW Sub Component Type
 * Byte 0 - BMCFW Instance ID
 */
typedef uint32_t BMCFW_COMPONENT_ID;

#define BMCFW_ENTITY_TYPE_FW            0x01000000
#define BMCFW_ENTITY_TYPE_CHIP          0x02000000
#define BMCFW_ENTITY_TYPE_PLATFORM      0x03000000


    