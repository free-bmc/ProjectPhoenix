/** 
  * @section  Get SEL Allocation Info
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  31.3
	* Restrictions:  None
  */  

 /**
   * \def IPMI20_NETCMD_GET_SEL_ALLOCATION_INFO
   * \brief The command returns the number of possible allocation units, the amount of usable free space, the allocation unit size */
  */
#define IPMI20_NETCMD_GET_SEL_ALLOCATION_INFO 				0x41

/** 
  * \typedef struct ipmi_sel_command_get_sel_allocation_info_request
  * \brief Definition of the Get SEL Allocation Info Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
typedef struct ipmi_sel_command_get_sel_allocation_info_request {

	/**< Byte 1 */ uint8_t u8Data[0]; /**< No Request data is present */

} IpmiSelCommandGetSelAllocationInfoRequest_sT, *pIpmiSelCommandGetSelAllocationInfoRequest_sT;

#define SEL_NUMBER_POSSIBLE_ALLOCATION_UNITS(x)                             (pIpmiSelCommandGetSelAllocationInfoResponse_sT)x->u16NumberPossibleAllocationUnits
#define SEL_ALLOCATION_UNIT_SIZE(x)                                         (pIpmiSelCommandGetSelAllocationInfoResponse_sT)x->u16AllocationUnitSize
#define SEL_NUMBER_FREE_ALLOCATION_UNITS(x)                                 (pIpmiSelCommandGetSelAllocationInfoResponse_sT)x->u16NumberFreeAllocationUnits
#define SEL_LARGEST_FREE_BLOCK_ALLOCATION_UNITS(x)                          (pIpmiSelCommandGetSelAllocationInfoResponse_sT)x->u16LargestFreeBlockAllocationUnits
#define SEL_MAXIMUM_RECORD_SIZE(x)                                          (pIpmiSelCommandGetSelAllocationInfoResponse_sT)x->u16MaximumRecordSize

/** 
  * \typedef struct ipmi_sel_command_get_sel_allocation_info_response
  * \brief Definition of the Get SEL Allocation Info Response
  */
typedef struct ipmi_sel_command_get_sel_allocation_info_response {

	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */	
	
	/**< Byte 2 */ uint16_t u16NumberPossibleAllocationUnits; /**< Number of possible allocation units, LS Byte first */
	
	/**< Byte 4 */ uint16_t u16AllocationUnitSize; /**< Allocation unit size in bytes, LS Byte first */
	
	/**< Byte 6 */ uint16_t u16NumberFreeAllocationUnits; /**< Number of free allocation units,  LS Byte first */
	
	/**< Byte 8 */ uint16_t u16LargestFreeBlockAllocationUnits; /**< Largest Free block allocation units, LS Byte first */
	
	/**< Byte 10 */ uint8_t u16MaximumRecordSize; /**< Maximum record size in allocation units */
    
} IpmiSelCommandGetSelAllocationInfoResponse_sT, *pIpmiSelCommandGetSelAllocationInfoResponse_sT;