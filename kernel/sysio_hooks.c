/*
 * Copyright (c) 2021 Matthew Ballance
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Definitions for sys_io hook methods and
 * default implementations
 */
#include <sys/sys_io.h>

static void sys_write8_default(uint8_t data, mm_reg_t addr);
static uint8_t sys_read8_default(mm_reg_t addr);
static void sys_write16_default(uint16_t data, mm_reg_t addr);
static uint16_t sys_read16_default(mm_reg_t addr);
static void sys_write32_default(uint32_t data, mm_reg_t addr);
static uint32_t sys_read32_default(mm_reg_t addr);

static sys_write8_t *_sys_write8_hook = &sys_write8_default;
static sys_read8_t *_sys_read8_hook = &sys_read8_default;
static sys_write16_t *_sys_write16_hook = &sys_write16_default;
static sys_read16_t *_sys_read16_hook = &sys_read16_default;
static sys_write32_t *_sys_write32_hook = &sys_write32_default;
static sys_read32_t *_sys_read32_hook = &sys_read32_default;

static void sys_write8_default(uint8_t data, mm_reg_t addr) {
	*(volatile uint8_t *)addr = data;
}


void sys_write8_hook(uint8_t data, mm_reg_t addr) {
	_sys_write8_hook(data, addr);
}

static uint8_t sys_read8_default(mm_reg_t addr) {
	return *(volatile uint8_t *)addr;
}


uint8_t sys_read8_hook(mm_reg_t addr) {
	return _sys_read8_hook(addr);
}

static void sys_write16_default(uint16_t data, mm_reg_t addr) {
	*(volatile uint16_t *)addr = data;
}


void sys_write16_hook(uint16_t data, mm_reg_t addr) {
	_sys_write16_hook(data, addr);
}

static uint16_t sys_read16_default(mm_reg_t addr) {
	return *(volatile uint16_t *)addr;
}


uint16_t sys_read16_hook(mm_reg_t addr) {
	return _sys_read16_hook(addr);
}

static void sys_write32_default(uint32_t data, mm_reg_t addr) {
	*(volatile uint32_t *)addr = data;
}


void sys_write32_hook(uint32_t data, mm_reg_t addr) {
	_sys_write32_hook(data, addr);
}

static uint32_t sys_read32_default(mm_reg_t addr) {
	return *(volatile uint32_t *)addr;
}

uint32_t sys_read32_hook(mm_reg_t addr) {
	return _sys_read32_hook(addr);
}

void sys_write8_hook_install(sys_write8_t *hook) {
	_sys_write8_hook = hook;
}

void sys_read8_hook_install(sys_read8_t *hook) {
	_sys_read8_hook = hook;
}

void sys_write16_hook_install(sys_write16_t *hook) {
	_sys_write16_hook = hook;
}

void sys_read16_hook_install(sys_read16_t *hook) {
	_sys_read16_hook = hook;
}

void sys_write32_hook_install(sys_write32_t *hook) {
	_sys_write32_hook = hook;
}

void sys_read32_hook_install(sys_read32_t *hook) {
	_sys_read32_hook = hook;
}

