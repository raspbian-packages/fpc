    _start:
        clr r1

        // load stack pointer
        ldi r30,lo8(_stack_top)
        out 0x3d,r30
        ldi r30,hi8(_stack_top)
        out 0x3e,r30
        
        // Initialize .data section
        ldi XL,lo8(_data)
        ldi XH,hi8(_data)
        ldi YH,hi8(_edata)
        ldi ZL,lo8(_etext)
        ldi ZH,hi8(_etext)
.LCopyDataLoop:
        lpm r0, Z+
        st X+, r0
        
        cpi XL, lo8(_edata)
        cpc XH, YH
        brne .LCopyDataLoop
        
        // Zero .bss section
        ldi XL,lo8(_bss_start)
        ldi XH,hi8(_bss_start)
        ldi YH,hi8(_bss_end)
.LZeroBssLoop:
        st X+, r1
        
        cpi XL, lo8(_bss_end)
        cpc XH, YH
        brne .LZeroBssLoop

        call PASCALMAIN
        call _FPC_haltproc
        .text

